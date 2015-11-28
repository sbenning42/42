/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 10:54:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/05 12:04:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DAR2_H
# define FT_DAR2_H

# include "ft_header.h"
# include "ft_mem.h"

# define DAR2_OFFSET 32

typedef void		(*t_dar_del)(void *);

typedef struct		s_dar2
{
	void		**ar;
	size_t		size_content;
	size_t		size;
	size_t		size_max;
	t_dar_del	del;
}			t_dar2;

int			ft_dar2new(t_dar2 *dar, size_t size, t_dar_del del);
int			ft_dar2add(t_dar2 *dar, void *data);
int			ft_dar2del(t_dar2 *dar);

#endif
