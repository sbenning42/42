/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:24:20 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 16:20:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regexp.h"

t_parser		g_regexp_parser[] = {\
	{0, "REGEXP_ALL",\
		REGEXP_TERME, match_or, REGEXP_EXTEND, NULL, reg_pop, 0},\
	{1, "REGEXP_EXTEND",\
		REGEXP_TERME, match_and, REGEXP_ALL, NULL, reg_pop, 0},\
	{2, "REGEXP_TERME",\
		REGEXP_DESCRIPTOR, match_or, REGEXP_TERM_STATUED, NULL, reg_pop, 0},\
	{3, "REGEXP_TERM_STATUED",\
		REGEXP_DESCRIPTOR, match_and, REGEXP_STATUS, NULL, reg_pop, 0},\
	{4, "REGEXP_DESCRIPTOR",\
		REGEXP_TERMINAL_LITTERAL, match_or, REGEXP_BRACKET, NULL, reg_pop, 0},\
	{5, "REGEXP_BRACKET",\
		REGEXP_TERMINAL_OPEN_BRACKET, match_and, REGEXP_CLOSE_BRACKET, NULL, reg_pop, 0},\
	{6, "REGEXP_CLOSE_BRACKET",\
		REGEXP_SIGNED_RANGE, match_and, REGEXP_TERMINAL_CLOSE_BRACKET, NULL, reg_pop, 0},\
	{7, "REGEXP_SIGNED_RANGE",\
		REGEXP_RANGE, match_or, REGEXP_NORANGE, NULL, reg_pop, 0},\
	{8, "REGEXP_NORANGE",\
		REGEXP_TERMINAL_TILD, match_and, REGEXP_RANGE, NULL, reg_pop, 0},\
	{9, "REGEXP_RANGE",\
		REGEXP_OPEN_RANGE, match_and, REGEXP_TERMINAL_LETTER, NULL, reg_pop, 0},\
	{10, "REGEXP_OPEN_RANGE",\
		REGEXP_TERMINAL_LETTER, match_and, REGEXP_TERMINAL_MINUS, NULL, reg_pop, 0},\
	{11, "REGEXP_STATUS",\
		REGEXP_QUANTIFIER_STATUS, match_or, REGEXP_TERMINAL_INTER, NULL, reg_pop, 0},\
	{12, "REGEXP_QUANTIFIER_STATUS",\
		REGEXP_TERMINAL_PLUS, match_or, REGEXP_TERMINAL_STAR, NULL, reg_pop, 0},\
	{13, "REGEXP_TERMINAL_TILD", NULL, match_tild, NULL, reg_lexer, NULL, 0},\
	{14, "REGEXP_TERMINAL_INTER", NULL, match_inter, NULL, reg_lexer, NULL, 0},\
	{15, "REGEXP_TERMINAL_STAR", NULL, match_star, NULL, reg_lexer, NULL, 0},\
	{16, "REGEXP_TERMINAL_PLUS", NULL, match_plus, NULL, reg_lexer, NULL, 0},\
	{17, "REGEXP_TERMINAL_MINUS", NULL, match_minus, NULL, NULL, NULL, 0},\
	{18, "REGEXP_TERMINAL_OPEN_BRACKET", NULL, match_open_bracket, NULL, NULL, NULL, 0},\
	{19, "REGEXP_TERMINAL_CLOSE_BRACKET", NULL, match_close_bracket, NULL, NULL, NULL, 0},\
	{20, "REGEXP_TERMINAL_LETTER", NULL, match_letter, NULL, reg_lexer, NULL, 0},\
	{21, "REGEXP_TERMINAL_LITTERAL", NULL, match_litteral, NULL, reg_lexer, NULL, 0}\
};
