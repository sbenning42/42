/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyntab.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 16:38:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/31 03:43:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNTAB_H
# define DYNTAB_H

# include "libft.h"

typedef struct			s_dtab
{
	void				*data;
	const unsigned int	size;
	const char			offset[sizeof(unsigned int) * 3];
}						t_dtab;

typedef struct			s_id
{
	void				*data;
	unsigned int		size;
	unsigned int		csize;
	unsigned int		ability;
	unsigned int		offset;
}						t_id;

int						dtab_init(t_dtab *dtab, unsigned int offset,\
						unsigned int csize);
unsigned int			dtab_push(t_dtab *dtab, void *data);
void					dtab_del(t_dtab *dtab);
void					dtab_remove(t_dtab *udtab, unsigned int i);
int						dtab_insert(t_dtab *udtab, unsigned int i, void *data);
void					dtab_move(t_dtab *udtab, unsigned int old_i,\
						unsigned int i, int groupe);

#endif
