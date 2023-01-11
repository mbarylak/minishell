/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:28:32 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/11 18:52:30 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *arg)
{
	char	*err_msg;
	char	*aux;

	aux = ft_strjoin("`", arg);
	err_msg = ft_strjoin(aux, "´");
	ft_memdel(aux);
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	ft_memdel(err_msg);
	if (g_shell->pipes != 0)
		exit(1);
}

int	is_valid(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) == 0 && arg[i] != '_')
		return (0);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalnum(arg[i]) == 0 && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	add_2_env(char *arg, t_list	*env)
{
	t_list	*new;
	t_list	*aux;

	if (env && env->content == NULL)
	{
		env->content = ft_strdup(arg);
		return (0);
	}
	new = malloc(sizeof (t_list));
	if (!new)
		return (-1);
	new->content = ft_strdup(arg);
	while (env && env->next && env->next->next)
		env = env->next;
	aux = env->next;
	env->next = new;
	new->next = aux;
	return (0);
}

int	ft_export(char **arg)
{
	int	i;

	i = 1;
	if (!arg[i])
		return (print_secret(g_shell, 1));
	while (arg[i])
	{
		if (!is_valid(arg[i]))
		{
			print_error(arg[i]);
			return (1);
		}
		if (!is_in_env(arg[i], g_shell->env))
			add_2_env(arg[i], g_shell->env);
		i++;
	}
	if (g_shell->pipes != 0)
		exit(0);
	return (0);
}
