/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_payload.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:44:02 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 17:39:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				payload_pop_arguments(t_payload *payload, t_token **lst, int op_index)
{
	unsigned int	i;

	i = 0;
	while (i < g_op[op_index].nb_arg)
	{

		++i;
	}
	return (0);
	(void)op_index;
	(void)payload;
}

int				payload_pop_id(t_payload *payload, t_token **lst, int *op_index)
{
	int			i;

	if (!*lst)
		return (0);
	i = -1;
	while (g_op[++i].id)
	{
		if (!ft_strcmp(g_op[i].id, (*lst)->value))
		{
			*op_index = i;
			pop_token(lst);
			return (0);
		}
	}
	ft_fprintf(2, "{red|gr}Unrecognized instruction [%s]... aborting{eoc}\n", (*lst)->key);
	return (-1);
	(void)payload;
}

int				payload_pop_label(t_payload *payload, t_token **lst)
{
	t_label		*label;

	if (!(label = new_label((*lst)->value, 0)))/*TODO REPLACE 0 BY ACTUAL EXPR OFFSET*/
		return (-1);
	pop_token(lst);
	add_label(&payload->labels, label);
	return (0);
}

int				payload_pop_instruction(t_payload *payload, t_token **lst)
{
	int			op_index;

	if ((*lst)->id == N_LABEL)
	{
		if (payload_pop_label(payload, lst))
			return (-1);
	}
	if (payload_pop_id(payload, lst, &op_index))
		return (-1);
	if (payload_pop_arguments(payload, lst, &op_index))
		return (-1);
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
