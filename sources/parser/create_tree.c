/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:47:01 by mbarylak          #+#    #+#             */
/*   Updated: 2023/02/09 21:55:49 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_node_right(t_tree *tree, char **arg, int pos, t_redir **redir_list)
{
	if (tree->right)
		add_node_right(tree->right, arg, pos, redir_list);
	else
		tree->right = create_node(arg, pos, N_PIPE, redir_list);
}

void	add_node_left(t_tree *tree, char **arg, int pos, t_redir **redir_list)
{
	if (tree->left)
		add_node_left(tree->left, arg, pos, redir_list);
	else
		tree->left = create_node(arg, pos, N_OTHER, redir_list);
}

t_tree	*create_node(char **arg, int pos, int n_type, t_redir **redir_list)
{
	t_tree	*node;

	node = malloc(sizeof (t_tree));
	if (!node)
		return (NULL);
	node->content = arg;
	node->cmd_pos = pos;
	node->n_type = n_type;
	node->l_redir = redir_list;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_tree	*create_tree(void)
{
	t_tree	*tree;
	int		i;
	int		pos;
	int		first;

	i = -1;
	first = 0;
	tree = create_node(NULL, 0, N_PIPE, NULL);
	pos = P_FIRST;
	while (++i < (g_shell->nb_args + g_shell->pipes))
	{
		if (g_shell->tokens[i].type == T_PIPE)
		{
			add_node_left(tree, join_cmd(first, i), pos, \
					get_redir_list(first, i));
			add_node_right(tree, NULL, 0, NULL);
			first = i;
			pos = P_MIDDLE;
		}
	}
	pos = P_LAST;
	add_node_left(tree, join_cmd(first, i), pos, get_redir_list(first, i));
	return (tree);
}
