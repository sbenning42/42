/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_p3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:36:49 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/26 16:24:10 by sbenning         ###   ########.fr       */
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

int		set_prec(t_printf_mod *mod, const char *fmt)
{
	int	n;

	n = 1;
	mod->prec = ft_atoi(++fmt);
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
