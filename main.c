/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:46:16 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/27 17:28:18 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(char **env)
{
	g_shell = malloc(sizeof(t_shell));
	g_shell->exit = 1;
	g_shell->exit_stat = 0;
	g_shell->pipes = 0;
	env_to_shell(env);
}

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;

	(void) argc;
	(void) argv;
	init_shell(env);
	while (g_shell->exit == 1)
	{
		inpt = readline("minishell> ");
		add_history(inpt);
		if (inpt[0] != 0 && inpt[0] != 32)
		{
			line = ft_split(inpt, ' ');
			exec_single_child(line);
		}
	}
	return (g_shell->exit_stat);
}
