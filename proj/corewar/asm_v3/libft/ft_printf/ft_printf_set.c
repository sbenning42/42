/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:33:40 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 14:29:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				set_fmt_mod(const char *fmt, \
				t_printf_mod *mod, t_printf_set_function *set_mod, va_list ap)
{
	const char	*cp;
	int			index;

	cp = ++fmt;
	while (*fmt)
	{
		index = get_mod_index(MOD_CSET, *fmt);
		if (index == -1)
			break ;
		fmt += set_mod[index](mod, fmt, ap);
	}
	mod->spec = *fmt;
	return (fmt - (cp - 1));
}
