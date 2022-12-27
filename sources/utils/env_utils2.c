/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:57:57 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/15 13:43:19 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	name_in_env(char *name, t_list *env)
{
	char	*env_name;
	t_list	*aux;

	aux = env;
	while (aux && aux->content)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			ft_memdel(env_name);
			return (1);
		}
		ft_memdel(env_name);
		aux = aux->next;
	}
	return (0);
}

t_list	*until_name(char *name, t_list *env)
{
	t_list	*aux;
	char	*env_name;

	aux = env;
	while (aux && aux->next)
	{
		env_name = get_name(aux->content);
		if (ft_strcmp(name, env_name) == 0)
		{
			ft_memdel(env_name);
			return (aux);
		}
		ft_memdel(env_name);
		aux = aux->next;
	}
	return (NULL);
}

int	is_in_env(char *arg, t_list *env)
{
	char	*name;
	t_list	*first;

	name = get_name(arg);
	first = env;
	if (name_in_env(name, env))
	{
		env = until_name(name, env);
		ft_memdel(env->content);
		env->content = ft_strdup(arg);
		env = first;
		ft_memdel(name);
		return (1);
	}
	ft_memdel(name);
	return (0);
}

char	**env_2_arr(t_list	*env)
{
	t_list	*aux;
	int		i;
	char	**env_arr;

	aux = env;
	env_arr = malloc(sizeof (char *) * (ft_lstsize(aux) + 1));
	if (!env_arr)
		return (NULL);
	i = 0;
	while (aux)
	{
		if (aux->content)
			env_arr[i] = ft_strdup(aux->content);
		i++;
		aux = aux->next;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
