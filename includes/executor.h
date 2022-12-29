/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:50 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/29 17:55:45 by mbarylak         ###   ########.fr       */
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

#endif
