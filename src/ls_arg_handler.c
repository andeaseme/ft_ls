#include "ft_ls.h"

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

void	ls_arg_notdir(t_ftls ls, char **av, char *is_first)
{
	int				i;

	i = 0;
	while (av[i])
	{
		if(av[i][0] != LS_NO_FILE && !ls_isdir(av[i]))
		{
			ls.print_name(av[i]);
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