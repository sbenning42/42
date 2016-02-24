/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 22:10:01 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 00:10:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void				hk_clr_between_input(t_hook_input *hook, size_t size)
{
	char			ret[1024];
	char			space[1024];
	char			scape[15];
	size_t			lin;
	size_t			col;

	if (size + 2 < hook->term.col)
	{
		ft_memset(ret, '\b', size);
		write(1, ret, ft_strlen(ret));
		ft_memset(space, ' ', size);
		write(1, space, ft_strlen(space));
		write(1, ret, ft_strlen(ret));
	}
	else if (size + 2 == hook->term.col)
	{
		lin = (size + 2) / hook->term.col;
		ft_snprintf(scape, 14, "\033[%dA", 1);
		write(1, scape, ft_strlen(scape));

	}
		col = (size + 2) % hook->term.col;
		ft_memset(ret, '\b', col);
		write(1, ret, ft_strlen(ret));
	if (col >= 2)
		ft_memset(ret, '\b', col - 2);
	if (lin)
	{
		ft_memset(ret, '\b', hook->term.col - 2);
	}
	write(1, ret, col - 2);
}

void				hk_output(t_hook_input *hook)
{
	static size_t	size;

	if (HOOK_FLUSH)
	{
		size = 0;
		return ;
	}
	hk_clr_between_input(hook, size);
	write(1, *hook->buffer.acontent, hook->buffer.curs - *hook->buffer.acontent);
	write(1, hook->buffer.stack, ft_strlen(hook->buffer.stack));
	size = *hook->buffer.asize;
}
