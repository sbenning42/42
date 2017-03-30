/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:48:53 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 20:49:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*argument_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_ARGUMENT_CFMT\
				: ASM_ARGUMENT_FMT));
}
