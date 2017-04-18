/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:18:50 by aphan             #+#    #+#             */
/*   Updated: 2016/12/09 22:55:27 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	qs_partition(void *arr[], int low, int high,
							int (*cmp)(const void *, const void *))
{
	void	*pivot;
	int		i;
	int		j;

	pivot = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (cmp(arr[j], pivot) <= 0)
		{
			SWAP(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	SWAP(arr[i], arr[high]);
	return (i);
}

void		ft_quicksort(void *arr[], int low, int high,
								int (*cmp)(const void *, const void *))
{
	int piv;

	if (cmp && low < high)
	{
		piv = qs_partition(arr, low, high, cmp);
		ft_quicksort(arr, low, piv - 1, cmp);
		ft_quicksort(arr, piv + 1, high, cmp);
	}
}
