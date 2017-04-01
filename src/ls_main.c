#include "ft_ls.h"

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

void	ls_recursion(t_ftls ls, char *d_name)
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
	if (ls.is_recursion)
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
				ls_recursion(ls, r_name);
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
	ls->is_recursion = TESTBIT(op, 'R');
	ls->is_parent = 1;
}

void	ls_arg_notfile(char **av)
{
	int				i;

	i = 0;
	while (av[i])
	{
		if(!ls_isfile(av[i]))
		{
			ft_printf("ft_ls: %s: No such file or directory\n", av[i]);
			av[i][0] = LS_NO_FILE;
		}
		i++;
	}
}

void	ls_arg_notdir(char **av, char *is_first)
{
	int				i;

	i = 0;
	while (av[i])
	{
		if(av[i][0] != LS_NO_FILE && !ls_isdir(av[i]))
		{
			ft_putstr(av[i]);
			write(1, "\n", 2);
			av[i][0] = LS_NO_DIR;
			*is_first = 0;
		}
		i++;
	}
}

void	ls_arg_isdir(t_ftls ls, int ac, char **av, char is_first)
{
	int		i;

	i = 0;
	while (av[i])
	{
		if(av[i][0] != LS_NO_FILE && av[i][0] !=LS_NO_DIR)
		{
			if (!is_first && ac > 1 && i < ac + 1)
				write(1, "\n", 1);
			else
				is_first = 0;
			if (ac > 1)
			{
				ft_putstr(av[i]);
				write(1, ":\n", 2);
			}
			ls_recursion(ls, av[i]);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_ftls			ls;
	int				*options;
	char			is_first;

	options = ft_option128(&argc, &argv);
	ls_init(&ls, options);
	free(options);
	if (argv[1])
		ft_quicksort((void **)(++argv), 0, (--argc) - 1, ls.qs_cmp);
	else
		argv[0] = ".";
	ls_arg_notfile(argv);
	is_first = 1;
	ls_arg_notdir(argv, &is_first);
	ls_arg_isdir(ls, argc, argv, is_first);
	return (1);
}
