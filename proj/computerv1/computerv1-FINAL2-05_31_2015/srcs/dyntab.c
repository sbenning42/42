/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:45:29 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 09:51:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dyntab.h"

int				dtab_init(t_dtab *udtab, unsigned int offset,\
				unsigned int csize)
{
	t_id		*dtab;

	dtab = (t_id *)udtab;
	if (!(dtab->data = ft_memalloc(csize * (offset + 1))))
		return (-1);
	ft_bzero(dtab->data, dtab->csize * offset + 1);
	dtab->ability = offset;
	dtab->offset = offset;
	dtab->csize = csize;
	dtab->size = 0;
	return (8);
}

unsigned int	dtab_push(t_dtab *udtab, void *data)
{
	t_id		*dtab;
	void		*tmp;

	dtab = (t_id *)udtab;
	if (dtab->size == dtab->ability)
	{
		tmp = dtab->data;
		if (!(dtab->data = (void *)ft_memalloc(dtab->csize *\
						(dtab->ability + dtab->offset + 1))))
		{
			ft_bzero(&tmp, dtab->csize * dtab->size);
			ft_memdel(&tmp);
			return (0);
		}
		ft_memcpy(dtab->data, tmp, dtab->csize * dtab->size);
		dtab->ability = dtab->ability + dtab->offset;
	}
	ft_memcpy(dtab->data + dtab->size * dtab->csize, data, dtab->csize);
	dtab->size = dtab->size + 1;
	return (dtab->size);
}
/*
void			dtab_move(t_dtab *udtab, unsigned int old_i,\
				unsigned int i, int groupe)
{
	t_id		*dtab;
	char		tmp[((t_id *)udtab)->csize * groupe];
	char		tmp2[((t_id *)udtab)->csize * (((t_id *)udtab)->size - i)];

	dtab = (t_id *)udtab;
	ft_memcpy(&tmp, &dtab->data[dtab->csize * old_i],\
			dtab->csize * groupe);
	ft_memcpy(&dtab->data[dtab->csize * old_i],\
			&dtab->data[dtab->csize * old_i +\
			(dtab->csize * groupe)],\
			(dtab->size - old_i - groupe) * dtab->csize);
	ft_memcpy(tmp2, &dtab->data[dtab->csize * i],\
			(dtab->size - i - groupe) * dtab->csize);
	ft_memcpy(&dtab->data[dtab->csize * i],\
			tmp, dtab->csize * groupe);
	ft_memcpy(&dtab->data[dtab->csize * (i + groupe)],\
			tmp2, (dtab->size - (i + groupe)) * dtab->csize);
}
*/
int					dtab_insert(t_dtab *udtab, unsigned int i, void *data)
{
	t_id			*dtab;
	void			*tmp;
	void			*tmp2;

	dtab = (t_id *)udtab;
	if (dtab->size == dtab->ability)
	{
		tmp = dtab->data;
		if (!(dtab->data = (void *)ft_memalloc(dtab->csize *\
						(dtab->ability + dtab->offset + 1))))
		{
			ft_bzero(&tmp, dtab->csize * dtab->size);
			ft_memdel(&tmp);
			return (0);
		}
		ft_memcpy(dtab->data, tmp, dtab->csize * dtab->size);
		ft_memdel(&tmp);
		dtab->ability = dtab->ability + dtab->offset;
	}
	tmp2 = malloc((dtab->size - i) * dtab->csize);
	ft_memcpy(tmp2, dtab->data + (dtab->csize * i) , (dtab->size - i) * dtab->csize);
	ft_memcpy(dtab->data + (dtab->csize * i), data, dtab->csize);
	ft_memcpy(dtab->data + (dtab->csize * (i + 1)), tmp2, dtab->csize * (dtab->size - i));
	ft_memdel(&tmp2);
	dtab->size++;
	return (42);
}

void			dtab_remove(t_dtab *udtab, unsigned int i)
{
	t_id		*dtab;
	void		*tmp;

	dtab = (t_id *)udtab;
	tmp = dtab->data + (dtab->csize * (i + 1));
	ft_memcpy(dtab->data + (dtab->csize * i), tmp, dtab->csize * (dtab->size - (i + 1)));
	dtab->size--;
	ft_bzero(dtab->data + (dtab->csize * dtab->size), dtab->csize);
}

void			dtab_del(t_dtab *udtab)
{
	t_id		*dtab;

	dtab = (t_id *)udtab;
	ft_bzero(dtab->data, dtab->csize * dtab->size);
	ft_memdel((void **)&dtab->data);
	ft_bzero(dtab, sizeof(t_dtab));
}
