/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_dump_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:06:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 14:33:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	asm_dump_token(t_token *token)
{
	ft_printf(token_fmt(),\
			token->position.line, token->position.column,\
			token->key, ((token->id == N_LABEL) ? "" : ((token->id == T_ID) ? "\t" : "\t\t")), token->value);
}

void		asm_dump_token_lst(t_token *lst)
{
//	char	*fmt;

/*	fmt = (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT)\
			? "{gr}\n%s\n(%-3s, %3s) %20s ---->\t\t| %s |\t%s\n%s{eoc}\n\n"\
			: "\n%s\n(%-3s, %3s) %20s ---->\t\t| %s |\t%s\n%s\n");
	ft_printf(fmt,\
			SEPLINE,\
			"LI", "CO",\
			"TYPE", "VALUE", "META",\
			SEPLINE);
*/	while (lst)
	{
		asm_dump_token(lst);
		lst = lst->next;
	}
	if (PI_ISOPT(proginfo()->opt, ASM_COLOR_OPT))
		ft_printf("{gr}%s{eoc}\n\n", SEPLINE);
	else
		ft_printf("%s\n\n", SEPLINE);
}
