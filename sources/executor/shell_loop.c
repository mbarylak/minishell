/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:39 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/11 19:09:42 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_order(t_tree *tree)
{
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
		{
			if (g_shell->pipes == 0)
				exec_single_child(tree->content);
			else
				exe_pipes(tree);
		}
		in_order(tree->left);
		in_order(tree->right);
	}
}

void	shell_loop()
{
	in_order(g_shell->tree);
}
