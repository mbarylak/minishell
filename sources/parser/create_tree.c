/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:47:01 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/28 18:26:23 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*create_node(char *line)
{
	t_tree	*node;

	node = malloc(sizeof (t_tree));
	if (!node)
		return (NULL);
	node->content = ft_strdup(line);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_tree	*create_tree(char *line)
{
	char	**tokens;
	int		tok_num;
	int		i;
	t_tree	*root;
	t_tree	*current;

	tok_num = 0;
	tokens = ft_split(line, ' ');
	root = create_node(tokens[0]);
	current = root;
	while (tokens[tok_num])
		tok_num++;
	i = 0;
	while (i < tok_num)
	{
		if (ft_strcmp(tokens[i], "|") != 0)
		{
			current->right = create_node(tokens[i]);
			current = current->right;
		}
		else
		{
			current->left = create_node(tokens[i]);
			current = current->left;
		}
		i++;
	}
	return (root);
}
