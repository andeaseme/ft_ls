#include "ft_ls.h"

int		ls_namecmp(const t_list *a, const t_list *b)
{
	char	*u;
	char	*v;

	u = ((struct dirent *)a->content)->d_name; 
	v = ((struct dirent *)b->content)->d_name; 
	while (*u == *v && (*u != '\0' || *v != '\0'))
	{
		u++;
		v++;
	}
	return ((unsigned char)*u - (unsigned char)*v);
}

int		ls_namecmp_neg(const t_list *a, const t_list *b)
{
	return (ls_namecmp(b, a));
}

int		ls_strcmp_neg(const void *a, const void *b)
{
	return (ft_strcmp(b, a));
}

int		ls_skip_A(char *d_name)
{
	return (!ft_strcmp(d_name, ".") ? 1 : !ft_strcmp(d_name, ".."));
}

int		ls_skip_default(char *d_name)
{
	return (*d_name == '.');
}

int		ls_isdir(char *d_name)
{
	struct stat		sb;

	ft_bzero(&sb, sizeof(struct stat));
	lstat(d_name, &sb);
	return (S_ISDIR(sb.st_mode));
}

t_list	*ls_lstdir(char *dirname, int (*skip)(char *d_name))
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*dlist;
	t_list			*last;
	t_list			*new;

	dlist = NULL;
	dirp = opendir(dirname);
	if (dirp != NULL)
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if (skip && skip(dp->d_name))
				continue ;
			new = ft_lstnew(dp, dp->d_reclen);
			if (dlist)
				ft_lstadd_after(last, new);
			else
				dlist = new;
			last = new;
		}
		closedir(dirp);
	}
	return (dlist);
}

void	ls_print_1(t_list *elem)
{
	struct dirent	*dp;

	dp = elem->content;
	write(1, dp->d_name, dp->d_namlen);
	write(1, "\n", 1);
}

void	ls_recursion(t_ftls ls, char *d_name, int recursion)
{
	t_list			*dlst;
	t_list			*r;
	char			*r_name;
	char			*this;

	if (!(dlst = ls_lstdir(d_name, ls.skip)))
		return ;
	if (ls.is_parent)
		ls.is_parent = 0;
	else
	{
		ft_putstr(d_name);
		write(1, ":\n", 2);
	}
	ft_mergesort(&dlst, ls.ms_cmp);
	ft_lstiter(dlst, ls.print);
	if (recursion)
	{
		r = dlst;
		while (r)
		{
			this = ((struct dirent *)r->content)->d_name;
			r_name = malloc(ft_strlen(d_name) + ft_strlen(this) + 2);
			r_name = ft_strcat_multi(r_name, d_name, "/", this, NULL);
			if (ls_isdir(r_name))
			{
				write(1, "\n", 1);
				ls_recursion(ls, r_name, recursion);
			}
			free(r_name);
			r = r->next;
		}
	}
	ft_lstfree(&dlst);
}

void	ls_init(t_ftls *ls, int *op)
{
	if (TESTBIT(op, 'a') || TESTBIT(op, 'f'))
		ls->skip = NULL;
	else if (TESTBIT(op, 'A'))
		ls->skip = &ls_skip_A;
	else
		ls->skip = &ls_skip_default;
	if (TESTBIT(op, 'f') && !(ls->ms_cmp = NULL))
		ls->qs_cmp = NULL;
	else if ((ls->ms_cmp = TESTBIT(op, 'r') ? &ls_namecmp_neg : &ls_namecmp))
		ls->qs_cmp =  TESTBIT(op, 'r') ? &ls_strcmp_neg : &ft_strcmp;
	if (TESTBIT(op, 'l'))
		ls->print = &ls_print_1; //tmp until -l print is ready
	else
		ls->print = &ls_print_1;
	ls->is_parent = 1;
}

void	ls_arg_isdir(t_ftls ls, int *ac, char **av)
{
	int				i;
	int				not_dir_count;

	i = 0;
	not_dir_count = 0;
	while (av[i])
	{
		if(!ls_isdir(av[i]))
		{
			ft_printf("ft_ls: %s: No such file or directory\n", av[i]);
			av[i][0] = LS_NO_DIR;
			not_dir_count++;
		}
		i++;
	}
	if (not_dir_count == 0)
		return ;
	ft_quicksort((void **)av, 0, *ac - 1, ls.qs_cmp);
	*ac -= not_dir_count;
}

int		main(int argc, char **argv)
{
	t_ftls			ls;
	int				i;
	int				*options;
	char			**name;

	options = ft_option128(&argc, &argv);
	ls_init(&ls, options);
	ft_quicksort((void **)argv, 1, --argc, ls.qs_cmp);
	argv[0] = ".";
	name = (argv[1]) ? &(argv[1]) : argv;
	ls_arg_isdir(ls, &argc, name);
	i = -1;
	while (name[++i] && name[i][0] != LS_NO_DIR)
	{
		if (name[i][0] == LS_NO_DIR)
			continue ;	
		if (argc > 1)
		{
			ft_putstr(name[i]);
			write(1, ":\n", 2);
		}
		ls_recursion(ls, name[i], TESTBIT(options, 'R'));
		if (argc > 1 && i < argc - 1)
			write(1, "\n", 1);
	}
	free(options);
	return (1);
}
