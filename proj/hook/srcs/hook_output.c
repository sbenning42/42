/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 22:10:01 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 15:35:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void				hk_clr_between_input(size_t size, size_t ssize)
{
	static	char	sp[2048] = INIT_SP;
	static	char	cl[2048] = INIT_CL;
	int				n;
	int				r;

	n = ((size + 2) - ssize) / 2048;
	r = ((size + 2) - ssize) % 2048;
	while (n--)
		write(1, cl, 2048);
	write(1, cl, r);
	write(1, "\033[2C", 4);
	n = size / 2048;
	r = size % 2048;
	while (n--)
		write(1, sp, 2048);
	write(1, sp, r);
	n = (size + 2) / 2048;
	r = (size + 2) % 2048;
	while (n--)
		write(1, cl, 2048);
	write(1, cl, r);
	write(1, "\033[2C", 4);
}

void				hk_output(t_hook_input *hook)
{
	static	char	cl[2048] = INIT_CL;
	static size_t	size;
	static size_t	ssize;
	size_t			len;

	if (HOOK_FLUSH)
	{
		size = 0;
		ssize = 0;
		return ;
	}
	hk_clr_between_input(size, ssize);
	len = hook->buffer.curs - *hook->buffer.acontent;
	write(1, *hook->buffer.acontent, len);
	write(1, hook->buffer.stack, ft_strlen(hook->buffer.stack));
	ssize = (*hook->buffer.acontent + hook->buffer.max) - hook->buffer.stack;
	write(1, cl, ssize);
	size = *hook->buffer.asize;
}
