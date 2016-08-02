/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 17:00:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/30 12:39:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			*gg_status(void)
{
	static int	status;

	return (&status);
}

void 		rl_sh_prompt(t_rl *rl, char *base, int settings)
{
	static char	prompt[4096];
	int			ret;

	if (ISIN(settings, RL_COLOR))
		ret = ft_snprintf(prompt, 4096, "{green}%s{eoc} {grey|gr}$>{eoc} ", base);
	else
		ret = ft_snprintf(prompt, 4096, "%s $> ", base);
	rl->prompt = prompt;
	rl->promptsize = ft_strlen(base) + 4;
}

void 		rl_bash_prompt(t_rl *rl, char *base, int settings)
{
	(void)rl;
	(void)base;
	(void)settings;
}

void 		rl_omzsh_prompt(t_rl *rl, char *base, int settings)
{
	static char	prompt[4096];

	if (ISIN(settings, RL_42_NODATE))
		ft_snprintf(prompt, 4096, "42 |:|-%s-|:| ", base);
	rl->prompt = prompt;
	rl->promptsize = ft_strlen(prompt);
}

void 		rl_42_prompt(t_rl *rl, char *base, int settings)
{
	static char	prompt[4096];
	char		fdate[1024];
	char		*date;
	time_t		t;
	char		*pwd;
	char		*status;
	size_t		len;


	len = 0;
	if (!ISIN(settings, RL_42_NOPWD))
	{
		if (!(pwd = ft_getenv("PWD")))
			pwd = "secret";
		len += ft_strlen(pwd) + 1;
	}
	else
		pwd = NULL;
	if (!ISIN(settings, RL_42_NODATE))
	{
		t = time(NULL);
		date = ctime(&t);
		ft_bzero((void *)fdate, 1024);
		ft_strncpy(fdate, date + 4, ft_strlen(date) - 10);
		date = fdate;
		len += ft_strlen(date) + 1;
	}
	else
		date = NULL;
	if (*gg_status())
		status = ":(";
	else
		status = ";)";
	len += 3;
	ft_bzero((void *)prompt, 4096);
	if (date)
	{
		if (ISIN(settings, RL_COLOR))
			ft_snprintf(prompt, 4096, "{pink|gr}%s{eoc} ", date);
		else
			ft_snprintf(prompt, 4096, "%s ", date);
	}
	if (pwd)
	{
		if (ISIN(settings, RL_COLOR))
			ft_snprintf(prompt, 4096, "%s{blue|gr}%s{eoc} ", prompt, pwd);
		else
			ft_snprintf(prompt, 4096, "%s%s ", prompt, pwd);
	}
	if (ISIN(settings, RL_COLOR))
	{
		if (!*gg_status())
			ft_snprintf(prompt, 4096, "%s{cyan|gr}%s{eoc} ", prompt, status);
		else
			ft_snprintf(prompt, 4096, "%s{red|gr}%s{eoc} ", prompt, status);
	}
	else
		ft_snprintf(prompt, 4096, "%s%s ", prompt, status);
	if (base)
	{
		len += ft_strlen(base);
		if (ISIN(settings, RL_COLOR))
			ft_snprintf(prompt, 4096, "%s{grey}%s{eoc}", prompt, base);
		else
			ft_snprintf(prompt, 4096, "%s%s", prompt, base);
	}
	rl->prompt = prompt;
	rl->promptsize = len;
	(void)settings;
}
