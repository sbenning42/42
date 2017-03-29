/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:44:44 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 12:08:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		asm_dump_header(header_t h)
{
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("\n{gr}%s\n\t%s: %s\n%s{eoc}\n",\
			SEPLINE,\
			"NAME", "COMMENT",\
			SEPLINE);
	else
		ft_printf("\n%s\n\t%s: %s\n%s\n",\
			SEPLINE,\
			"NAME", "COMMENT",\
			SEPLINE);
	ft_printf(header_fmt(), h.prog_name, h.comment);
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("{gr}%s{eoc}\n", SEPLINE);
	else
		ft_printf("%s\n", SEPLINE);
}
