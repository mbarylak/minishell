/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:55:42 by mbarylak          #+#    #+#             */
/*   Updated: 2021/09/20 20:07:47 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	int				dig_count;
	unsigned int	nbr;

	dig_count = 1;
	if (n < 0)
	{	
		nbr = n * -1;
		dig_count++;
	}
	else
		nbr = n;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		dig_count++;
	}
	return (dig_count);
}

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	nbr;
	int				dig_count;

	dig_count = digit_counter(n);
	num = (char *) malloc((dig_count + 1) * sizeof (char));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		nbr = n * -1;
		num[0] = '-';
	}
	else
		nbr = n;
	if (nbr == 0)
		num[0] = '0';
	num[dig_count] = '\0';
	while (nbr > 0)
	{
		dig_count--;
		num[dig_count] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (num);
}
