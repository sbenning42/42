/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:05:07 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 14:26:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	skip_whitespace(char **scan)
{
	while (**scan == ' ' || **scan == '\t')
		*scan += 1;
}

static int	asm_logic(char **scan, t_lexem *lexer, t_gramm_rule *rule)
{
	if (rule->skip_whitespace)
		skip_whitespace(scan);
	return (rule->logic(rule->left, rule->right, scan, lexer));
}

static int	asm_match(char **scan, t_lexem *lexer, t_gramm_rule *rule)
{
	if (rule->skip_whitespace)
		skip_whitespace(scan);
	return (rule->match(scan, lexer));
}

int			(*g_asm_parse[])(char **, t_lexem *, t_gramm_rule *) = {\
	asm_logic,\
	asm_match\
};

int			asm_parse(char **scan, t_lexem *lexer, t_gramm_rule *rule)
{
//	ft_printf("Enter asm_parse...\n");
	return (g_asm_parse[rule->type](scan, lexer, rule));
}
