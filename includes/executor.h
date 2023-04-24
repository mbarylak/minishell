/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:50 by mbarylak          #+#    #+#             */
/*   Updated: 2023/04/24 17:57:50 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/*	EXEC_CMD */

int		execute(t_tree *tree);
char	**get_env_path(t_list *env);
char	*get_right_path(char *cmd);
int		exec_cmd(char **cmd);

/* EXEC_SINGLE_CHILD */

void	exit_status(int status);
int		exec_single_child(char **cmd);

/* SHELL LOOP */

void	in_order(t_tree *tree);
void	shell_loop(void);

/* EXE_PIPES */

int		exe_pipes(t_tree *tree);

/* REDIR */

void	redir(t_tree *tree);

#endif
