#include "ft_ls.h"

void	ls_print_1(t_list *elem)
{
	t_lsfile	*f;

	f = elem->content;
	write(1, f->name, f->namelen);
	write(1, "\n", 1);
}

void	ls_print_1_name(char *name)
{
	int		i;

	i = 0;
	while (name[i])
		i++;
	name[i] = '\n';
	write(1, name, i + 1);
}

void	ls_print_l(t_list *elem)
{
	t_lsfile	*f;

	f = CAST_LSFILE(elem);
	ft_printf("%s%2d %s %s %6d %.12s %s\n", f->mode, f->s.st_nlink,
			getpwuid(f->s.st_uid)->pw_name, getgrgid(f->s.st_gid)->gr_name,
			f->s.st_size, ctime(&(f->s.st_mtime)) + 4, f->name); 
}

void	ls_print_l_name(char *name)
{
	ls_print_1_name(name); //placeholder
}

void	ls_set_mode(t_lsfile *l, struct stat sb)
{
	l->mode[0] = S_ISDIR(sb.st_mode) ? 'd' : '-';
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

void	ls_set_l(t_list *elem)
{
	struct stat		sb;
	t_lsfile		*f;

	f = CAST_LSFILE(elem);
	ft_bzero(&sb, sizeof(struct stat));
	lstat(f->fullname, &sb);
	ls_set_mode(f, sb);
	ft_memcpy(&(f->s), &sb, sizeof(struct stat));
}
