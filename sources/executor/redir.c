/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:46:58 by mbarylak          #+#    #+#             */
/*   Updated: 2023/02/16 20:35:49 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(int type, char *data)
{
	if (type == T_REDIR_OUT)
		printf("minishell: syntax error near unexpected token `>'\n");
	else if (type == T_REDIR_IN)
		printf("minishell: syntax error near unexpected token `<'\n");
	else if (type == T_APPEND_OUT)
		printf("minishell: syntax error near unexpected token `>>'\n");
	else if (type == T_HEREDOC)
		printf("minishell: syntax error near unexpected token `<<'\n");
	else if (type == T_PIPE)
		printf("minishell: syntax error near unexpected token `|'\n");
	else if (type > T_HEREDOC || type == 0)
		printf("minishell: syntax error near unexpected token `newline'\n");
	else if (type == -1)
		printf("minishell: *: ambiguous redirect\n");
	else if (type == -2)
		printf("minishell: %s: Is a directory\n", data);
}

int	check_redir_list(t_redir *redir)
{
	t_redir	*aux;

	aux = redir;
	while (aux)
	{
		if (!aux->value)
		{
			print_error(aux->r_type, NULL);
			return (1);
		}
		else if (ft_strcmp(aux->value, "*") == 0)
		{
			print_error(-1, NULL);
			return (1);
		}
		/*else if (is_directory(aux->value))
		{
			print_error(-2, aux->value);
			return (1);
		}*/
		aux = aux->next;
	}
	return (0);
}

int	*open_redir_list(t_redir *redir)
{
	int		*fd;
	t_redir	*aux;

	if (check_redir_list(redir))
		return (NULL);
	aux = redir;
	fd = malloc(2 * sizeof (int));
	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	while (aux)
	{
		if (redir->r_type == T_REDIR_OUT)
			fd[1] = open(redir->value, O_RDWR | O_CREAT | O_TRUNC, 00644);
		else if (redir->r_type == T_REDIR_IN)
			fd[0] = open(redir->value, O_RDONLY);
		else if (redir->r_type == T_APPEND_OUT)
			fd[1] = open(redir->value, O_APPEND | O_RDWR | O_CREAT, 00644);
		//else if (redir->r_type == T_HEREDOC)
		aux = aux->next;
	}
	return (fd);
}

void	print_redir_list(t_redir *redir)
{
	if (!redir)
		return ;
	while (redir)
	{
		printf("La redir tipo %d es hacia %s\n", redir->r_type, redir->value);
		redir = redir->next;
	}
}

void	redir(t_tree *tree)
{
	int		*fd;
	int		std_fd[2];

	fd = NULL;
	if (tree->l_redir && *(tree->l_redir))
	{
		print_redir_list(*tree->l_redir);
		std_fd[0] = dup(0);
		std_fd[1] = dup(1);
		fd = open_redir_list(*tree->l_redir);
		if (fd == NULL)
			return ;
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		exec_single_child(tree->content);
		dup2(std_fd[0], STDIN_FILENO);
		dup2(std_fd[1], STDOUT_FILENO);
		close(std_fd[0]);
		close(std_fd[1]);
		close(fd[1]);
	}
	else
		exec_single_child(tree->content);
}
