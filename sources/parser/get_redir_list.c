/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:23:47 by mbarylak          #+#    #+#             */
/*   Updated: 2023/02/09 16:37:09 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_redir	*create_r_node(int type, char *value)
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

void	add_r_node(t_redir **redir_l, t_redir *new)
{
	if (!redir_l)
		return ;
	if (*redir_l == NULL)
		*redir_l = new;
	else
		redir_last(*redir_l)->next = new;
}

t_redir	**get_redir_list(int f, int l)
{
	t_token	*toks;
	t_redir	**r_list;

	toks = g_shell->tokens;
	r_list = malloc(sizeof (t_redir));
	while (f < l)
	{
		if ((toks[f].type >= T_REDIR_OUT && toks[f].type <= T_HEREDOC) && \
				(toks[f - 1].type < T_REDIR_OUT))
		{
			if (toks[f + 1].data && \
					(toks[f + 1].type == T_FILE || toks[f + 1].type == T_CMD))
				add_r_node(r_list, \
						create_r_node(toks[f].type, toks[f + 1].data));
			else
				add_r_node(r_list, create_r_node(toks[f + 1].type, NULL));
		}
		f++;
	}
	return (r_list);
}
