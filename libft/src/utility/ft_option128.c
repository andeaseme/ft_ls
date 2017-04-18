/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option128.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
**	Returns a bit array flagging all options.
**	Decrements 'argc' and increments 'argv' for each options.
**	'argv[1]' will always be the first 'argv' after options
**	similar to having no options.
*/

static void	op128_illegal(char *file, char *ops, char *usage, char c)
{
	ft_printf("%s: illegal option -- %c\n"
		"usage: %s [-%s] [%s]\n",
		file, c,
		file, ops, usage);
	exit(1);
}

int			*ft_option128(int *ac, char ***av, char *valid_ops, char *usage_in)
{
	int		i;
	int		j;
	int		*op;
	char	*filename;

	filename = ft_strrchr(*av[0], '/') + 1;
	i = 0;
	if ((op = (int *)ft_strnew(sizeof(int) * 4 - 1)) && *ac > 1)
	{
		while (*(*av + 1) && (*(*av + 1))[0] == '-' && (*(*av + 1))[1] != 0)
		{
			(*ac)--;
			(*av)++;
			j = 0;
			if (!ft_strcmp(**av, "--"))
				break ;
			while (++j && (**av)[j] > 0 && (**av)[j] <= 127)
			{
				if (valid_ops && !ft_strchr(valid_ops, (int)(**av)[j]))
					op128_illegal(filename, valid_ops, usage_in, (**av)[j]);
				SETBIT(op, (int)(**av)[j]);
			}
		}
	}
	return (op);
}
