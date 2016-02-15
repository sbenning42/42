/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:25:11 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 00:58:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void			put_env\
					(void)
{
	char		**ep;

	ep = ENV;
	if (!ep)
	{
		if (IS(O_COLOR, OPT))
			ft_printf("{red}No ENV...{eoc}\n");
		else
			ft_printf("No ENV...\n");
		return ;
	}
	if (IS(O_COLOR, OPT))
		ft_printf("{yellow}put_env{eoc}: %{\n\n");
	else
		ft_printf("put_env: %{\n\n");
	while (*ep)
	{
		ft_printf("%s\n", *ep);
		ep++;
	}
	ft_printf("\n}\n");
}

void			put_av\
					(void)
{
	if (!AV)
	{
		if (IS(O_COLOR, OPT))
			ft_printf("{red}No AV...{eoc}\n");
		else
			ft_printf("No AV...\n");
		return ;
	}
	if (IS(O_COLOR, OPT))
		ft_printf("{yellow}put_av{eoc}: %s\n", AV);
	else
		ft_printf("put_av: %s\n", AV);
}

void			put_opt\
					(void)
{
	if (IS(O_COLOR, OPT))
		ft_printf("{yellow}put_opt{eoc}: %#X\n", OPT);
	else
		ft_printf("put_opt: %#X\n", OPT);
}

void			put_cmd_buffer\
					(char *cmd, int ret)
{
	if (IS(O_COLOR, OPT))
	{
		ft_printf("{yellow}put_cmd_buffer{eoc}:\n");
		ft_printf("%{\n\n{cyan}cmd{eoc}: [{gr}%.*s{eoc}]\n", ret - 1, cmd);
		ft_printf("{cyan}read return{eoc}: [{gr}%d{eoc}]\n\n}\n", ret);
	}
	else
	{
		ft_printf("put_cmd_buffer:\n");
		ft_printf("%{\n\ncmd: [%.*s]\n", ret - 1, cmd);
		ft_printf("read return: [%d]\n\n}\n", ret);
	}
}

void			put_cmd\
					(t_cmd cmd)
{
	int			i;

	ft_printf((IS(O_COLOR, OPT) ? FMT_CCMD : FMT_CMD)\
			, "put_cmd",  cmd.arg_v[0], "] -> [", cmd.pathbin);
	i = 0;
	while (cmd.arg_v[i])
	{
		ft_printf((IS(O_COLOR, OPT) ? FMT_CARGV : FMT_ARGV), i, cmd.arg_v[i]);
		i++;
	}
	ft_printf("\n}\n");
}
