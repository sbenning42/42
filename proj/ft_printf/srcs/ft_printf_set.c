/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:33:40 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 12:34:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				set_fmt_mod(const char *fmt, \
				t_printf_mod *mod, t_printf_set_function *set_mod)
{
	const char	*cp;
	int			index;

	cp = ++fmt;
	while (*fmt)
	{
		index = MOD__(*fmt);
		if (index == -1)
			break ;
		fmt += set_mod[index](mod, fmt);
	}
	mod->spec = *fmt;
	return (fmt - (cp - 1));
}
