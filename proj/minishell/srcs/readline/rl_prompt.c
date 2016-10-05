/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:00:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:20:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				*gg_status(void)
{
	static int	status;

	return (&status);
}

void			rl_sh_prompt(t_rl *rl, char *base, int settings)
{
	static char	prompt[4096];
	int			ret;

	if (ISIN(settings, RL_COLOR))
		ret = ft_snprintf(prompt, 4096, RL_SH_STYLE_CPROMPT_FORMAT, base);
	else
		ret = ft_snprintf(prompt, 4096, RL_SH_STYLE_PROMPT_FORMAT, base);
	rl->prompt = prompt;
	rl->promptsize = ft_strlen(base) + 3;
}

void			rl_bash_prompt(t_rl *rl, char *base, int settings)
{
	(void)rl;
	(void)base;
	(void)settings;
}

void			rl_omzsh_prompt(t_rl *rl, char *base, int settings)
{
	static char	prompt[4096];

	if (ISIN(settings, RL_42_NODATE))
		ft_snprintf(prompt, 4096, "42 |:|-%s-|:| ", base);
	rl->prompt = prompt;
	rl->promptsize = ft_strlen(prompt);
}
