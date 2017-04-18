/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:18:50 by aphan             #+#    #+#             */
/*   Updated: 2016/12/09 22:55:27 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ms_lstmerge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((int)a->content <= (int)b->content)
	{
		result = a;
		result->next = ms_lstmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ms_lstmerge(a, b->next);
	}
	return (result);
}

static void		ms_partition(t_list *head, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	if (head == NULL || head->next == NULL)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

void			ft_mergesort_int(t_list **source)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *source;
	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	ms_partition(head, &a, &b);
	ft_mergesort_int(&a);
	ft_mergesort_int(&b);
	*source = ms_lstmerge(a, b);
}
