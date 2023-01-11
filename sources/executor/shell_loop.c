/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:39 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/11 17:23:46 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_order(t_tree *tree)
{
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
		{
			printf("Cmd en pos: %d\n", tree->cmd_pos);
			print_env(tree->content);
			printf("\n");
		}
		in_order(tree->left);
		in_order(tree->right);
	}
}

void	shell_loop()
{
	in_order(g_shell->tree);
}
