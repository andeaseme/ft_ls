/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_1(t_list *elem, void *any)
{
	t_lsfile	*f;

	f = elem->content;
	write(1, f->name, f->namelen);
	write(1, "\n", 1);
	if (any)
		return ;
}

void	ft_print_l_bc(t_lsfile *f, char *mtime, t_ftls *ls)
{
	ft_printf("%s  %2d %-*s  %-*s  %3d, %4d %.7s%.5s %s", f->mode,
		f->s.st_nlink, ls->owner_max, getpwuid(f->s.st_uid)->pw_name,
		ls->group_max, getgrgid(f->s.st_gid)->gr_name,
		major(f->s.st_rdev), minor(f->s.st_rdev), mtime + 4,
		(time(NULL) - SIX_MONTH < f->s.st_mtime) ? mtime + 11 : mtime + 19,
		f->name);
}

void	ft_print_l_else(t_lsfile *f, char *mtime, t_ftls *ls)
{
	ft_printf("%s  %2d %-*s  %-*s  %*d %.7s%.5s %s",
		f->mode, f->s.st_nlink,
		ls->owner_max, getpwuid(f->s.st_uid)->pw_name,
		ls->group_max, getgrgid(f->s.st_gid)->gr_name,
		ls->byte_max, f->s.st_size, mtime + 4,
		(time(NULL) - SIX_MONTH < f->s.st_mtime) ? mtime + 11 : mtime + 19,
		f->name);
}

void	ls_print_l(t_list *elem, void *lsvoid)
{
	t_lsfile		*f;
	t_ftls			*ls;
	char			*mtime;
	char			link[MAX_PATH];
	ssize_t			len;

	ls = (t_ftls *)lsvoid;
	f = CAST_LSFILE(elem);
	mtime = ctime(&(f->s.st_mtime));
	if (f->mode[0] == 'b' || f->mode[0] == 'c')
		ft_print_l_bc(f, mtime, ls);
	else
		ft_print_l_else(f, mtime, ls);
	if (f->mode[0] == 'l')
	{
		len = readlink(f->fullname, link, MAX_PATH);
		link[len] = 0;
		ft_printf(" -> %s", link);
	}
	write(1, "\n", 1);
}
