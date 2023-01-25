/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:48:31 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/25 19:41:47 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_counter(int first, int last)
{
	t_token	*tokens;
	int		size;

	size = 0;
	tokens = g_shell->tokens;
	while (first < last)
	{
		if (tokens[first].type == T_CMD || tokens[first].type == T_ARG)
			size++;
		first++;
	}
	return (size);
}

char	**join_cmd(int first, int last)
{
	t_token	*tokens;
	char	**cmd;
	int		i;

	i = 0;
	tokens = g_shell->tokens;
	cmd = malloc(sizeof (char *) * (arg_counter(first, last) + 1));
	if (!cmd)
		return (NULL);
	while (first < last)
	{
		if (tokens[first].type == T_CMD || tokens[first].type == T_ARG)
			cmd[i++] = tokens[first].data;
		first++;
	}
	cmd[i] = NULL;
	return (cmd);
}
