/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:53:42 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/15 14:16:58 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(int n, char *err)
{
	if (n == 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(err, STDERR_FILENO);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}	
	else if (n == 1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		perror(err);
	}
	if (g_shell->pipes != 0)
		exit(1);
}

static int	update_env(char *s)
{
	char	buf[PATH_MAX];
	char	*path;
	t_list	*aux_env;

	path = NULL;
	aux_env = g_shell->env;
	if (!getcwd(buf, PATH_MAX) || !g_shell->env)
		return (1);
	while (aux_env && aux_env->next)
	{
		if (ft_strncmp(aux_env->content, s, ft_strlen(s)) == 0)
		{
			if (aux_env->content)
				ft_memdel(aux_env->content);
			path = ft_strjoin(s, buf);
			if (!path)
				return (1);
			aux_env->content = ft_strdup(path);
			break ;
		}
		aux_env = aux_env->next;
	}
	ft_memdel(path);
	return (0);
}

static int	cd_aux(char *s)
{
	char	*path;

	path = ft_getenv(s, g_shell->env);
	if (!path)
	{
		print_error(0, s);
		return (1);
	}
	update_env("OLDPWD=");
	if (chdir(path) == -1)
		print_error(1, path);
	update_env("PWD=");
	ft_memdel(path);
	return (0);
}

int	ft_cd(char **arg)
{
	int	ret;

	ret = 0;
	if (!arg[1])
		ret = cd_aux("HOME");
	else if (arg[1] && ft_strncmp(arg[1], "-", 1) == 0)
	{
		ret = cd_aux("OLDPWD");
		if (ret == 0)
			ft_pwd(g_shell);
	}
	else
	{
		update_env("OLDPWD=");
		ret = chdir(arg[1]);
		if (ret == -1)
			print_error(1, arg[1]);
		update_env("PWD=");
	}
	if (g_shell->pipes != 0)
		exit(0);
	if (ret < 0)
		return (ret * -1);
	return (ret);
}
