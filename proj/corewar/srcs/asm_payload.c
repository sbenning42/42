/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_payload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:44:02 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/03 09:45:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					payload_pop_argument(t_instruction *ins, t_token **lst)
{
	unsigned int	i;

	i = 0;
	while (i < ins->op->nb_arg)
	{
		if (bad_argument_count(lst))
		{
			argument_count_error(ins->op->id);
			return (-1);
		}
		if (asm_handle_ocp(ins, lst, i))
			return (-1);
		ins->str_arguments[i] = ft_strdup((*lst)->value);
		ins->size += get_arg_size(*lst, ins->op->label_size);
		pop_token(lst);
		++i;
	}
	while (ins->op->ocp && i < MAX_ARGS_NUMBER)
	{
		ins->ocp <<= 0x2;
		++i;
	}
	return (0);
}

int					payload_pop_label(t_payload *payload, t_token **lst)
{
	t_label			*label;

	if (!(label = new_label((*lst)->value, payload->size)))
		return (-1);
	pop_token(lst);
	add_label(&payload->labels, label);
	return (0);
}

int					payload_pop_instruction(t_payload *payload, t_token **lst)
{
	t_instruction	*ins;

	while ((*lst) && (*lst)->id == N_LABEL)
	{
		if (payload_pop_label(payload, lst))
			return (-1);
	}
	if (!*lst)
		return (0);
	if (!(ins = new_instruction((t_op *)(*lst)->meta)))
		return (-1);
	ins->offset = payload->size;
	add_instruction(&payload->instruction, ins);
	pop_token(lst);
	if (payload_pop_argument(ins, lst))
		return (-1);
	payload->size += ins->size;
	return (0);
}

int					asm_payload(t_payload *payload, t_token **lst)
{
	if (!*lst)
		return (0);
	if (payload_pop_instruction(payload, lst))
		return (-1);
	return (asm_payload(payload, lst));
}
