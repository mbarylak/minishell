/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:23:47 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/26 17:59:06 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(void)
{
	dprintf(2, "Error\n");
}

t_redir	*redir_last(t_redir *redir)
{
	if (!redir)
		return (NULL);
	if (redir->next)
	{
		while (redir->next)
			redir = redir->next;
	}
	return (redir);
}

t_redir	*create_redir_node(int type, char *value)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	new->r_type = type;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_redir_node(t_redir **redir_l, t_redir *new)
{
	if (!redir_l)
		return ;
	if (*redir_l == NULL)
		*redir_l = new;
	else
		redir_last(*redir_l)->next = new;
}

t_redir	**get_redir_list(int fst, int lst)
{
	t_token	*toks;
	t_redir	**r_list;

	toks = g_shell->tokens;
	r_list = malloc(sizeof (t_redir));
	while (fst < lst)
	{
		if (toks[fst].type >= T_REDIR_OUT && toks[fst].type <= T_REDIR_IN)
		{
			if (toks[fst + 1].type == T_FILE)
				add_redir_node(r_list, \
						create_redir_node(toks[fst].type, toks[fst + 1].data));
			else
				print_error();
		}
		fst++;
	}
	return (r_list);
}
