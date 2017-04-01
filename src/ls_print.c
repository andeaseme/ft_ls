#include "ft_ls.h"

void	ls_print_1(t_list *elem)
{
	write(1, elem->content, elem->content_size);
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
	ls_print_1(elem); //placeholder
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
}

void	ls_set_l(t_list *elem)
{
	struct stat		sb;
	t_lsfile		*l;

	ft_bzero(&sb, sizeof(struct stat));
	lstat(elem->content, &sb);
	l = (t_lsfile *)malloc(sizeof(t_lsfile));
	ls_set_mode(l, sb);
	l->nlink = sb.st_nlink;
	
	ft_printf("%s\t%d\t%s\n", l->mode, l->nlink, elem->content); 
}
