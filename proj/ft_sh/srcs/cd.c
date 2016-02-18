/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:05:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/18 19:18:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	supprtwopoint(\
			char *s, int *j)
{
	int		i;
	char	*f;

	i = *j;
	if (s[i - 1] != '/' || (s[i + 2] && s[i + 2] != '/'))
		return ;
	else if (!s[i + 2] && i != 1)
	{
		s[i - 1] = 0;
		f = ft_strrchr(s, '/');
		f = 0;
	}
	else if (!s[i + 2])
		s[i] = 0;
	else
	{
		s[i - 1] = 0;
		f = ft_strrchr(s, '/');
		*f = 0;
		ft_strcat(s, s + i + 2);
	}
	*j = -1;
}

static void	supprpoint(\
			char *s, int *j)
{
	int		i;

	i = *j;
	if (s[i - 1] != '/' || (s[i + 1] && s[i + 1] != '/'))
		return ;
	else if (!s[i + 1])
	{
		s[i] = 0;
		s[i - 1] = (i == 1 ? s[i - 1] : 0);
		return ;
	}
	if (i == 1)
		ft_strcpy(s, s + 2);
	else if (!s[i + 2])
	{
		s[i - 1] = 0;
		s[i] = 0;
		s[i + 1] = 0;
	}
	else
	{
		s[i - 1] = 0;
		ft_strcat(s, s + i + 1);
	}
	*j = -1;
}

static void	gothrowabs(\
			char *dest, char *go)
{
	int		i;

	i = 0;
	while (go[i])
	{
		if (go[i] == '.' && go[i + 1] != '.')
			supprpoint(go, &i);
		else if (go[i] == '.' && go[i + 1] == '.')
			supprtwopoint(go, &i);
		i++;
	}
	ft_strcpy(dest, go);
}

static void	gothrowrel(\
			char *dest, char *go, char *pwd)
{
	ft_strcpy(dest, pwd);
	ft_strcat(dest, "/");
	ft_strcat(dest, go);
	gothrowabs(dest, dest);
}

static void	cleanslash(\
			char *cp)
{
	int		i;

	i = 0;
	while (cp[i])
	{
		if (cp[i] == '/' && cp[i + 1] == '/')
		{
			cp[i] = 0;
			ft_strcat(cp, cp + i-- + 1);
		}
		if (cp[i] == '/' && !cp[i + 1] && i)
			cp[i--] = 0;
		i++;
	}
}

static char	*constructpwd(\
			char *nrel, char *old)
{
	char	cp[FT_SH_CWD_PATH_SIZE + 1];

	ft_strcpy(cp, nrel);
	cleanslash(cp);
	ft_bzero((void *)nrel, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (*cp == '/')
		gothrowabs(nrel, cp);
	else
		gothrowrel(nrel, cp, old);
	return (nrel);
}

static int	cdenv(\
			char *nwd_path, char put)
{
	char	*cwd_path;

	if (!(cwd_path = intern_getenv("PWD")))
		cd_error(Unknow, NULL, EXIT_SUCCESS);
	else if (!intern_setenv("OLDPWD", cwd_path))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (chdir(nwd_path))
		cd_error(Chdir, nwd_path, EXIT_SUCCESS);
	else if (!intern_setenv("PWD", constructpwd(nwd_path, cwd_path)))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (put)
		ft_printf((IS(O_COLOR, OPT) ? "{cyan}%s{eoc}\n" : "%s\n"), nwd_path);
	return (1);

}

static int	fcdenv(\
			char *nwd_path, char put)
{
	char	*cp;
	char	cwd_path[FT_SH_CWD_PATH_SIZE + 1];

	ft_bzero((void *)cwd_path, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (!(cp = intern_getenv("PWD")))
		cd_error(Unknow, NULL, EXIT_SUCCESS);
	else if (!intern_setenv("OLDPWD", cp))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (chdir(nwd_path))
		cd_error(Chdir, nwd_path, EXIT_SUCCESS);
	else if (!getcwd(cwd_path, FT_SH_CWD_PATH_SIZE))
		cd_error(Getcwd, NULL, EXIT_SUCCESS);
	else if (!intern_setenv("PWD", cwd_path))
		cd_error(Malloc, NULL, EXIT_FAILURE);
	else if (put)
		ft_printf((IS(O_COLOR, OPT) ? "{cyan}%s{eoc}\n" : "%s\n"), cwd_path);
	return (1);
}

static int	getargc(\
			char **arg_v)
{
	int		i;

	i = 0;
	while (arg_v[i])
		i++;
	return (i);
}

static t_error_msg_id	isvalid(\
						char *path, char **arg_v)
{
	struct stat			s;

	if (access(path, F_OK))
		return (cd_error(Cdnofound, path, EXIT_SUCCESS));
	else if (access(path, R_OK))
		return (cd_error(Cdnoright, path, EXIT_SUCCESS));
	else if (stat(path, &s))
		return (cd_error(Cdstat, path, EXIT_SUCCESS));
	if (!IS(S_IFDIR, s.st_mode))
		return (cd_error(Cdnodir, path, EXIT_SUCCESS));
	if (arg_v[0] && arg_v[1])
		return (cd_error(Cdtoomany, NULL, EXIT_SUCCESS));
	return (1);
}

static char	handle_cwd(\
			char **arg_v, char *nwd_path)
{
	char	*spec;

	ft_bzero((void *)nwd_path, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (!arg_v[0])
	{
		if (!(spec = intern_getenv("HOME")))
		{
			ft_fprintf(2, (IS(O_COLOR, OPT) ? FMT_COL_NOHOME : FMT_STD_NOHOME));
			return (-1);
		}
		ft_strcpy(nwd_path, spec);
	}
	else if (!ft_strcmp("-", arg_v[0]))
	{
		spec = intern_getenv("OLDPWD");
		ft_strcpy(nwd_path, (spec ? spec : ""));
		return (1);
	}
	else
		ft_strcpy(nwd_path, arg_v[0]);
	if (!isvalid(nwd_path, arg_v))
		return (-1);
	return (0);
}

int			builtin_cd(\
			char **arg_v)
{
	int		arg_c;
	int		o;
	char	e;
	char	nwd_path[FT_SH_CWD_PATH_SIZE + 1];

	e = 0;
	arg_c = getargc(arg_v);
	o = get_opt(CSET_CD_O, arg_c, arg_v, &e);
	if (IS(O_PRIVATE_ERROR, o) || (IS(O_CD_FOLLOW, o) && IS(O_CD_NOFOLLOW, o)))
		return (cd_usage(e));
	arg_v += go_over_opt(arg_c, arg_v);
	e = handle_cwd(arg_v, nwd_path);
	if (!nwd_path[0] || e < 0)
		return (1);
	return ((IS(O_CD_FOLLOW, o) ? fcdenv(nwd_path, e) : cdenv(nwd_path, e)));
}
