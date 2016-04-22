/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:42:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 14:01:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static char		*g_type[] = {\
	"TY_Word",\
	"TY_Neg",\
	"TY_Case",\
	"TY_Coproc",\
	"TY_Do",\
	"TY_Done",\
	"TY_Elif",\
	"TY_Else",\
	"TY_Esac",\
	"TY_Fi",\
	"TY_For",\
	"TY_Function",\
	"TY_If",\
	"TY_In",\
	"TY_Select",\
	"TY_Then",\
	"TY_Until",\
	"TY_While",\
	"TY_Bracket_open",\
	"TY_Bracket_close",\
	"TY_Time",\
	"TY_Hook_open",\
	"TY_Hook_close"\
};

static char		*static_lx_typetostr(t_lxtype type, int plv)
{
	static char	buff[1024];

	ft_bzero((void *)buff, 1024);
	ft_strcpy(buff, g_type[type]);
	if (ISBIT(plv, LX_PLVDQUOTE))
		ft_strcat(buff, "--Dquoted");
	if (ISBIT(plv, LX_PLVQUOTE))
		ft_strcat(buff, "--Quoted");
	return (buff);
}

#define LX_NOWORD "\t[{pink|ss}%s{eoc}][{cyan}%s{eoc}][{yellow}%zu{eoc}]\n"
#define LX_WORD "\t[{red|ss}%s{eoc}][{cyan}%s{eoc}][{yellow}%zu{eoc}]\n"

void			lx_print(t_lxem *lst)
{
	char		*format;

	while (lst)
	{
		if (lst->type > TY_Word)
			format = LX_NOWORD;
		else
			format = LX_WORD;
		ft_printf(format,\
				static_lx_typetostr(lst->type, lst->plv),\
				lst->value.str,\
				lst->len\
				);
		lst = lst->next;
	}
}
