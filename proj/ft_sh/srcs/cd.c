/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:05:42 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 19:54:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	getargc(\
			char **arg_v)
{
	int		i;

	i = 0;
	while (arg_v[i])
		i++;
	return (i);
}

static void	handle_cwd(\
			char **arg_v, char *cwd_path)
{
	char	*home;

	ft_bzero((void *)cwd_path, sizeof(char) * (FT_SH_CWD_PATH_SIZE + 1));
	if (!arg_v[0])
	{
		if (!(home = intern_getenv("HOME")))
		{
			ft_fprintf(2, "No Home msg\n");
			return ;
		}
		ft_strcpy(cwd_path, home);
	}
	else
		ft_strcpy(cwd_path, arg_v[0]);
}

int			builtin_cd(\
			char **arg_v)
{
	int		arg_c;
	int		o;
	char	e;
	char	cwd_path[FT_SH_CWD_PATH_SIZE + 1];

	e = 0;
	arg_c = getargc(arg_v);
	o = get_opt(CSET_CD_O, arg_c, arg_v, &e);
	if (IS(O_PRIVATE_ERROR, o))
		return (cd_usage(e));
	arg_v += go_over_opt(arg_c, arg_v);
	handle_cwd(arg_v, cwd_path);
	if (!cwd_path[0])
		return (1);
	
/*
***	have to get cwd or PWD= (dangerous in case of ENV compromition)
***	put it on the OLDPWD (if is not, create it)
*** put the cwd_path calculated below on PWD (if is not create it) and call the chdir syscall
*/
	return (1);
}







