/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:09:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 21:18:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void		lx_del(t_lex **alst)
{
	t_lex	*tmp;
	t_lex	*cp;

	cp = *alst;
	while (cp)
	{
		tmp = cp->next;
		if (cp->value)
			ft_memdel((void **)&cp->value);
		ft_memdel((void **)&cp);
		cp = tmp;
	}
	*alst = NULL;
}
