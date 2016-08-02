/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:25:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 17:49:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		debug_cmd(\
			t_cmd cmd)
{
	int		i;

	if (!IS(O_FILEDEBUG, OPT) && !IS(O_DEBUG, OPT))
		return ;
	start_debug("Command");
	i = -1;
	ft_fprintf(FDDEBUG, "Binary: [%s] -> [%s]\n", cmd.arg_v[0], cmd.pathbin);
	while (cmd.arg_v[++i])
		ft_fprintf(FDDEBUG, FMT_ARGV, i, cmd.arg_v[i]);
	end_debug("Command");
}

void		debug_builtin(\
			void)
{
	int		i;

	if (!IS(O_FILEDEBUG, OPT) && !IS(O_DEBUG, OPT))
		return ;
	start_debug("Builtin");
	i = -1;
	while (++i < FT_SH_BUILTIN_SIZE)
		ft_fprintf(FDDEBUG, FMT_BUILTIN_DEBUG, BUILTIN[i].id, BUILTIN[i].built);
	end_debug("Builtin");
}

static void	putbinary(\
			t_dic *e)
{
	if (!e)
		return ;
	ft_fprintf(FDDEBUG, FMT_BINARY_DEBUG, e->id, (char *)e->content);
}

void		debug_binary(\
			void)
{
	if (!IS(O_FILEDEBUG, OPT) && !IS(O_DEBUG, OPT))
		return ;
	start_debug("Binary");
	ft_dicdoinf(BINARY, putbinary);
	end_debug("Binary");
}

void		debug_env(\
			void)
{
	int		i;

	if (!IS(O_FILEDEBUG, OPT) && !IS(O_DEBUG, OPT))
		return ;
	start_debug("Environ");
	i = 0;
	while (ENV[i])
		ft_fprintf(FDDEBUG, "\t%s\n", ENV[i++]);
	end_debug("Environ");
}
