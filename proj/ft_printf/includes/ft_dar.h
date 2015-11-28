/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 10:54:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:28:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DAR_H
# define FT_DAR_H

# include "ft_header.h"
# include "ft_printf.h"

typedef struct		s_cel
{
	void			*data;
	size_t			size;
}					t_cel;

typedef struct		s_dar
{
	void			*data;
	void			*curr;
	void			*end;
	t_cel			*address;
	size_t			size;
	unsigned int	i;
}					t_dar;

void				ft_darnew(t_dar *ar);
int					ft_daradd(t_dar *ar, void *data, size_t size);
void				ft_dardel(t_dar *ar);
void				ft_dardumpi(t_dar *ar, unsigned int i);
void				ft_dardump(t_dar *ar);

#endif
