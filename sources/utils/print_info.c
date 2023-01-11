/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:07:25 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/11 16:10:45 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		dprintf(2, "%s ", env[i]);
		i++;
	}
}

void	print_list(t_list *env)
{
	t_list	*aux;

	aux = env;
	while (aux)
	{
		if (aux->content)
			dprintf(2, "%s\n", aux->content);
		aux = aux->next;
	}
}

static char	*ft_msg_aux(char *arg)
{
	char	*value;
	char	*aux;
	char	*msg;

	value = get_value(arg);
	aux = ft_strjoin("\"", value);
	ft_memdel(value);
	value = ft_strjoin(aux, "\"");
	ft_memdel(aux);
	msg = get_name(arg);
	aux = ft_strjoin(msg, "=");
	ft_memdel(msg);
	msg = ft_strjoin(aux, value);
	ft_memdel(aux);
	ft_memdel(value);
	return (msg);
}

static char	*ft_msg(char *arg)
{
	char	*msg;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	while (arg[i++] && flag == 0)
		if (arg[i] == '=')
			flag = 1;
	if (flag == 1)
		msg = ft_msg_aux(arg);
	else
		msg = ft_strdup(arg);
	return (msg);
}

int	print_secret(t_shell *shell, int fd)
{
	char	**env_arr;
	char	*msg;
	int		i;

	env_arr = env_2_arr(shell->env);
	if (!env_arr)
		return (1);
	sort_env(env_arr, arr_len(env_arr));
	i = 0;
	while (env_arr[i])
	{
		ft_putstr_fd("declare -x ", fd);
		msg = ft_msg(env_arr[i]);
		ft_putendl_fd(msg, fd);
		ft_memdel(msg);
		i++;
	}
	free_arr(env_arr);
	if (shell->pipes != 0)
		exit(0);
	return (0);
}
