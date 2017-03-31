/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:26:59 by aphan             #+#    #+#             */
/*   Updated: 2017/03/15 14:57:38 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>

# define LS_OPTIONS		"1ARafr"
# define LS_NO_DIR		127

typedef struct			s_lslongform
{
	char				mode[10];
	int					num_links;
	char				*owner;
	int					owner_len;
	char				*group;
	int					group_len;
	int					num_bytes;
	time_t				time;
	char				*name;
	int					*name_len;
	int					file_type;
}						t_lslongform;

typedef struct			s_ftls
{
	int					(*skip)(char *d_name);
	int					(*ms_cmp)(const t_list *a, const t_list *b);
	int					(*qs_cmp)(const void *, const void *);
	void				(*print)(t_list *elem);
	char				is_parent;
}						t_ftls;

#endif
