/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_payload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:44:02 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 16:50:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	get_arg_size(t_token *lst, size_t label_size)
{
	if (lst->id == T_REGISTRE)
		return (1);
	if (lst->id == T_INDIRECT)
		return (2);
	if (lst->id == N_DIR_ARG)
		return (label_size);
	if (lst->id == N_DIR_LAB)
		return (label_size);
	return (0);
}

int				payload_pop_argument(t_instruction *ins, t_token **lst)
{
	unsigned int			i;

	i = 0;
	while (i < ins->op->nb_arg)
	{
		if (!*lst)
		{
			ft_printf("No enougth arguments\n");
			return (-1);
		}
		if ((*((int *)((*lst)->meta)) & ins->op->args_type[i]) == 0)
		{
			ft_fprintf(2, "Bad argument type for [%s] in instruction `%s` (%03d, %03d)\n", (*lst)->value, ins->op->id, (*lst)->position.line, (*lst)->position.column);
			return (-1);
		}
		if (ins->op->ocp)
		{
			ins->ocp <<= 0x2;
			ins->ocp |= *((int *)((*lst)->meta));
		}
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

int				payload_pop_label(t_payload *payload, t_token **lst)
{
	t_label		*label;

	if (!(label = new_label((*lst)->value, payload->size)))
		return (-1);
	pop_token(lst);
	add_label(&payload->labels, label);
	return (0);
}

int				payload_pop_instruction(t_payload *payload, t_token **lst)
{
	t_instruction	*ins;

	if ((*lst)->id == N_LABEL)
	{
		if (payload_pop_label(payload, lst))
			return (-1);
	}
	if (!(ins = new_instruction((t_op *)(*lst)->meta)))
		return (-1);
	add_instruction(&payload->instruction, ins);
	pop_token(lst);
	if (payload_pop_argument(ins, lst))
		return (-1);
	payload->size += ins->size;
	return (0);
}

int				asm_payload(t_payload *payload, t_token **lst)
{
	while (*lst)
	{
		if (payload_pop_instruction(payload, lst))
			return (-1);
	}
	return (0);
}
