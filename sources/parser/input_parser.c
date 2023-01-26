/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:20:00 by danimart          #+#    #+#             */
/*   Updated: 2023/01/26 16:55:48 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_input_size(char *in)
{
	size_t	i;
	int		str;
	int		size;

	i = -1;
	str = 0;
	size = 0;
	while (++i < ft_strlen(in))
	{
		if (in[i] == '"' && str == 1)
			str = 0;
		else if (in[i] == '"' && str == 0)
			str = 1;
		else if ((in[i] == '|' || in[i] == ' ') && str == 0)
			size++;
	}
	return (size);
}

// Temporary solution to avoid breaking the program.
t_input	*parse_input(char *input)
{
	int	size;

	size = get_input_size(input);
	printf("size = %i\n", size);
	return (NULL);
}
