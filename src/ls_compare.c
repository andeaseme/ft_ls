#include "ft_ls.h"

int		ls_namecmp(const t_list *a, const t_list *b)
{
	char	*u;
	char	*v;

	u = ((struct dirent *)a->content)->d_name; 
	v = ((struct dirent *)b->content)->d_name; 
	while (*u == *v && (*u != '\0' || *v != '\0'))
	{
		u++;
		v++;
	}
	return ((unsigned char)*u - (unsigned char)*v);
}

int		ls_namecmp_neg(const t_list *a, const t_list *b)
{
	return (ls_namecmp(b, a));
}

int		ls_strcmp_neg(const void *a, const void *b)
{
	return (ft_strcmp(b, a));
}
