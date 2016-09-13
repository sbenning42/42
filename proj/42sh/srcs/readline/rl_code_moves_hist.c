/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_moves_hist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:39:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:46:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	rl_up_majrl(t_rl *rl)
{
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
}

static void	rl_down_majrl(t_rl *rl)
{
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
}

int			rl_code_up(t_rl *rl)
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
	rl_up_majrl(rl);
	cur_write(rl->dyn.str, rl->dyn.ante);
	return (0);
}

int			rl_code_down(t_rl *rl)
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
	rl_down_majrl(rl);
	cur_write(rl->dyn.str, rl->dyn.ante);
	return (0);
}
