/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:13:53 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 15:46:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			logic_and(t_gramm_rule *left_rule, t_gramm_rule *right_rule,\
						char **scan, t_lexem *lexer)
{
	char	*tmp;
	int		left_ret;
	int		right_ret;

	tmp = *scan;
	left_ret = asm_parse(scan, lexer, left_rule);
	if (!left_ret)
	{
		*scan = tmp;
		return (0);
	}
	right_ret = asm_parse(scan, lexer, right_rule);
	if (!right_ret)
	{
		*scan = tmp;
		return (0);
	}
	return (1);
}

int			logic_or(t_gramm_rule *left_rule, t_gramm_rule *right_rule,\
						char **scan, t_lexem *lexer)
{
	char	*tmp;
	int		left_ret;
	int		right_ret;

	tmp = *scan;
	left_ret = asm_parse(scan, lexer, left_rule);
	right_ret = asm_parse(scan, lexer, right_rule);
	if (!left_ret && !right_ret)
	{
		*scan = tmp;
		return (0);
	}
	return (1);
}

int			logic_xor(t_gramm_rule *left_rule, t_gramm_rule *right_rule,\
						char **scan, t_lexem *lexer)
{
	char	*tmp;
	int		left_ret;
	int		right_ret;

	tmp = *scan;
	left_ret = asm_parse(scan, lexer, left_rule);
	if (left_ret)
		return (1);
	right_ret = asm_parse(scan, lexer, right_rule);
	if (right_ret)
		return (1);
	*scan = tmp;
	return (0);
}

int			logic_or_and(t_gramm_rule *left_rule, t_gramm_rule *right_rule,\
						char **scan, t_lexem *lexer)
{
	char	*tmp;
	int		right_ret;

	tmp = *scan;
	asm_parse(scan, lexer, left_rule);
	right_ret = asm_parse(scan, lexer, right_rule);
	if (!right_ret)
	{
		*scan = tmp;
		return (0);
	}
	return (1);
}

int			logic_and_or(t_gramm_rule *left_rule, t_gramm_rule *right_rule,\
						char **scan, t_lexem *lexer)
{
	char	*tmp;
	int		left_ret;

	tmp = *scan;
	left_ret = asm_parse(scan, lexer, left_rule);
	asm_parse(scan, lexer, right_rule);
	if (!left_ret)
	{
		*scan = tmp;
		return (0);
	}
	return (1);
}
