/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 10:50:02 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/05 12:04:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_space(t_printf_mod *mod)
{
	if (!mod->sign)
		mod->sign = ' ';
	return (1);
}

int	set_plus(t_printf_mod *mod)
{
	mod->sign = '+';
	return (1);
}

int	set_alt(t_printf_mod *mod)
{
	mod->flag |= ALT;
	return (1);
}

int	set_minus(t_printf_mod *mod)
{
	mod->flag |= LADJUST;
	return (1);
}

int	set_zero(t_printf_mod *mod)
{
	mod->flag |= ZEROPAD;
	return (1);
}
