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
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>

# define LS_OPTIONS		"1ARaflrt"

/*
**	LS_NO_DIR and LS_NO_FILE must be a value from the ascii table [0..127]
**	but not NULL nor a valid filename character
*/
# define LS_NO_DIR		1
# define LS_NO_FILE		1
# define LS_NO_PRINT	1
# define SIX_MONTH		15778800
# define MAX_PATH		1024
# define CAST_LSFILE(a)	((t_lsfile *)a->content)

typedef struct			s_lsfile
{
	char				*name;
	int					namelen;
	char				*fullname;
	int					fullnamelen;
	char				mode[12];
	struct stat			s;
}						t_lsfile;

typedef struct			s_ftls
{
	int					(*skip)(char *d_name);
	int					(*ms_cmp)(const t_list *a, const t_list *b);
	int					(*qs_cmp)(const void *, const void *);
	void				(*print_name)(char *name);
	void				(*print)(t_list *elem, void *);
	size_t				owner_max;
	size_t				group_max;
	size_t				byte_max;
	size_t				nblock;
	_Bool				is_parent;
	_Bool				is_recursion;
	_Bool				is_long;
}						t_ftls;

int						ls_namecmp(const t_list *a, const t_list *b);
int						ls_namecmp_neg(const t_list *a, const t_list *b);
int						ls_strcmp_neg(const void *a, const void *b);
int						ls_timecmp(const t_list *a, const t_list *b);
int						ls_timecmp_neg(const t_list *a, const t_list *b);
int						ls_qstimecmp(const void *a, const void *b);
int						ls_qstimecmp_neg(const void *a, const void *b);

int						ls_skip_upper_a(char *d_name);
int						ls_skip_default(char *d_name);
int						ls_isfile(char *d_name);
int						ls_isdir(char *d_name);

void					ls_print_1(t_list *elem, void *any);
void					ls_print_l(t_list *elem, void *ls);

void					ls_arg_notfile(char **av);
t_list					*ls_arg_lst(char **av);
void					ls_arg_notdir(t_ftls ls, t_list *avlst, char *is_first);
void					ls_arg_isdir(t_ftls ls, int ac,
										t_list *avlst, char is_first);

void					ls_recursion(t_ftls ls, char *d_name);
void					ls_error(char *filename);

t_list					*ls_lstfilenew(char *dirname, char *name, int namlen);
void					ls_lstfiledel(void *content, size_t content_size);
t_list					*ls_lstdir(char *dirname, int (*skip)(char *d_name));

void					ls_set_l(t_list *elem, void *ls);

#endif
