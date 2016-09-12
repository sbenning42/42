/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:42:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/08/31 12:50:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_code_slct_right(t_rl *rl)
{
	rl->bitset |= RL_BS_SELECT;
	if (!rl->dyn.post)
		return (0);
	if (rl->dyn.slct_post)
	{
		rl->dyn.slct_post -= 1;
		cur_static_write(rl->dyn.strend - rl->dyn.post, 1);
	}
	else
	{
		rl->dyn.slct_ante += 1;
		cur_mode(M_HIGTHLIGHT);
		cur_static_write(rl->dyn.strend - rl->dyn.post, 1);
		cur_mode(M_OFF);
	}
	return (rl_code_right(rl));
}

int			rl_code_slct_left(t_rl *rl)
{
	rl->bitset |= RL_BS_SELECT;
	if (!rl->dyn.ante)
		return (0);
	rl_code_left(rl);
	if (rl->dyn.slct_ante)
	{
		rl->dyn.slct_ante -= 1;
		cur_static_write(rl->dyn.strend - rl->dyn.post, 1);
	}
	else
	{
		rl->dyn.slct_post += 1;
		cur_mode(M_HIGTHLIGHT);
		cur_static_write(rl->dyn.strend - rl->dyn.post, 1);
		cur_mode(M_OFF);
	}
	return (0);
	(void)rl;
}

int			rl_code_slct_home(t_rl *rl)
{
	size_t	tmp;

	rl->bitset |= RL_BS_SELECT;
	if (!rl->dyn.ante)
		return (0);
	if (rl->dyn.slct_ante)
	{
		tmp = rl->dyn.ante - rl->dyn.slct_ante;
		cur_go_backward(rl->dyn.slct_ante);
		cur_write(rl->dyn.str + (rl->dyn.ante - rl->dyn.slct_ante), rl->dyn.slct_ante);
		rl->dyn.slct_ante = 0;
	}
	else
		tmp = rl->dyn.ante;
	rl->dyn.slct_post += tmp;
	rl_code_home(rl);
	if (tmp)
	{
		cur_mode(M_HIGTHLIGHT);
		cur_static_write(rl->dyn.strend - rl->dyn.post, tmp);
		cur_mode(M_OFF);
	}
	return (0);
}

int			rl_code_slct_end(t_rl *rl)
{
	size_t	tmp;
	char	*str;

	rl->bitset |= RL_BS_SELECT;
	if (!rl->dyn.post)
		return (0);
	if (rl->dyn.slct_post)
	{
		tmp = rl->dyn.post - rl->dyn.slct_post;
		cur_write(rl->dyn.strend - rl->dyn.post, rl->dyn.slct_post);
		if (!(str = ft_strnew(rl->dyn.slct_post)))
			return (-1);
		dyn_strpoppost(&rl->dyn, str, rl->dyn.slct_post);
		dyn_strpushante(&rl->dyn, str, rl->dyn.slct_post);
		free(str);
		rl->dyn.slct_post = 0;
	}
	else
		tmp = rl->dyn.post;
	rl->dyn.slct_ante += tmp;
	if (tmp)
	{
		cur_mode(M_HIGTHLIGHT);
		cur_static_write(rl->dyn.strend - rl->dyn.post, tmp);
		cur_mode(M_OFF);
	}
	rl_code_end(rl);
	return (0);
}

int			rl_code_slct_pageup(t_rl *rl)
{
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.ante <= co)
		return (rl_code_slct_home(rl));
	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}

int			rl_code_slct_pagedown(t_rl *rl)
{
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.post <= co)
		return (rl_code_slct_end(rl));
	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}

int			rl_code_slct_wright(t_rl *rl)
{
	if (!rl->dyn.post)
		return (0);

	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}

int			rl_code_slct_wleft(t_rl *rl)
{
	if (!rl->dyn.ante)
		return (0);

	rl->bitset |= RL_BS_SELECT;
	return (0);
	(void)rl;
}
