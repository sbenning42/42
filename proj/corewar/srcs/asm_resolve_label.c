/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_resolve_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:46:03 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/03 13:43:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					dispatch_argument(t_instruction *ins,\
										t_payload *payload, unsigned int i)
{
	if (ins->arguments_id[i] == T_REGISTRE)
		return (encode_registre(ins, payload, i));
	else if (ins->arguments_id[i] == T_INDIRECT)
		return (encode_indirect(ins, payload, i));
	else if (ins->arguments_id[i] == N_DIR_ARG)
		return (encode_direct_value(ins, payload, i));
	else if (ins->arguments_id[i] == N_DIR_LAB)
		return (encode_direct_label(ins, payload, i));
	else
		ft_printf("UNKNOW. . . [%d]\n", ins->arguments_id[i]);
	return (-1);
}

int					rec_resolve_label(t_instruction *ins, t_payload *payload)
{
	unsigned int	i;

	if (!ins)
		return (0);
	i = 0;
	while (i < ins->op->nb_arg)
	{
		if (dispatch_argument(ins, payload, i))
			return (-1);
		++i;
	}
	return (rec_resolve_label(ins->next, payload));
}

int					resolve_label(t_payload *payload)
{
	t_instruction	*drive;

	drive = payload->instruction;
	if (rec_resolve_label(drive, payload))
		return (-1);
	return (0);
}
