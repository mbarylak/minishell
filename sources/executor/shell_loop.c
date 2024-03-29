/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:39 by mbarylak          #+#    #+#             */
/*   Updated: 2023/04/24 17:51:49 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	in_order(t_tree *tree)
{
	if (tree != NULL)
	{
		if (tree->n_type != N_PIPE)
			redir(tree);
		in_order(tree->left);
		in_order(tree->right);
	}
}

void	shell_loop(void)
{
	in_order(g_shell->tree);
}
