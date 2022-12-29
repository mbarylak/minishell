/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:13:55 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/29 18:42:49 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_access(char *line)
{
	dprintf(2, "aqui llega\n");
	if (access(line, X_OK) == 0)
		return (1);
	else if (get_right_path(line) != NULL)
		return (1);
	else
		return (0);
	
}

t_token	create_token(char *data, int type)
{
	t_token	new;

	new.data = data;
	new.type = type;
	return (new);
}

t_token	*tokenizer(char **line)
{
	int		i;
	t_token	*tokens;

	i = 0;
	tokens = malloc(sizeof (t_token));
	if (!tokens)
		return (NULL);
	while (line[i])
	{
		if (ft_strcmp(line[i], "|") == 0)
		{
			tokens[i] = create_token(line[i], T_PIPE);
			g_shell->pipes++;
		}
		else if (check_access(line[i]))
			tokens[i] = create_token(line[i], T_CMD);
		else
			tokens[i] = create_token(line[i], T_ARG);
		i++;
		g_shell->nb_args++;		
	}
	return (tokens);
}