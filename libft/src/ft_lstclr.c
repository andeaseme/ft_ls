/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:41:49 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:52:26 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstclr(t_list **head)
{
	t_list	*current;

	while ((current = *head) != NULL)
	{
		*head = (*head)->next;
		free(current);
	}
	return (*head);
}
