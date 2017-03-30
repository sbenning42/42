/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 18:26:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:35:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					cleanup(t_parser *self, t_token **lst)
{
	t_token			*drive;
	t_token			*tmp;

	drive = *lst;
	while (drive && drive->next)
	{
		tmp = drive;
		drive = drive->next;
	}
	if (drive == *lst)
		return (0);
	del_token(&drive);
	tmp->next = NULL;
	return (0);
	(void)self;
}

int					refactor(t_parser *self, t_token **lst)
{
	char			*tmp;

	if (!(tmp = ft_strjoin((*lst)->value, (*lst)->next->value)))
		return (-1);
	(*lst)->size += (*lst)->next->size;
	del_token(&(*lst)->next);
	free((*lst)->value);
	(*lst)->value = tmp;
	(*lst)->id = self->id;
	(*lst)->key = self->key;
	if ((*lst)->meta)
	{
		free((*lst)->meta);
		(*lst)->meta = NULL;
	}
	return (0);
}

int					smart_delete(t_parser *self, t_token **lst)
{
	t_token			*smart;

	smart = (*lst)->next->next;
	(*lst)->next->next = NULL;
	del_token(&(*lst)->next);
	(*lst)->next = smart;
	return (0);
	(void)self;
}

int					get_op(t_parser *self, t_token **lst)
{
	int				i;

	i = -1;
	while (g_op[++i].id)
	{
		if (!ft_strcmp((*lst)->value, g_op[i].id))
		{
			if (!((*lst)->meta = ft_memalloc(sizeof(t_op))))
				return (-1);
			ft_memcpy((*lst)->meta, g_op + i, sizeof(t_op));
			return (0);
		}
	}
	return (0);
	(void)self;
}

int					get_mask(t_parser *self, t_token **lst)
{
	if (!((*lst)->meta = ft_memalloc(sizeof(int))))
		return (-1);
	if ((*lst)->id == T_REGISTRE)
		*(int *)((*lst)->meta) = T_REG;
	else if ((*lst)->id == T_INDIRECT)
		*(int *)((*lst)->meta) = T_IND;
	else if ((*lst)->id == N_DIR_ARG)
		*(int *)((*lst)->meta) = T_DIR;
	else if ((*lst)->id == N_DIR_LAB)
		*(int *)((*lst)->meta) = T_DIR;
	return (0);
	(void)self;
}
