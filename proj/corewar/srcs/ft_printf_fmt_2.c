/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:48:53 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 08:36:00 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*argument_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_ARGUMENT_CFMT\
				: ASM_ARGUMENT_FMT));
}

char			*argument_count_fmt(void)
{
	return ((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
				? ASM_C_ARGUMENT_CFMT\
				: ASM_C_ARGUMENT_FMT));
}
