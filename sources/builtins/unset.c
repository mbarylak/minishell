/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:22:13 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/27 16:23:49 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_error(char *arg)
{
	char	*err_msg;
	char	*aux;

	aux = ft_strjoin("`", arg);
	err_msg = ft_strjoin(aux, "´");
	ft_memdel(aux);
	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	ft_memdel(err_msg);
	if (g_shell->pipes != 0)
		exit(0);
	return (1);
}

static int	len(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '=')
		i++;
	return (i);
}

static void	free_env_node(char *arg, t_list *env)
{
	t_list	*aux;

	if (ft_strncmp(arg, env->content, len(env->content)) == 0)
	{
		g_shell->env = g_shell->env->next;
		ft_memdel(env->content);
		ft_memdel(env);
		env = g_shell->env;
		return ;
	}
	while (env && env->next)
	{
		if (ft_strncmp(arg, env->next->content, len(env->next->content)) == 0)
		{
			aux = env->next->next;
			ft_memdel(env->next->content);
			ft_memdel(env->next);
			env->next = aux;
		}
		env = env->next;
	}
}

int	ft_unset(char **arg)
{
	t_list	*env;
	int		i;

	env = g_shell->env;
	if (!arg[1])
		return (0);
	i = 1;
	while (arg[i])
	{
		if (!is_valid(arg[i]))
			return (print_error(arg[i]));
		free_env_node(arg[i], env);
		i++;
	}
	if (g_shell->pipes != 0)
		exit(0);
	return (0);
}
