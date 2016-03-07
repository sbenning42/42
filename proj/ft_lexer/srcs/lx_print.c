/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:42:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 13:52:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static char		*g_type[] = {\
	"TY_Word"\
};

static char		*static_lx_typetostr(t_lxtype type, int plv)
{
	static char	buff[1024];

	ft_bzero((void *)buff, 1024);
	ft_strcpy(buff, g_type[type]);
	if (ISBIT(plv, LX_PLVESCAPE))
		ft_strcat(buff, "--Escaped");
	if (ISBIT(plv, LX_PLVQUOTE))
		ft_strcat(buff, "--Quoted");
	if (ISBIT(plv, LX_PLVDQUOTE))
		ft_strcat(buff, "--Dquoted");
	return (buff);
}

void	lx_print(t_lxem *lst)
{
	while (lst)
	{
		ft_printf("\t[{red|ss}%s{eoc}][{cyan}%s{eoc}][{yellow}%zu{eoc}]\n",\
				static_lx_typetostr(lst->type, lst->plv),\
				lst->value.str,\
				lst->len\
				);
		lst = lst->next;
	}
}
