/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:31:22 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/15 14:00:46 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **arg)
{
	ft_putendl_fd("exit", STDERR_FILENO);
	if (arg[1] && !ft_isnum(arg[1]))
	{
		g_shell->ret = 2;
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(arg[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	}
	else if (arg[1] && arg[2])
	{
		g_shell->ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
	}
	else if (arg[1])
		g_shell->ret = ft_atoi(arg[1]) % 256;
	else
		g_shell->ret = 0;
	g_shell->exit = 0;
}
