/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:32:29 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/15 14:16:34 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_equal_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_env(t_shell *shell)
{
	t_list	*aux;

	aux = shell->env;
	if (!aux)
		return (1);
	while (aux)
	{
		if (find_equal_sign(aux->content))
			ft_putendl_fd(aux->content, 1);
		aux = aux->next;
	}
	if (shell->pipes != 0)
		exit(0);
	return (0);
}
