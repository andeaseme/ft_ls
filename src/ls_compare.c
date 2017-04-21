/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_namecmp(const t_list *a, const t_list *b)
{
	char	*u;
	char	*v;

	u = CAST_LSFILE(a)->name;
	v = CAST_LSFILE(b)->name;
	while (*u == *v && (*u != '\0' || *v != '\0'))
	{
		u++;
		v++;
	}
	return ((unsigned char)*u - (unsigned char)*v);
}

int		ls_timecmp(const t_list *a, const t_list *b)
{
	struct stat		u;
	struct stat		v;

	lstat(CAST_LSFILE(a)->fullname, &u);
	lstat(CAST_LSFILE(b)->fullname, &v);
	if (u.st_mtimespec.tv_sec != v.st_mtimespec.tv_sec)
		return ((int)(v.st_mtimespec.tv_sec - u.st_mtimespec.tv_sec));
	else if (u.st_mtimespec.tv_nsec != v.st_mtimespec.tv_nsec)
		return ((int)(v.st_mtimespec.tv_nsec - u.st_mtimespec.tv_nsec));
	else
		return (ls_namecmp(a, b));
}

int		ls_qstimecmp(const void *a, const void *b)
{
	struct stat		u;
	struct stat		v;

	lstat((char *)a, &u);
	lstat((char *)b, &v);
	if (u.st_mtimespec.tv_sec != v.st_mtimespec.tv_sec)
		return ((int)(v.st_mtimespec.tv_sec - u.st_mtimespec.tv_sec));
	else if (u.st_mtimespec.tv_nsec != v.st_mtimespec.tv_nsec)
		return ((int)(v.st_mtimespec.tv_nsec - u.st_mtimespec.tv_nsec));
	else
		return (ft_strcmp(b, a));
}
