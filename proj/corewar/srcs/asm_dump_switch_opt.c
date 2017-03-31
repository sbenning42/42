/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_switch_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:03:13 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 14:36:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			dump_header(header_t header)
{
	if (PI_ISOPT(proginfo()->opt, ASM_VERBOSE_OPT))
		asm_dump_header(header);
}

void			dump_token(t_token *token)
{
	if (PI_ISOPT(proginfo()->opt, ASM_VERBOSE_OPT))
		asm_dump_token_lst(token);
}

void			dump_payload(t_payload *payload)
{
	if (PI_ISOPT(proginfo()->opt, ASM_VERY_VERBOSE_OPT))
		asm_dump_payload(payload);
}
