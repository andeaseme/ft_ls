/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	ls_error(char *filename)
{
	ft_putstr_fd("fl_ls: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	perror(NULL);
}

void	ls_set_l(t_list *elem, void *lsvoid)
{
	struct stat		sb;
	t_lsfile		*f;
	t_ftls			*ls;
	size_t			len;

	f = CAST_LSFILE(elem);
	ft_bzero(&sb, sizeof(struct stat));
	if (0 != lstat(f->fullname, &sb))
		ls_error(f->fullname);
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
