/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:44:44 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/03 13:44:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_dump_header(header_t h)
{
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("{gr}%s{eoc}\n\n", SEPLINE);
	else
		ft_printf("%s\n\n", SEPLINE);
	ft_printf(header_fmt(), h.prog_name, h.comment);
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("{gr}%s{eoc}\n\n", SEPLINE);
	else
		ft_printf("%s\n\n", SEPLINE);
}
