/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:02:31 by mbarylak          #+#    #+#             */
/*   Updated: 2021/09/23 19:43:18 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (src[i] && (dst_len + i) < dstsize - 1 && dstsize != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i != 0)
		dst[dst_len + i] = '\0';
	if (dstsize < dst_len)
		count = dstsize + src_len;
	else
		count = dst_len + src_len;
	return (count);
}
