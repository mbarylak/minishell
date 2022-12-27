/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:20:18 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/15 14:15:05 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **arg, t_shell *shell)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (arg[i] && (ft_strncmp(arg[i], "-n", 2) == 0))
	{
		flag = 1;
		i++;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		if (arg[i + 1] && arg[i] != NULL)
			write(1, " ", 1);
		i++;
	}
	if (flag == 0)
		write(1, "\n", 1);
	if (shell->pipes != 0)
		exit(0);
	return (0);
}
