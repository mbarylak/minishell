/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:54:45 by mbarylak          #+#    #+#             */
/*   Updated: 2021/09/23 13:07:33 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	struct s_list	*list;

	list = malloc(sizeof (content));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
