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
# include <pwd.h>
# include <grp.h>

# define LS_OPTIONS		"1ARafr"

/*
**	LS_NO_DIR and LS_NO_FILE must be a value from the ascii table [0..127]
**	but not NULL nor a valid filename character
*/
# define LS_NO_DIR		1
# define LS_NO_FILE		1
# define CAST_LSFILE(a)		((t_lsfile *)a->content)

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
	void				(*print)(t_list *elem);
	char				is_parent										: 1;
	char				is_recursion									: 1;
	char				is_long											: 1;
}						t_ftls;

int						ls_namecmp(const t_list *a, const t_list *b);
int						ls_namecmp_neg(const t_list *a, const t_list *b);
int						ls_strcmp_neg(const void *a, const void *b);

int						ls_skip_A(char *d_name);
int						ls_skip_default(char *d_name);
int						ls_isfile(char *d_name);
int						ls_isdir(char *d_name);

void					ls_print_1(t_list *elem);
void					ls_print_1_name(char *name);
void					ls_print_l(t_list *elem);
void					ls_print_l_name(char *name);

void					ls_arg_notfile(char **av);
void					ls_arg_notdir(t_ftls ls, char **av, char *is_first);
void					ls_arg_isdir(t_ftls ls, int ac, char **av, char is_first);

void					ls_recursion(t_ftls ls, char *d_name);

void					ls_set_l(t_list *elem);

#endif
