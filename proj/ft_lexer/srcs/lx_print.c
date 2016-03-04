/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:13:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/04 19:29:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char		*g_strtype[] = {\
	"None",\
	"Blank",\
	"Word",\
	"Tok_and",\
	"Tok_or"\
};

void		lx_print(t_lex *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		ft_printf\
			("\t[{red}%zu{eoc}][{yellow}%s{eoc}][{green}%s{eoc}][{cyan}%zu{eoc}]\n",\
				i++,\
				g_strtype[lst->type],\
				lst->value,\
				lst->len\
			);
		lst = lst->next;
	}
}
