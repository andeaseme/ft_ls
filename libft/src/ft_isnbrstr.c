/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbrstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:45:16 by aphan             #+#    #+#             */
/*   Updated: 2016/12/03 14:49:54 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnbrstr(char *str)
{
	if (str && (*str == '+' || *str == '-' || ft_isdigit(*str)) && ++str)
	{
		while (*str && ft_isdigit(*str))
			str++;
		if (!(*str))
			return (1);
	}
	return (0);
}
