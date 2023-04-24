/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:07:15 by mbarylak          #+#    #+#             */
/*   Updated: 2023/04/24 20:06:04 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	choose_exec(t_tree *tree)
{
	int	ret;

	ret = exec_builtins(tree->content);
	if (ret == -1)
		exec_cmd(tree->content);
}

void	first_child(t_tree *tree)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		if (g_shell->fd[1] == 1)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(tree);
	}
	else
	{
		g_shell->oldfd[0] = fd[0];
		g_shell->oldfd[1] = fd[1];
		close(fd[1]);
	}
}

void	middle_child(t_tree *tree)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		if (g_shell->fd[0] == 0)
			dup2(g_shell->oldfd[0], STDIN_FILENO);
		close(g_shell->oldfd[0]);
		if (g_shell->fd[1] == 1)
			dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		choose_exec(tree);
	}
	else
	{
		close(g_shell->oldfd[0]);
		g_shell->oldfd[0] = fd[0];
		g_shell->oldfd[1] = fd[1];
		close(fd[1]);
	}
}

void	last_child(t_tree *tree)
{
	int	pid;
	int	status;
	int	x;

	x = 1;
	pid = fork();
	if (pid == 0)
	{
		if (g_shell->fd[0] == 0)
			dup2(g_shell->oldfd[0], STDIN_FILENO);
		close(g_shell->oldfd[0]);
		choose_exec(tree);
	}
	else
	{
		close(g_shell->oldfd[0]);
		waitpid(pid, &status, 0);
		exit_status(status);
		while (x != -1)
			x = wait(&status);
	}
}

int	exe_pipes(t_tree *tree)
{
	if (tree->cmd_pos == P_FIRST)
		first_child(tree);
	else if (tree->cmd_pos == P_MIDDLE)
		middle_child(tree);
	else if (tree->cmd_pos == P_LAST)
		last_child(tree);
	else if (tree->cmd_pos == 0)
		return (1);
	return (0);
}
