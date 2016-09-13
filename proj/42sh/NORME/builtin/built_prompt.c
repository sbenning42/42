/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:19:02 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:16:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void				style_trigger(t_sh *sh, int o, int option, int setting)
{
	if (ISO(o, option))
	{
		if (ISIN(sh->settings, setting))
			sh->settings &= ~setting;
		else
			sh->settings |= setting;
	}
}

void					prompt(t_sh *sh, int ac, char **av)
{
	static char			arg[1024];
	int					o;
	int					skip;

	if ((o = ft_getopt(ac, av, "cpds")) < 0)
		return ;
	skip = 0;
	while (++skip < ac)
	{
		if (av[skip][0] != '-')
			break ;
	}
	if (skip < ac)
	{
		(av[skip][0] ?\
			(void)ft_strncpy(arg, av[skip], 1024) :\
			ft_bzero((void *)arg, 1024));
		sh->prompt = arg;
	}
	else
		sh->prompt = arg;
	style_trigger(sh, o, SH_PROMPT_O_COLOR, RL_COLOR);
	style_trigger(sh, o, SH_PROMPT_O_SH, RL_SH_STYLE);
	style_trigger(sh, o, SH_PROMPT_O_DATE, RL_42_NODATE);
	style_trigger(sh, o, SH_PROMPT_O_PATH, RL_42_NOPWD);
}

int						built_prompt(t_sh *sh, t_tree *root)
{
	int					ac;

	ac = 0;
	while (root->cmd.arg[ac])
		ac++;
	prompt(sh, ac, root->cmd.arg);
	return (0);
}
