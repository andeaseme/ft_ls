#include "ft_ls.h"



char		*ls_options(int ac, char **av)
{
	int		i;
	char	*op;

	i = 0;
	op = (char *)malloc(sizeof(char) * 126);
	while (i < 126)
		op[i++] = 0;
	if (ac > 1 && op)
	{
		i = 0;
		while (++i < ac)
			if (av[i][0] == '-' && av[i][1] >= 0 && av[i][1] <= 126)
				op[(int)av[i][1]] = 1;
	}
	return (op);
}

int		main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				i;
	char			*op;
	
	op = ls_options(argc, argv);
	ft_printf("sizeof(op): %d\n", sizeof(op));
	ft_printf("sizeof(op[1]): %d\n", sizeof(op[1]));
	ft_printf("sizeof(int): %d\n", sizeof(int));
	i = 0;
	dirp = opendir(".");
	if (dirp == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
	{
		i++;
		ft_printf("%d: ", i);
		write(1, dp->d_name, dp->d_namlen);
		write(1, "\n", 1);
	}
	(void)closedir(dirp);
	return (1);
}
