/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:47:01 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/11 17:23:48 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_node_right(t_tree *tree, char **arg, int pos)
{
	if (tree->right)
		add_node_right(tree->right, arg, pos);
	else
		tree->right = create_node(arg, pos, N_PIPE);
}

void	add_node_left(t_tree *tree, char **arg, int pos)
{
	if (tree->left)
		add_node_left(tree->left, arg, pos);
	else
		tree->left = create_node(arg, pos, N_OTHER);
}

t_tree	*create_node(char **arg, int pos, int n_type)
{
	t_tree	*node;

	node = malloc(sizeof (t_tree));
	if (!node)
		return (NULL);
	node->content = arg;
	node->cmd_pos = pos;
	node->n_type = n_type;
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
	first = i;
	tree = create_node(NULL, 0, N_PIPE);
	pos = P_FIRST;
	i = -1;
	while (++i < (g_shell->nb_args + g_shell->pipes))
	{
		if (g_shell->tokens[i].type == T_PIPE)
		{
			add_node_left(tree, join_cmd(first, i), pos);
			add_node_right(tree, NULL, 0);
			first = i;
			pos = P_MIDDLE;
		}
	}
	pos = P_LAST;
	add_node_left(tree, join_cmd(first, i), pos);
	return (tree);
}
