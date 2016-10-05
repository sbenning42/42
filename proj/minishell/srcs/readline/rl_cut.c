/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 09:22:04 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 18:36:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int	rl_cut_ante(t_rl *rl)
{
	if (!(rl->dyn.slct = ft_strnew(rl->dyn.slct_ante)))
		return (-1);
	dyn_strpopante(&rl->dyn, rl->dyn.slct, rl->dyn.slct_ante);
	cur_go_backward(rl->dyn.slct_ante);
	return (0);
}

static int	rl_cut_post(t_rl *rl)
{
	if (!(rl->dyn.slct = ft_strnew(rl->dyn.slct_post)))
		return (-1);
	dyn_strpoppost(&rl->dyn, rl->dyn.slct, rl->dyn.slct_post);
	return (0);
}

static int	rl_cut_line(t_rl *rl)
{
	size_t	co;
	size_t	scrco;
	size_t	len_ante;
	size_t	len_post;

	co = cur_get_co();
	scrco = cur_get_scrco() + 1;
	if (!(rl->dyn.slct = ft_strnew(scrco)))
		return (-1);
	len_ante = (co > rl->dyn.ante ? rl->dyn.ante : co);
	dyn_strpopante(&rl->dyn, rl->dyn.slct, len_ante);
	if (len_ante)
		cur_go_backward(len_ante);
	len_post = ((scrco - co) > rl->dyn.post ? rl->dyn.post : (scrco - co));
	dyn_strpoppost(&rl->dyn, rl->dyn.slct + len_ante, len_post);
	if (rl->dyn.ante)
	{
		cur_go_backward(rl->dyn.ante);
		cur_write(rl->dyn.str, rl->dyn.ante);
	}
	cur_from_clr();
	if (rl->dyn.post)
		cur_static_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
	return (0);
}

int			rl_code_cut(t_rl *rl)
{
	if (rl->dyn.slct)
		ft_memdel((void **)&rl->dyn.slct);
	if (rl->dyn.slct_post)
		return (rl_cut_post(rl));
	if (rl->dyn.slct_ante)
		return (rl_cut_ante(rl));
	return (rl_cut_line(rl));
}
