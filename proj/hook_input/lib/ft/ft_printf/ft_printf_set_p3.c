/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_p3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:36:49 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 15:28:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_color(int *color, const char *fmt)
{
	int	n;

	n = 0;
	while (*(fmt + ++n))
	{
		if (*(fmt + n) == '}')
			break ;
	}
	if (!*(fmt + n))
		return ;
	*color |= color_flag(++fmt);
}

int		set_prec(t_printf_mod *mod, const char *fmt, va_list ap)
{
	int	n;

	if (*++fmt == '*')
	{
		mod->prec = va_arg(ap, int);
		return (2);
	}
	mod->prec = ft_atoi(fmt);
	n = 1;
	while (ft_isdigit(*fmt++))
		n++;
	return (n);
}

int		set_width(t_printf_mod *mod, const char *fmt)
{
	int	n;

	n = 0;
	mod->width = ft_atoi(fmt);
	while (ft_isdigit(*fmt++))
		n++;
	return (n);
}

int		set_aster(t_printf_mod *mod, const char *fmt, va_list ap)
{
	int	width;

	width = va_arg(ap, int);
	if (width < 0)
	{
		mod->flag |= LADJUST;
		mod->width = -width;
	}
	else
		mod->width = width;
	return (1);
	if (fmt)
		return (1);
}
