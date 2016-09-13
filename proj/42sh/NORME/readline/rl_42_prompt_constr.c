/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_42_prompt_constr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:00:31 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:20:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_42_prompt_date_constr(char *prompt, char *date, int settings)
{
	if (date)
	{
		if (ISIN(settings, RL_COLOR))
			ft_snprintf(prompt, 4096, "{pink|gr}%s{eoc} ", date);
		else
			ft_snprintf(prompt, 4096, "%s ", date);
	}
}

void	rl_42_prompt_pwd_constr(char *prompt, char *pwd, int settings)
{
	if (pwd)
	{
		if (ISIN(settings, RL_COLOR))
			ft_snprintf(prompt, 4096, "%s{blue|gr}%s{eoc} ", prompt, pwd);
		else
			ft_snprintf(prompt, 4096, "%s%s ", prompt, pwd);
	}
}

void	rl_42_prompt_col_constr(char *prompt, char *status, int settings)
{
	if (ISIN(settings, RL_COLOR))
	{
		if (!*gg_status())
			ft_snprintf(prompt, 4096, "%s{cyan|gr}%s{eoc} ", prompt, status);
		else
			ft_snprintf(prompt, 4096, "%s{red|gr}%s{eoc} ", prompt, status);
	}
	else
		ft_snprintf(prompt, 4096, "%s%s ", prompt, status);
}

void	rl_42_prompt_base_constr(\
			char *prompt,\
			char *base,\
			int settings,\
			size_t *len)
{
	if (base)
	{
		*len = *len + ft_strlen(base);
		if (ISIN(settings, RL_COLOR))
			ft_snprintf(prompt, 4096, "%s{grey}%s{eoc}", prompt, base);
		else
			ft_snprintf(prompt, 4096, "%s%s", prompt, base);
	}
}
