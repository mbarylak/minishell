/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:46:16 by mbarylak          #+#    #+#             */
/*   Updated: 2023/01/26 18:38:22 by mbarylak         ###   ########.fr       */
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

	(void) argc;
	(void) argv;
	init_shell(env);
	while (g_shell->exit == 1)
	{
		inpt = readline("minishell> ");
		add_history(inpt);
		g_shell->pipes = 0;
		g_shell->nb_args = 0;
		if (inpt[0] != 0 && inpt[0] != 32)
		{
			line = ft_split(inpt, ' ');
			g_shell->tokens = tokenizer(line);
			g_shell->tree = create_tree();
			shell_loop();
		}
	}
	return (g_shell->ret);
}
