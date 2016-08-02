/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:19:02 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/29 20:33:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

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
		if (av[skip][0])
			ft_strncpy(arg, av[skip], 1024);
		else
			ft_bzero((void *)arg, 1024);
		sh->prompt = arg;
	}
	else
		sh->prompt = arg;
	if (ISO(o, SH_PROMPT_O_COLOR))
	{
		if (ISIN(sh->settings, RL_COLOR))
			sh->settings &= ~RL_COLOR;
		else
			sh->settings |= RL_COLOR;
	}
	if (ISO(o, SH_PROMPT_O_SH))
	{
		if (ISIN(sh->settings, RL_SH_STYLE))
			sh->settings &= ~RL_SH_STYLE;
		else
			sh->settings |= RL_SH_STYLE;
	}
	if (ISO(o, SH_PROMPT_O_DATE))
	{
		if (ISIN(sh->settings, RL_42_NODATE))
			sh->settings &= ~RL_42_NODATE;
		else
			sh->settings |= RL_42_NODATE;
	}
	if (ISO(o, SH_PROMPT_O_PATH))
	{
		if (ISIN(sh->settings, RL_42_NOPWD))
			sh->settings &= ~RL_42_NOPWD;
		else
			sh->settings |= RL_42_NOPWD;
	}
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
