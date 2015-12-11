/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:19:39 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 12:24:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_free_line(void *content, size_t size)
{
	t_lex_tk	*t;

	if (size != sizeof(t_lex_tk))
		return ;
	t = (t_lex_tk *)content;
	if (t->type == Eol)
		ft_strdel(&t->value);
}
