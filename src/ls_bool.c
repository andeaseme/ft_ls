#include "ft_ls.h"

int		ls_skip_A(char *d_name)
{
	return (!ft_strcmp(d_name, ".") ? 1 : !ft_strcmp(d_name, ".."));
}

int		ls_skip_default(char *d_name)
{
	return (*d_name == '.');
}

int		ls_isfile(char *d_name)
{
	struct stat		sb;

	return (lstat(d_name, &sb) == 0);
}

int		ls_isdir(char *d_name)
{
	struct stat		sb;

	ft_bzero(&sb, sizeof(struct stat));
	lstat(d_name, &sb);
	return (S_ISDIR(sb.st_mode));
}
