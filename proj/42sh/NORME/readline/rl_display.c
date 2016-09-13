/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_reset_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:47:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 12:01:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_post_display(t_rl *rl)
{
	if (rl->dyn.post)
		cur_static_write(rl->dyn.strend - rl->dyn.post, rl->dyn.post);
}

void	rl_ante_display(t_rl *rl)
{
	if (rl->dyn.ante)
	{
		cur_go_backward(rl->dyn.ante);
		cur_write(rl->dyn.str, rl->dyn.ante);
	}
}

void	rl_reset_ante_display(t_rl *rl)
{
	rl_ante_display(rl);
	cur_from_clr();
}

void	rl_reset_post_display(t_rl *rl)
{
	cur_from_clr();
	rl_post_display(rl);
}

void	rl_reset_display(t_rl *rl)
{
	rl_reset_ante_display(rl);
	rl_post_display(rl);
}
