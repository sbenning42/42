/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:06:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 12:08:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_dump_token(t_token *token)
{
	ft_printf(token_fmt(),\
			token->position.line, token->position.column,\
			token->key, token->value);
}

void		asm_dump_token_lst(t_token *lst)
{
	char	*fmt;

	fmt = (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
			? "{gr}\n%s\n(%-3s, %3s) %20s ---->\t\t| %s |\n%s{eoc}\n\n"\
			: "\n%s\n(%-3s, %3s) %20s ---->\t\t| %s |\n%s\n");
	ft_printf(fmt,\
			SEPLINE,\
			"LI", "CO",\
			"TYPE", "VALUE",\
			SEPLINE);
	while (lst)
	{
		asm_dump_token(lst);
		lst = lst->next;
	}
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("{gr}%s{eoc}\n", SEPLINE);
	else
		ft_printf("%s\n", SEPLINE);
}
