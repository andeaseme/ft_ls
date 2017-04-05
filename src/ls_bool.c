/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_bool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_skip_upper_a(char *d_name)
{
	return (!ft_strcmp(d_name, ".") ? 1 : !ft_strcmp(d_name, ".."));
}

int		ls_skip_default(char *d_name)
{
	return (*d_name == '.');
}

int		ls_isfile(char *d_name)
{
	struct stat		sb;

	return (lstat(d_name, &sb) == 0);
}

int		ls_isdir(char *d_name)
{
	struct stat		sb;

	ft_bzero(&sb, sizeof(struct stat));
	lstat(d_name, &sb);
	return (S_ISDIR(sb.st_mode));
}
