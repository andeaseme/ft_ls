/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_compare_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_namecmp_neg(const t_list *a, const t_list *b)
{
	return (ls_namecmp(b, a));
}

int		ls_strcmp_neg(const void *a, const void *b)
{
	return (ft_strcmp(b, a));
}

int		ls_timecmp_neg(const t_list *a, const t_list *b)
{
	return (ls_timecmp(b, a));
}

int		ls_qstimecmp_neg(const void *a, const void *b)
{
	return (ls_qstimecmp(b, a));
}
