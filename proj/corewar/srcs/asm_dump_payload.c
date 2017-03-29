/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_payload.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:53:35 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 17:25:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				asm_dump_payload(t_payload *payload)
{
	size_t			i;
	t_label			*drive;

	i = 0;
	ft_printf("Dumping payload:\n");
	ft_printf("%s\n%s\n%s\n", SEPLINE, "ADDRESS\tBYTES", SEPLINE);
	while ((i + 1) < payload->size)
	{
		ft_printf((PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
					? "%#2x%#2x%s"\
					: "{gr}%#2x%#2x%s{eoc}"),\
				payload->payload[i], payload->payload[i + 1],\
				((i % 2) ? "" : "  "));
		if (!(i % 16))
			ft_printf("\n%p\t", payload->payload + i);
		++i;
	}
	ft_printf("%s\n%zu bytes remaning. . .\n",\
			SEPLINE,\
			payload->size);
	drive = payload->labels;
	while (drive)
	{
		ft_printf("LABEL %s at offset %zu\n", drive->id, drive->offset);
		drive = drive->next;
	}
	ft_printf("%s\n", SEPLINE);
}
