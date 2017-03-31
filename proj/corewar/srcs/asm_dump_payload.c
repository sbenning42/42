/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_payload.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:53:35 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 14:26:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				asm_dump_instruction(t_instruction *ins)
{
	unsigned int	i;

	i = 0;
	ft_printf("%s(", ins->op->id);
	while (i < ins->op->nb_arg)
	{
		ft_printf("%s%s", ins->str_arguments[i], (i + 1 == ins->op->nb_arg ? ")\n" : ", "));
		++i;
	}
	if (PI_ISOPT(proginfo()->opt, ASM_VERY_VERBOSE_OPT))
	{
		ft_printf("\t[%#04x]", ins->op->opcode);
		if (ins->ocp)
			ft_printf("[%#04x]", ins->ocp);
		else
			ft_printf("[0x00]");
		i = 0;
		while (i < ins->arg_size)
		{
			if (ins->arg_payload[i])
				ft_printf("[%#04x]", (unsigned char)ins->arg_payload[i]);
			else
				ft_printf("[0x00]");
			++i;
		}
		ft_printf("\n");
	}
}

void				asm_dump_payload(t_payload *payload)
{
	t_label			*drive;
	t_instruction	*drivi;

	drive = payload->labels;
	while (drive)
	{
		ft_printf("LABEL %s at offset %#04x\n", drive->id, drive->offset);
		drive = drive->next;
	}
	ft_printf("%s\n\n", SEPLINE);
	drivi = payload->instruction;
	while (drivi)
	{
		asm_dump_instruction(drivi);
		drivi = drivi->next;
	}
	ft_printf("\n%s\n\n", SEPLINE);
}
