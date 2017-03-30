/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_payload.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:53:35 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:43:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				asm_dump_instruction(t_instruction *ins)
{
	unsigned int	i;

	i = 0;
	ft_printf("[%#2x][%#2x]--[%zu] --> ",\
			ins->op->opcode, ins->ocp, ins->size);
	while (i < ins->op->nb_arg)
	{
		ft_printf("[%s]", ins->str_arguments[i]);
		++i;
	}
	ft_printf("\n");
}

void				asm_dump_payload(t_payload *payload)
{
	t_label			*drive;
	t_instruction	*drivi;

	ft_printf("Dumping payload:\n");
	ft_printf("%s\n%s\n%s\n", SEPLINE, "ADDRESS\tBYTES", SEPLINE);
	ft_printf("%s\n%zu bytes remaning. . .\n",\
		SEPLINE,\
		payload->size);
	drive = payload->labels;
	while (drive)
	{
		ft_printf("LABEL %s at offset %zu\n", drive->id, drive->offset);
		drive = drive->next;
	}
	drivi = payload->instruction;
	while (drivi)
	{
		asm_dump_instruction(drivi);
		drivi = drivi->next;
	}
	ft_printf("%s\n", SEPLINE);
}
