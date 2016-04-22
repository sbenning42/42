/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 11:54:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_code_home(t_rl *rl)
{
	char	*str;
	size_t	len;

	if (!(len = rl->dyn.ante))
		return (0);
	if (!(str = ft_strnew(len)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpopante(&rl->dyn, str, len);
	dyn_strpushpost(&rl->dyn, str, len);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_backward(len);
	return (0);
}

int		rl_code_cl(t_rl *rl)
{
	cur_all_clr();
	cur_write(rl->prompt, rl->promptsize);
	if (ISIN(rl->settings, RL_ECHO))
	{
		if (rl->dyn.ante)
			cur_write(rl->dyn.str, rl->dyn.ante);
		if (rl->dyn.post)
		{
			cur_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
			cur_go_backward(rl->dyn.post);
		}
	}
	return (0);
}

int		rl_code_retarr(t_rl *rl)
{
	if (!rl->dyn.ante)
		return (0);
	dyn_strpopante(&rl->dyn, NULL, 1);
	if (ISIN(rl->settings, RL_ECHO))
	{
		cur_go_backward(1);
		cur_from_clr();
		if (rl->dyn.post)
			cur_static_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
	}
	return (0);
}

int		rl_code_insert(t_rl *rl)
{
	if (ISIN(rl->bitset, RL_BS_INSERT))
		rl->bitset &= ~RL_BS_INSERT;
	else
		rl->bitset |= RL_BS_INSERT;
	return (0);
}

int		rl_code_suppr(t_rl *rl)
{
	if (!rl->dyn.post)
		return (0);
	dyn_strpoppost(&rl->dyn, NULL, 1);
	if (ISIN(rl->settings, RL_ECHO))
	{
		cur_from_clr();
		if (rl->dyn.post)
			cur_static_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
	}
	return (0);
}

int		rl_code_up(t_rl *rl)
{
	char	*str;
	size_t	len;

	if (!rl->hist_cp.cursor->p)
		return (0);
	len = rl->dyn.post;
	if (!(str = ft_strnew(len)))
		return (-1);
	if (rl->dyn.ante)
	{
		cur_go_backward(rl->dyn.ante);
		cur_from_clr();
	}
	dyn_strpoppost(&rl->dyn, str, len);
	dyn_strpushante(&rl->dyn, str, len);
	free(str);
	rl->hist_cp.cursor->content = ft_strdup(rl->dyn.str);
	rl->hist_cp.cursor->content_size = ft_strlen(rl->dyn.str) + 1;
	rl->hist_cp.cursor = rl->hist_cp.cursor->p;
	free(rl->dyn.str);
	rl->dyn.str = rl->hist_cp.cursor->content;
	rl->dyn.real = rl->hist_cp.cursor->content_size - 1;
	rl->dyn.strend = rl->dyn.str + rl->dyn.real;
	rl->dyn.used = rl->dyn.real;
	rl->dyn.ante = rl->dyn.used;
	rl->dyn.post = 0;
	cur_write(rl->dyn.str, rl->dyn.ante);
	return (0);
}

int		rl_code_down(t_rl *rl)
{
	char	*str;
	size_t	len;

	if (!rl->hist_cp.cursor->n)
		return (0);
	len = rl->dyn.post;
	if (!(str = ft_strnew(len)))
		return (-1);
	if (rl->dyn.ante)
	{
		cur_go_backward(rl->dyn.ante);
		cur_from_clr();
	}
	dyn_strpoppost(&rl->dyn, str, len);
	dyn_strpushante(&rl->dyn, str, len);
	free(str);
	rl->hist_cp.cursor->content = ft_strdup(rl->dyn.str);
	rl->hist_cp.cursor->content_size = ft_strlen(rl->dyn.str) + 1;
	rl->hist_cp.cursor = rl->hist_cp.cursor->n;
	free(rl->dyn.str);
	rl->dyn.str = rl->hist_cp.cursor->content;
	rl->dyn.real = rl->hist_cp.cursor->content_size;
	rl->dyn.strend = rl->dyn.str + rl->dyn.real;
	rl->dyn.used = rl->dyn.real - 1;
	rl->dyn.ante = rl->dyn.used;
	rl->dyn.post = 0;
	cur_write(rl->dyn.str, rl->dyn.ante);
	return (0);
}

int			rl_code_pageup(t_rl *rl)
{
	char	*str;
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.ante <= co)
		return (rl_code_home(rl));
	if (!(str = ft_strnew(co)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpopante(&rl->dyn, str, co);
	dyn_strpushpost(&rl->dyn, str, co);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_up();
	return (0);
}

int			rl_code_pagedown(t_rl *rl)
{
	char	*str;
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.post <= co)
		return (rl_code_end(rl));
	if (!(str = ft_strnew(co)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpoppost(&rl->dyn, str, co);
	dyn_strpushante(&rl->dyn, str, co);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_xdo(1);
	return (0);
}

int		rl_code_end(t_rl *rl)
{
	char	*str;
	size_t	len;

	if (!(len = rl->dyn.post))
		return (0);
	if (!(str = ft_strnew(len)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpoppost(&rl->dyn, str, len);
	dyn_strpushante(&rl->dyn, str, len);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_forward(len);
	return (0);
}
