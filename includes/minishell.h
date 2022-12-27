/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:36:38 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/27 17:23:22 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/errno.h>

typedef struct s_shell
{
	t_list	*env;
	int		exit;
	int		exit_stat;
	int		pipes;
}	t_shell;

t_shell	*g_shell;

/*	ENV UTILS	*/

int		env_to_shell(char **env_arr);
char	*get_value(char *arg);
char	*get_name(char *arg);
char	*ft_getenv(char *arg, t_list *env);
void	sort_env(char **env_arr, int env_len);
int		arr_len(char **arr);
int		name_in_env(char *name, t_list *env);
t_list	*until_name(char *name, t_list *env);
int		is_in_env(char *arg, t_list *env);
char	**env_2_arr(t_list *env);

/*	UTILS	*/

void	print_env(char **env);
void	print_list(t_list *env);
void	free_arr(char **arr);
int		print_secret(t_shell *shell, int fd);

/* BUILTIN UTILS */

int		is_builtin(char *cmd);
int		choose_builtin(char **cmd, t_shell *shell);
int		exec_builtins(char **cmd);
int		is_valid(char *arg);
int		add_2_env(char *arg, t_list *env);

/*	BUILTINS	*/

int		ft_env(t_shell *shell);
int		ft_secret(t_shell *shell);
int		ft_pwd(t_shell *shell);
int		ft_echo(char **arg, t_shell *shell);
void	ft_exit(char **arg);
int		ft_cd(char **arg);
int		ft_export(char **arg);
int		ft_unset(char **arg);

/* EXECUTOR */

int		exec_cmd(char **cmd);
void	exit_status(int status);
int		exec_single_child(char **cmd);

#endif
