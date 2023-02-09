/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:50 by mbarylak          #+#    #+#             */
/*   Updated: 2023/02/09 19:20:43 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/*	EXEC_CMD */

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

void	redir_loop(t_tree *tree);

#endif
