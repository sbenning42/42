/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_grammar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:46:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/27 12:17:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token					*match_open_bracket(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, '('));
}

t_token					*match_close_bracket(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, ')'));
}

t_token					*match_mult(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, '*'));
}

t_token					*match_div(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, '/'));
}

t_token					*match_add(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, '+'));
}

t_token					*match_sub(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, '-'));
}

#define SUM				0
#define PRODUCT			1
#define TERM			2
#define OP_BRACKET		3
#define OP_MULT			4
#define OP_DIV			5
#define OP_ADD			6
#define OP_SUB			7
#define NUMBER			8
#define OPEN_BRACKET	9
#define CLOSE_BRACKET	10
#define CHAR_MULT		11
#define CHAR_DIV		12
#define CHAR_ADD		13
#define CHAR_SUB		14

t_parser				g_numexpr_grammar[] = {\
	{SUM,			"SUM",					match_or,				TRUE,	{OP_ADD, OP_SUB, PRODUCT},			3},\
	{PRODUCT,		"PRODUCT",				match_or,				TRUE,	{OP_MULT, OP_DIV, TERM},			3},\
	{TERM,			"TERM",					match_or,				TRUE,	{OP_BRACKET, NUMBER},				2},\
	{OP_BRACKET,	"OP BRACKET",			match_and,				TRUE,	{OPEN_BRACKET, SUM, CLOSE_BRACKET},	3},\
	{OP_MULT,		"OP MULT",				match_and,				TRUE,	{TERM, CHAR_MULT, PRODUCT},			3},\
	{OP_DIV,		"OP DIV",				match_and,				TRUE,	{TERM, CHAR_DIV, PRODUCT},			3},\
	{OP_ADD,		"OP ADD",				match_and,				TRUE,	{PRODUCT, CHAR_ADD, SUM},			3},\
	{OP_SUB,		"OP SUB",				match_and,				TRUE,	{PRODUCT, CHAR_SUB, SUM},			3},\
	{NUMBER,		"NUMBER",				match_num,				TRUE,	{},									0},\
	{OPEN_BRACKET,	"CHAR OPEN BRACKET",	match_open_bracket,		TRUE,	{},									0},\
	{CLOSE_BRACKET,	"CHAR CLOSE BRACKET",	match_close_bracket,	TRUE,	{},									0},\
	{CHAR_MULT,		"CHAR MULT",			match_mult,				TRUE,	{},									0},\
	{CHAR_DIV,		"CHAR DIV",				match_div,				TRUE,	{},									0},\
	{CHAR_ADD,		"CHAR ADD",				match_add,				TRUE,	{},									0},\
	{CHAR_SUB,		"CHAR SUB",				match_sub,				TRUE,	{},									0}\
};
