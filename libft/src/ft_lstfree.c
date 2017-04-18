/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:15:48 by aphan             #+#    #+#             */
/*   Updated: 2016/09/24 17:24:44 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **alst)
{
	t_list	*current;
	t_list	*forward;

	current = *alst;
	while (current != NULL)
	{
		free(current->content);
		forward = current->next;
		free(current);
		current = forward;
	}
	*alst = NULL;
}
