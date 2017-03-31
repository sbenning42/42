/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:24:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 11:10:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label			*new_label(char *id, unsigned char offset)
{
	t_label		*label;
	size_t		size;

	if (!(label = (t_label *)ft_memalloc(sizeof(t_label))))
		return (NULL);
	size = ft_strlen(id);
	if (!(label->id = ft_strsub(id, 0, size - 1)))
	{
		free(label);
		return (NULL);
	}
	label->offset = offset;
	return (label);
}

void			add_label(t_label **label_lst, t_label *label)
{
	t_label		*drive;

	if (!*label_lst)
	{
		*label_lst = label;
		return ;
	}
	drive = *label_lst;
	while (drive->next)
		drive = drive->next;
	drive->next = label;
}

void			del_label(t_label **label)
{
	t_label		*tmp;

	while (*label)
	{
		tmp = (*label)->next;
		free((*label)->id);
		free(*label);
		*label = tmp;
	}
}

t_label			*get_label(t_label *label, char *id)
{
	while (label)
	{
		if (!ft_strcmp(id, label->id))
			return (label);
		label = label->next;
	}
	return (NULL);
}
