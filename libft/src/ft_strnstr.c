/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:06:34 by aphan             #+#    #+#             */
/*   Updated: 2016/09/23 18:19:41 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	int			c;

	i = -1;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[++i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			c = 0;
			while (little[j] && big[i + j] && c != -1 && i + j < len)
			{
				if (little[j] != big[i + j])
					c = -1;
				else
					j++;
				if (!little[j] && c != -1)
					return ((char *)&big[i]);
			}
		}
	}
	return (0);
}
