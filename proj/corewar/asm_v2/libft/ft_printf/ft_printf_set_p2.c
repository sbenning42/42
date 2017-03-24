/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:36:10 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 12:36:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_h(t_printf_mod *mod)
{
	if (mod->flag & SHORTINT)
	{
		mod->flag &= ~SHORTINT;
		mod->flag |= CHARINT;
	}
	else
		mod->flag |= SHORTINT;
	return (1);
}

int	set_l(t_printf_mod *mod)
{
	if (mod->flag & LONGINT)
	{
		mod->flag &= ~LONGINT;
		mod->flag |= LLONGINT;
	}
	else
		mod->flag |= LONGINT;
	return (1);
}

int	set_j(t_printf_mod *mod)
{
	mod->flag |= INTMAXT;
	return (1);
}

int	set_z(t_printf_mod *mod)
{
	mod->flag |= SIZET;
	return (1);
}
