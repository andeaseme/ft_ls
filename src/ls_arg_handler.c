/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_arg_notfile(char **av)
{
	int				i;

	i = 0;
	while (av[i])
	{
		if (!ls_isfile(av[i]))
		{
			ls_error(av[i]);
			av[i][0] = LS_NO_FILE;
		}
		i++;
	}
}

t_list	*ls_arg_lst(char **av)
{
	t_list			*dlist;
	t_list			*last;
	t_list			*new;
	int				i;

	dlist = NULL;
	i = -1;
	while (++i >= 0 && av[i])
	{
		if (av[i][0] == LS_NO_FILE)
			continue ;
		new = ls_lstfilenew(NULL, av[i], ft_strlen(av[i]) + 1);
		if (dlist)
			ft_lstadd_after(last, new);
		else
			dlist = new;
		last = new;
	}
	return (dlist);
}

void	ls_arg_notdir(t_ftls ls, t_list *avlst, char *is_first)
{
	int				i;
	t_lsfile		*f;
	char			link[MAX_PATH];
	ssize_t			len;

	i = 0;
	if (avlst)
		ft_lstiter2(avlst, &ls, &ls_set_l);
	while (avlst)
	{
		f = CAST_LSFILE(avlst);
		if (ls.is_long && f->mode[0] == 'l')
		{
			len = readlink(f->name, link, MAX_PATH);
			link[len] = 0;
			ls.print(avlst, &ls);
			f->name[0] = LS_NO_DIR;
			*is_first = 0;
		}
		else if (f->mode[0] != 'l' && f->mode[0] != 'd')
		{
			ls.print(avlst, &ls);
			f->name[0] = LS_NO_DIR;
			*is_first = 0;
		}
		avlst = avlst->next;
	}
}

void	ls_arg_isdir(t_ftls ls, int ac, t_list *avlst, char is_first)
{
	int		i;

	i = 0;
	while (avlst)
	{
		if (CAST_LSFILE(avlst)->name[0] != LS_NO_FILE
			& CAST_LSFILE(avlst)->name[0] != LS_NO_DIR)
		{
			if (!is_first && ac > 1 && i < ac + 1)
				write(1, "\n", 1);
			else
				is_first = 0;
			if (ac > 1)
			{
				ft_putstr(CAST_LSFILE(avlst)->name);
				write(1, ":\n", 2);
			}
			ls_recursion(ls, CAST_LSFILE(avlst)->name);
		}
		i++;
		avlst = avlst->next;
	}
}
