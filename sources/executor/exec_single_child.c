/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:24:15 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/29 17:55:39 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_status(int status)
{
	if (WIFEXITED(status))
		g_shell->exit_stat = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_shell->exit_stat = 128 + WTERMSIG(status);
	else if (WIFSTOPPED(status))
		g_shell->exit_stat = 128 + WSTOPSIG(status);
	else
		g_shell->exit_stat = 0;
}

int	exec_single_child(char **cmd)
{
	int	pid;
	int	status;
	int	ret;

	ret = exec_builtins(cmd);
	if (ret != -1)
		return (ret);
	else
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		else if (pid == 0)
		{
			ret = exec_cmd(cmd);
			exit(ret);
		}
		else
		{
			waitpid(pid, &status, 0);
			exit_status(status);
		}
	}
	return (0);
}
