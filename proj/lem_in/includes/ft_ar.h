/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 10:54:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/09/21 17:05:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AR_H
# define FT_AR_H

# include "ft_header.h"

typedef struct		s_cel
{
	void			*data;
	size_t			size;
}					t_cel;

typedef struct		s_ar
{
	void			*data;
	void			*curr;
	void			*end;
	t_cel			*address;
	size_t			size;
	unsigned int	i;
}					t_ar;

void				ft_arnew(t_ar *ar);
int					ft_aradd(t_ar *ar, void *data, size_t size);
void				ft_ardel(t_ar *ar);
void				ft_ardumpi(t_ar *ar, unsigned int i);
void				ft_ardump(t_ar *ar);

#endif
