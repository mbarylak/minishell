/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:21:38 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/27 17:04:01 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

int	choose_builtin(char **cmd, t_shell *shell)
{
	int	ret;

	ret = 1;
	if (ft_strcmp(cmd[0], "env") == 0)
		ret = ft_env(shell);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		ret = ft_pwd(shell);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		ret = ft_echo(cmd, shell);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ret = ft_cd(cmd);
	else if (ft_strcmp(cmd[0], "export") == 0)
		ret = ft_export(cmd);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		ret = ft_unset(cmd);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd);
	return (ret);
}

int	exec_builtins(char **cmd)
{
	int	ret;

	ret = -1;
	if (is_builtin(cmd[0]))
		ret = choose_builtin(cmd, g_shell);
	return (ret);
}
