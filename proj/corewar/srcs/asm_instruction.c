/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 14:35:49 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 15:16:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instruction		*new_instruction(t_op *op)
{
	t_instruction	*ins;

	if (!(ins = ft_memalloc(sizeof(t_instruction))))
		return (NULL);
	ins->op = op;
	ins->size = 1 + op->ocp;
	return (ins);
}

void				add_instruction(t_instruction **lst, t_instruction *ins)
{
	t_instruction	*drive;

	if (!*lst)
	{
		*lst = ins;
		return ;
	}
	drive = *lst;
	while (drive->next)
		drive = drive->next;
	drive->next = ins;
}

void				del_instruction(t_instruction **lst)
{
	t_instruction	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
