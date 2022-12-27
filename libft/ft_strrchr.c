/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:54:14 by mbarylak          #+#    #+#             */
/*   Updated: 2021/09/23 19:44:21 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	*str;
	char	ch;

	i = 0;
	ch = (char) c;
	str = (char *) s;
	res = NULL;
	while (str[i])
	{
		if (str[i] == ch)
			res = &str[i];
		i++;
	}
	if (str[i] == ch)
		res = &str[i];
	return (res);
}
