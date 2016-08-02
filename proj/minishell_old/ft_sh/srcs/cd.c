/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:05:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 11:25:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int				getargc(\
						char **arg_v)
{
	int					i;

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

static char				handle_cwd(\
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

int						builtin_cd(\
						char **arg_v)
{
	int					arg_c;
	int					o;
	char				e;
	char				nwd_path[FT_SH_CWD_PATH_SIZE + 1];

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
