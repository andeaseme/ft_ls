/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:57:01 by aphan             #+#    #+#             */
/*   Updated: 2017/03/29 21:09:22 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_lstfiledel(void *content, size_t content_size)
{
	t_lsfile	*f;

	if (content_size == 4)
	{
		f = content;
		free(f->name);
		free(f->fullname);
		free(f);
	}
}

t_list			*ls_lstfilenew(char *dirname, char *name, int namlen)
{
	t_list		*node;
	t_lsfile	*f;

	if ((node = malloc(sizeof(t_list))))
	{
		if (!(f = (t_lsfile *)malloc(sizeof(t_lsfile))))
		{
			free(node);
			return (NULL);
		}
		f->fullnamelen = !(dirname) ? namlen + 1
				: ft_strlen(dirname) + namlen + 2;
		f->namelen = namlen;
		f->name = ft_memdup(name, namlen + 1);
		f->fullname = malloc(f->fullnamelen);
		f->fullname = !(dirname) ? ft_strcat_multi(f->fullname, name, NULL)
				: ft_strcat_multi(f->fullname, dirname, "/", name, NULL);
		node->content = (void *)f;
		node->content_size = 4;
		node->next = NULL;
	}
	return (node);
}

t_list			*ls_lstdir(char *dirname, int (*skip)(char *d_name))
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*dlist;
	t_list			*last;
	t_list			*new;

	dlist = NULL;
	if (NULL == (dirp = opendir(dirname)))
		ls_error(dirname);
	else
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if (skip && skip(dp->d_name))
				continue ;
			new = ls_lstfilenew(dirname, dp->d_name, dp->d_namlen + 1);
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
