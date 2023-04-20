/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:46:58 by mbarylak          #+#    #+#             */
/*   Updated: 2023/04/20 21:27:35 by mbarylak         ###   ########.fr       */
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
	if (!aux)
		return (1);
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

void	open_redir_list(t_redir *redir)
{
	if (redir->r_type == T_REDIR_OUT)
		g_shell->fd[1] = open(redir->value, O_RDWR | O_CREAT | O_TRUNC, 00644);
	else if (redir->r_type == T_REDIR_IN)
		g_shell->fd[0] = open(redir->value, O_RDONLY);
	else if (redir->r_type == T_APPEND_OUT)
		g_shell->fd[1] = open(redir->value, O_APPEND | O_RDWR | O_CREAT, 00644);
	//else if (redir->r_type == T_HEREDOC)
}

void	close_redir(int fd0, int fd1)
{
	close(fd0);
	close(fd1);
	if (g_shell->fd[0] != 0)
	{
		close(g_shell->fd[0]);
		g_shell->fd[0] = 0;
	}
	if (g_shell->fd[1] != 1)
	{
		close(g_shell->fd[1]);
		g_shell->fd[1] = 1;
	}
}

void	redir(t_tree *tree)
{
	t_redir	*aux;
	int		std_fd[2];

	aux = *tree->l_redir;
	if (!check_redir_list(aux))
	{
		std_fd[0] = dup(0);
		std_fd[1] = dup(1);
		while (aux)
		{
			open_redir_list(aux);
			aux = aux->next;
		}
		dup2(g_shell->fd[0], STDIN_FILENO);
		dup2(g_shell->fd[1], STDOUT_FILENO);
		exec_single_child(tree->content);
		dup2(std_fd[0], STDIN_FILENO);
		dup2(std_fd[1], STDOUT_FILENO);
		close_redir(std_fd[0], std_fd[1]);
	}
	else
		exec_single_child(tree->content);
}
