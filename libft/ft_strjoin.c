/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:12:35 by mbarylak          #+#    #+#             */
/*   Updated: 2021/09/23 19:45:06 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	strjoin = (char *) ft_calloc(size1 + size2 + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	while (size2)
	{
		size2--;
		strjoin[size1 + size2] = s2[size2];
	}
	while (size1)
	{
		size1--;
		strjoin[size1 + size2] = s1[size1];
	}
	return (strjoin);
}
