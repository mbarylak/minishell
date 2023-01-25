/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:23:47 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/25 20:06:23 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(void)
{
	dprintf(2, "Error\n");
}

t_redir	*add_redir_node(int type, char *value)
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

void	create_redir_node(t_redir *redir_l, int type, char *value)
{
	if (redir_l)
	{
		while (redir_l->next)
			redir_l = redir_l->next;
		redir_l->next = add_redir_node(type, value);
	}
	else
		redir_l = add_redir_node(type, value);
}

t_redir	*get_redir_list(int fst, int lst)
{
	t_token	*tokens;
	t_redir	*redir_l;

	tokens = g_shell->tokens;
	redir_l = malloc(sizeof (t_redir));
	if (!redir_l)
		return (NULL);
	while (fst < lst)
	{
		if (tokens[fst].type >= T_REDIR_OUT && tokens[fst].type <= T_HEREDOC)
		{
			if (tokens[fst + 1].type == T_FILE && tokens[fst].type != T_HEREDOC)
				create_redir_node(redir_l, tokens[fst].type, \
						tokens[fst + 1].data);
			else
				print_error();
		}
		fst++;
	}
	return (redir_l);
}
