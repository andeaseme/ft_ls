/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_put_dir_name(char *d_name)
{
	write(1, "\n", 1);
	ft_putstr(d_name);
	write(1, ":\n", 2);
	return (0);
}

static void		ls_put_total_blocks(size_t nblock)
{
	write(1, "total ", 6);
	ft_putnbr(nblock);
	write(1, "\n", 1);
}

void			ls_recursion(t_ftls ls, char *d_name)
{
	t_list			*dlst;
	t_list			*r;
	char			*r_name;

	ls.is_parent = ls.is_parent ? 0 : ls_put_dir_name(d_name);
	if (!(dlst = ls_lstdir(d_name, ls.skip)))
		return ;
	ft_mergesort(&dlst, ls.ms_cmp);
	if (ls.is_long)
	{
		ft_lstiter2(dlst, &ls, &ls_set_l);
		ls_put_total_blocks(ls.nblock);
	}
	ft_lstiter2(dlst, &ls, ls.print);
	if (ls.is_recursion && (r = dlst))
		while (r && (r_name = CAST_LSFILE(r)->fullname))
		{
			ft_bzero(&(ls.owner_max), sizeof(ls.owner_max) * 4);
			if (!ls_skip_upper_a(CAST_LSFILE(r)->name) && ls_isdir(r_name))
				ls_recursion(ls, r_name);
			r = r->next;
		}
	ft_lstdel(&dlst, &ls_lstfiledel);
}

void			ls_init(t_ftls *ls, int *op)
{
	if (TESTBIT(op, 'a') || TESTBIT(op, 'f'))
		ls->skip = NULL;
	else if (TESTBIT(op, 'A'))
		ls->skip = &ls_skip_upper_a;
	else
		ls->skip = &ls_skip_default;
	if (TESTBIT(op, 'f') && !(ls->ms_cmp = NULL))
		ls->qs_cmp = NULL;
	else if (TESTBIT(op, 't')
		&& ((ls->ms_cmp = TESTBIT(op, 'r') ? &ls_timecmp_neg : &ls_timecmp)))
		ls->qs_cmp = TESTBIT(op, 'r') ? &ls_qstimecmp_neg : &ls_qstimecmp;
	else if ((ls->ms_cmp = TESTBIT(op, 'r') ? &ls_namecmp_neg : &ls_namecmp))
		ls->qs_cmp = TESTBIT(op, 'r') ? &ls_strcmp_neg : &ft_strcmp;
	if (TESTBIT(op, 'l') && (ls->is_long = 1))
		ls->print = &ls_print_l;
	else if (!(ls->is_long = 0))
		ls->print = &ls_print_1;
	ls->is_recursion = TESTBIT(op, 'R') ? 1 : 0;
	ls->is_parent = 1;
}

int				main(int argc, char **argv)
{
	t_ftls			ls;
	int				*options;
	char			is_first;
	t_list			*avlst;

	options = ft_option128(&argc, &argv, LS_OPTIONS, "file ...");
	ls_init(&ls, options);
	free(options);
	if (argv[1])
		ft_quicksort((void **)(++argv), 0, (--argc) - 1, ls.qs_cmp);
	else
		argv[0] = ".";
	ls_arg_notfile(argv);
	is_first = 1;
	avlst = ls_arg_lst(argv);
	ls_arg_notdir(ls, avlst, &is_first);
	ls_arg_isdir(ls, argc, avlst, is_first);
	ft_lstdel(&avlst, &ls_lstfiledel);
	return (0);
}
