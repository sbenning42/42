/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_42_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 12:41:20 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:24:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char		*rl_42_prompt_pwd(int settings, size_t *len)
{
	char		*pwd;

	pwd = NULL;
	if (!ISIN(settings, RL_42_NOPWD))
	{
		if (!(pwd = ft_getenv("PWD")))
			pwd = "secret";
		*len = *len + ft_strlen(pwd) + 1;
	}
	return (pwd);
}

static char		*rl_42_prompt_date(int settings, char *fdate, size_t *len)
{
	time_t		t;
	char		*date;

	date = NULL;
	if (!ISIN(settings, RL_42_NODATE))
	{
		t = time(NULL);
		date = ctime(&t);
		ft_bzero((void *)fdate, 1024);
		ft_strncpy(fdate, date + 4, ft_strlen(date) - 10);
		date = fdate;
		*len = *len + ft_strlen(date) + 1;
	}
	return (date);
}

void			rl_42_prompt(t_rl *rl, char *base, int settings, size_t len)
{
	static char	prompt[4096];
	char		fdate[1024];
	char		*date;
	char		*pwd;
	char		*status;

	len = 0;
	pwd = rl_42_prompt_pwd(settings, &len);
	date = rl_42_prompt_date(settings, fdate, &len);
	status = (*gg_status() ? ":(" : ";)");
	len += 3;
	ft_bzero((void *)prompt, 4096);
	rl_42_prompt_date_constr(prompt, date, settings);
	rl_42_prompt_pwd_constr(prompt, pwd, settings);
	rl_42_prompt_col_constr(prompt, status, settings);
	rl_42_prompt_base_constr(prompt, base, settings, &len);
	rl->prompt = prompt;
	rl->promptsize = len;
}
