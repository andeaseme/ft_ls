/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:23:50 by aphan             #+#    #+#             */
/*   Updated: 2017/01/27 13:41:44 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	new = (new_size) ? malloc(new_size) : ft_strnew(0);
	if (ptr)
	{
		ft_memcpy(new, ptr, (old_size < new_size) ? old_size : new_size);
		free(ptr);
	}
	return (new);
}
