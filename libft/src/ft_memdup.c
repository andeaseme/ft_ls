/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:13:41 by aphan             #+#    #+#             */
/*   Updated: 2017/03/15 17:23:12 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void	*dst;

	if (src)
	{
		dst = (void *)malloc(n);
		if (dst)
			return (ft_memcpy(dst, src, n));
	}
	return (NULL);
}
