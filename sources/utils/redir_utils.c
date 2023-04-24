/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:20:34 by mbarylak          #+#    #+#             */
/*   Updated: 2023/04/24 20:36:05 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(char *value)
{
	if (opendir(value) != NULL)
		return (1);
	else
		return (0);
}

void	heredoc(char *value)
{
	char	*inpt;

	inpt = ft_strdup("");
	while (ft_strcmp(inpt, value) != 0)
	{
		free(inpt);
		inpt = readline(">");
	}
	free(inpt);
}