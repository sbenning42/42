/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_gramm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:54:34 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 19:41:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
***	#############################	BNF	########################################
***
***	<line>			::= <content> "";
***	<content>		::= <comment> | <significative> | <significative> <comment>;
*** <comment>		::= '#' <skip_all> "";
*** <significative>	::= <expression> | <command>;
***	<command>		::= '.'<identifier> <litteral>;
*** <litteral>		::=	'"' <skip_quote> '"';
***	<expression>	::= <instruction> | <label> | <label> <instruction>;
***	<instruction>	::=	<identifier> <arguments>;
*** <arguments>		::= <argument> | <argument> ',' <arguments>;
*** <argument>		::= <registre> | <direct> | <indirect>;
*** <direct>		::=	'%'<direct_label> | '%'<indirect>;
***	<direct_label>	::=	':'<identifier>;
***	<label>			::= <identifier>':';
***
***	############################	TERMINAUX	###############################
***
***	<skip_all>		::= ![~\0]*! ;
***	<skip_quote>	::= ![~\0"]*! ;
***	<registre>		::= !r[0-9]+! ;
*** <indirect>		::= !-?[0-9]+! ;
*** <identifier>	::=	![A-Z|a-z][A-Z|a-z|0-9|_]*! ;
***
*/

t_parser		g_asm_parser[] = {\
	{0,		"ASM_LINE",					ASM_PARSE(ASM_CONTENT),				match_and,				ASM_PARSE(ASM_T_END_LINE),			NULL, NULL, FALSE},\
	{1,		"ASM_CONTENT",				ASM_PARSE(ASM_SINGLE_CONTENT),		match_or,				ASM_PARSE(ASM_DOUBLE_CONTENT),		NULL, NULL, FALSE},\
	{2,		"ASM_SINGLE_CONTENT",		ASM_PARSE(ASM_COMMENT),				match_or,				ASM_PARSE(ASM_SIGNIFICATIF),		NULL, NULL, FALSE},\
	{3,		"ASM_DOUBLE_CONTENT", 		ASM_PARSE(ASM_SIGNIFICATIF),		match_and,				ASM_PARSE(ASM_COMMENT),				NULL, NULL, FALSE},\
	{4,		"ASM_COMMENT",				ASM_PARSE(ASM_T_COMMENT),			match_and,				ASM_PARSE(ASM_T_SKIP_ALL),			NULL, NULL, FALSE},\
	{5,		"ASM_SIGNIFICATIF",			ASM_PARSE(ASM_EXPRESSION),			match_or,				ASM_PARSE(ASM_COMMAND),				NULL, NULL, FALSE},\
	{6,		"ASM_COMMAND",				ASM_PARSE(ASM_ID_COMMAND),			match_and,				ASM_PARSE(ASM_LITTERAL),			NULL, NULL, FALSE},\
	{7,		"ASM_ID_COMMAND",			ASM_PARSE(ASM_T_COMMAND),			match_and,				ASM_PARSE(ASM_T_IDENTIFIER),		NULL, NULL, FALSE},\
	{8,		"ASM_LITTERAL",				ASM_PARSE(ASM_T_LITTERAL),			match_and,				ASM_PARSE(ASM_T_SKIP_LITTERAL),		NULL, NULL, FALSE},\
	{9,		"ASM_EXPRESSION",			ASM_PARSE(ASM_SINGLE_EXPRESSION),	match_or,				ASM_PARSE(ASM_DOUBLE_EXPRESSION),	NULL, NULL, FALSE},\
	{10,	"ASM_SINGLE_EXPRESSION",	ASM_PARSE(ASM_INSTRUCTION),			match_or,				ASM_PARSE(ASM_LABEL),				NULL, NULL, FALSE},\
	{11,	"ASM_DOUBLE_EXPRESSION",	ASM_PARSE(ASM_LABEL),				match_and,				ASM_PARSE(ASM_INSTRUCTION),			NULL, NULL, FALSE},\
	{12,	"ASM_LABEL",				ASM_PARSE(ASM_T_IDENTIFIER),		match_and,				ASM_PARSE(ASM_T_LABEL),				NULL, NULL, FALSE},\
	{13,	"ASM_INSTRUCTION",			ASM_PARSE(ASM_T_IDENTIFIER),		match_and,				ASM_PARSE(ASM_SUITE_ARGUMENT),		NULL, NULL, FALSE},\
	{14,	"ASM_SUITE_ARGUMENT",		ASM_PARSE(ASM_ARGUMENT),			match_or,				ASM_PARSE(ASM_SEP_ARGUMENT),		NULL, NULL, FALSE},\
	{15,	"ASM_SEP_ARGUMENT",			ASM_PARSE(ASM_ARGUMENT),			match_and,				ASM_PARSE(ASM_SEPARATOR),			NULL, NULL, FALSE},\
	{16,	"ASM_SEPARATOR",			ASM_PARSE(ASM_T_SEPARATOR),			match_and,				ASM_PARSE(ASM_SUITE_ARGUMENT),		NULL, NULL, FALSE},\
	{17,	"ASM_ARGUMENT",				ASM_PARSE(ASM_DIRECT),				match_or,				ASM_PARSE(ASM_REG_IND),				NULL, NULL, FALSE},\
	{18,	"ASM_REG_IND",				ASM_PARSE(ASM_T_REGISTRE),			match_or,				ASM_PARSE(ASM_T_INDIRECT),			NULL, NULL, FALSE},\
	{19,	"ASM_DIRECT",				ASM_PARSE(ASM_T_DIRECT),			match_and,				ASM_PARSE(ASM_ARG_DIRECT),			NULL, NULL, FALSE},\
	{20,	"ASM_ARG_DIRECT",			ASM_PARSE(ASM_LAB_DIRECT),			match_or,				ASM_PARSE(ASM_T_INDIRECT),			NULL, NULL, FALSE},\
	{21,	"ASM_LAB_DIRECT",			ASM_PARSE(ASM_T_LABEL),				match_and,				ASM_PARSE(ASM_T_WOSW_IDENTIFIER),	NULL, NULL, FALSE},\
	{22,	"ASM_T_COMMENT",			NULL,								match_t_comment,		NULL,								NULL, NULL, TRUE},\
	{23,	"ASM_T_COMMAND",			NULL,								match_t_command,		NULL,								NULL, NULL, TRUE},\
	{24,	"ASM_T_LITTERAL",			NULL,								match_t_litteral,		NULL,								NULL, NULL, TRUE},\
	{25,	"ASM_T_SEPARATOR",			NULL,								match_t_separator,		NULL,								NULL, NULL, TRUE},\
	{26,	"ASM_T_DIRECT",				NULL,								match_t_direct,			NULL,								NULL, NULL, TRUE},\
	{27,	"ASM_T_LABEL",				NULL,								match_t_label,			NULL,								NULL, NULL, FALSE},\
	{28,	"ASM_T_REGISTRE",			NULL,								match_t_registre,		NULL,								NULL, NULL, TRUE},\
	{29,	"ASM_T_INDIRECT",			NULL,								match_t_indirect,		NULL,								NULL, NULL, TRUE},\
	{30,	"ASM_T_IDENTIFIER",			NULL,								match_t_identifier,		NULL,								NULL, NULL, TRUE},\
	{31,	"ASM_T_WOSW_IDENTIFIER",	NULL,								match_t_identifier,		NULL,								NULL, NULL, FALSE},\
	{32,	"ASM_T_SKIP_LITTERAL",		NULL,								match_t_skip_litteral,	NULL,								NULL, NULL, FALSE},\
	{33,	"ASM_T_SKIP_ALL",			NULL,								match_t_skip_all,		NULL,								NULL, NULL, TRUE},\
	{34,	"ASM_T_END_LINE",			NULL,								match_t_end_line,		NULL,								NULL, NULL, TRUE}\
};
