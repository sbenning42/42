/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:42:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 11:18:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static char		*g_type[] = {\
	"TY_Word",\
	"TY_Strict_sep",\
	"TY_And_sep",\
	"TY_Or_sep",\
	"TY_Pipe",\
	"TY_Bg",\
	"TY_Stdin_redir",\
	"TY_Stdout_redir",\
	"TY_Stdin_append_redir",\
	"TY_Stdout_append_redir",\
	"TY_Stderr_redir",\
	"TY_Stderr_append_redir"\
};

char			*lx_typetostr(t_lxtype type, int plv)
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
				lx_typetostr(lst->type, lst->plv),\
				lst->value.str,\
				lst->len);
		lst = lst->next;
	}
}
