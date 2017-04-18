/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 16:36:30 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 17:30:33 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter2(t_list *lst, void *any, void (*f)(t_list *elem, void *any))
{
	while (lst)
	{
		f(lst, any);
		lst = lst->next;
	}
}
