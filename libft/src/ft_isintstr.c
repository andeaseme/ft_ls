/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isintstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:47:04 by aphan             #+#    #+#             */
/*   Updated: 2016/12/03 14:56:06 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isintstr(char *str)
{
	int		sign;
	int		len;
	char	*intlimit[2];

	if (ft_isnbrstr(str))
	{
		intlimit[0] = "2147483647";
		intlimit[1] = "2147483648";
		sign = (*str == '-') ? 1 : 0;
		if (*str == '-' || *str == '+')
			str++;
		while (*str == '0')
			str++;
		if (((len = ft_strlen(str)) == 10
					&& ft_strcmp(intlimit[sign], str) >= 0)
				|| (len < 10))
			return (1);
	}
	return (0);
}
