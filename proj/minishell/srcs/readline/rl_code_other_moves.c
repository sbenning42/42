/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:40:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:33:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_code_esc(t_rl *rl)
{
	rl->bitset |= RL_BS_SKIPNEXT;
	return (0);
	(void)rl;
}

int			rl_code_cle(t_rl *rl)
{
	size_t	len;

	if (!rl->dyn.slct)
		return (0);
	len = ft_strlen(rl->dyn.slct);
	dyn_strpushante(&rl->dyn, rl->dyn.slct, len);
	cur_write(rl->dyn.slct, len);
	if (!ISIN(rl->bitset, RL_BS_INSERT))
		dyn_strpoppost(&rl->dyn, NULL,\
						(len > rl->dyn.post ? rl->dyn.post : len));
	if (rl->dyn.post)
		cur_static_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
	return (0);
}

int			rl_code_del(t_rl *rl)
{
	return (0);
	(void)rl;
}
