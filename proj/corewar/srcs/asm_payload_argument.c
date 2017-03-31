/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_payload_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 09:35:09 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 11:19:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	get_arg_size(t_token *lst, size_t label_size)
{
	if (lst->id == T_REGISTRE)
		return (1);
	if (lst->id == T_INDIRECT)
		return (2);
	if (lst->id == N_DIR_ARG || lst->id == N_DIR_LAB)
		return (label_size);
	return (0);
}

int				asm_handle_ocp\
					(t_instruction *ins, t_token **lst, unsigned int i)
{
	if ((*((int *)((*lst)->meta)) & ins->op->args_type[i]) == 0)
	{
		argument_error(ins->op->id, i, *lst);
		return (-1);
	}
	if (ins->op->ocp)
	{
		ins->ocp <<= 0x2;
		ins->ocp |= *((int *)((*lst)->meta));
		ins->arguments_type[i] = *((int *)((*lst)->meta));
	}	
	ins->arguments_id[i] = (*lst)->id;
	return (0);
}

int				bad_argument_count(t_token **lst)
{
	return (!(*lst && (\
					(*lst)->id == T_REGISTRE\
					|| (*lst)->id == T_INDIRECT\
					|| (*lst)->id == N_DIR_LAB\
					|| (*lst)->id == N_DIR_ARG)));
}
