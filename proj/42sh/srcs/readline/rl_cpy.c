/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 19:25:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/19 20:11:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_cpy_ante(t_rl *rl)
{
	void	*src;

	src = rl->dyn.str + (rl->dyn.ante - rl->dyn.slct_ante);
	if (!(rl->dyn.slct = ft_strnew(rl->dyn.slct_ante)))
		return (-1);
	ft_memcpy(rl->dyn.slct, src, rl->dyn.slct_ante);
	return (0);
}

int			rl_cpy_post(t_rl *rl)
{
	void	*src;

	src = rl->dyn.strend - rl->dyn.post;
	if (!(rl->dyn.slct = ft_strnew(rl->dyn.slct_post)))
		return (-1);
	ft_memcpy(rl->dyn.slct, src, rl->dyn.slct_post);
	return (0);
}

int			rl_cpy_line(t_rl *rl)
{
	void	*src;
	size_t	co;
	size_t	scrco;
	size_t	len_ante;
	size_t	len_post;

	co = cur_get_co();
	scrco = cur_get_scrco() + 1;
	if (!(rl->dyn.slct = ft_strnew(scrco)))
		return (-1);
	len_ante = (co > rl->dyn.ante ? rl->dyn.ante : co);
	src = rl->dyn.str + (rl->dyn.ante - len_ante);
	ft_memcpy(rl->dyn.slct, src, len_ante);
	len_post = ((scrco - co) > rl->dyn.post ? rl->dyn.post : (scrco - co));
	src = rl->dyn.strend - rl->dyn.post;
	ft_memcpy(rl->dyn.slct + len_ante, src, len_post);
	return (0);
}

int			rl_code_cpy(t_rl *rl)
{
	if (rl->dyn.slct)
		ft_memdel((void **)&rl->dyn.slct);
	if (rl->dyn.slct_post)
		return (rl_cpy_post(rl));
	if (rl->dyn.slct_ante)
		return (rl_cpy_ante(rl));
	return (rl_cpy_line(rl));
}
