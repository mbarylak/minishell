/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:46:16 by mbarylak          #+#    #+#             */
/*   Updated: 2022/12/29 18:25:50 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(char **env)
{
	g_shell = malloc(sizeof(t_shell));
	g_shell->exit = 1;
	g_shell->ret = 0;
	g_shell->exit_stat = 0;
	g_shell->pipes = 0;
	g_shell->nb_args = 0;
	env_to_shell(env);
}

int	main(int argc, char **argv, char **env)
{
	char	*inpt;
	char	**line;
	int		i;

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
			g_shell->tokens = tokenizer(line);
			printf("Num of Args: %d\n", g_shell->nb_args);
			i = 0;
			while (line[i])
			{
				printf("Type of Token: %d\n", g_shell->tokens[i].type);
				printf("Token: %s\n", g_shell->tokens[i].data);
				i++;
			}
			//g_shell->ret = exec_single_child(line);
		}
	}
	return (g_shell->ret);
}
