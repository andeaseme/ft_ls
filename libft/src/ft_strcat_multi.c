/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:14:51 by aphan             #+#    #+#             */
/*   Updated: 2016/09/22 19:14:30 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function will concatenate a series of strings
**	to form a result string.  A sentinel value of NULL
**	should be placed at the end of the list of strings.
*/

char	*ft_strcat_multi(char *result, char *string1, ...)
{
	va_list		args;
	char		*str;
	int			len;
	int			i;

	va_start(args, string1);
	str = string1;
	len = 0;
	while (str)
	{
		i = 0;
		while (str[i])
			result[len++] = str[i++];
		result[len] = 0;
		str = va_arg(args, char *);
	}
	va_end(args);
	return (result);
}
