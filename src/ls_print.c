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
	ft_printf("%s %2d %-*s %-*s %3d, %4d %.7s%.5s %s", f->mode,
		f->s.st_nlink, ls->owner_max, getpwuid(f->s.st_uid)->pw_name,
		ls->group_max, getgrgid(f->s.st_gid)->gr_name,
		major(f->s.st_rdev), minor(f->s.st_rdev), mtime + 4,
		(time(NULL) - SIX_MONTH < f->s.st_mtime) ? mtime + 11 : mtime + 19,
		f->name);
}

void	ft_print_l_else(t_lsfile *f, char *mtime, t_ftls *ls)
{
	ft_printf("%s %2d %-*s %-*s %*d %.7s%.5s %s",
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

void	ls_set_mode(t_lsfile *l, struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
		l->mode[0] = 'd';
	else if (S_ISLNK(sb.st_mode))
		l->mode[0] = 'l';
	else if (S_ISCHR(sb.st_mode))
		l->mode[0] = 'c';
	else if (S_ISBLK(sb.st_mode))
		l->mode[0] = 'b';
	else
		l->mode[0] = '-';
	l->mode[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	l->mode[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	l->mode[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	l->mode[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	l->mode[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	l->mode[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	l->mode[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	l->mode[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	l->mode[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
	l->mode[10] = ' ';
	l->mode[11] = 0;
}

void	ls_set_l(t_list *elem, void *lsvoid)
{
	struct stat		sb;
	t_lsfile		*f;
	t_ftls			*ls;
	size_t			len;

	f = CAST_LSFILE(elem);
	ft_bzero(&sb, sizeof(struct stat));
	lstat(f->fullname, &sb);
	ls_set_mode(f, sb);
	ft_memcpy(&(f->s), &sb, sizeof(struct stat));
	ls = (t_ftls *)lsvoid;
	ls->owner_max = MAX(ls->owner_max,
		(size_t)ft_strlen(getpwuid(sb.st_uid)->pw_name));
	ls->group_max = MAX(ls->group_max,
		(size_t)ft_strlen(getgrgid(sb.st_gid)->gr_name));
	len = (f->mode[0] == 'b' || f->mode[0] == 'c') ? 9 : 1;
	if (len == 1)
		while (sb.st_size /= 10)
			len++;
	ls->byte_max = MAX(ls->byte_max, len);
	ls->nblock += sb.st_blocks;
}
