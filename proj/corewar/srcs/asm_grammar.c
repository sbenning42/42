/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_grammar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:16:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 18:31:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
***
***	<line>			::=	<content> <empty> ;
***	<content>		::=	<significatif> <comment> | <significatif> | <comment> ;
***	<comment>		::=	'#' ... <T_empty> ;
***	<significatif>	::=	<command> | <expression> ;
***	<command>		::=	<command_id> <litteral> ;
***	<command_id>	::=	'.'<T_id> ;
***	<litteral>		::=	'"' ... '"' ;
***	<expression>	::=	<label> <instruction> | <label> | <instruction> ;
***	<label>			::=	<T_id>':' ;
***	<instruction>	::=	<T_id> <arguments> ;
*** <arguments>		::=	<arg_separator> | <argument> ;
***	<arg_separator>	::=	<argument> ',' <arguments> ;
***	<argument>		::=	<registre> | <indirect> | <direct> ;
***	<registre>		::= 'r'<T_uint> ;
***	<indirect>		::=	<T_int> ;
*** <direct>		::= '%'<direct_arg> ;
***	<direct_arg>	::=	<direct_label> | <T_int> ;
*** <direct_label>	::=	':'<T_id> ;
***
***	T_empty			::= "" ;
***	T_uint			::= [0-9]+ ;
***	T_int			::= -?[0-9]+ ;
***	T_id			::= [a-z][a-z0-9_]* ;
***
*/

t_parser			g_asm_grammar[] = {\
	{N_DUMB,			"DUMB",				FALSE,	NULL,			match_or,				{N_LINE, T_EMPTY},							2},\
	{N_LINE,			"LINE",				FALSE,	cleanup,		match_and,				{N_CONTENT, T_EMPTY},						2},\
	{N_CONTENT,			"CONTENT",			FALSE,	NULL,			match_or,				{N_SIGNICOM, N_SIGNIFICATIF, N_COMMENT},	3},\
	{N_SIGNICOM,		"SIGNICOM",			FALSE,	NULL,			match_and,				{N_SIGNIFICATIF, N_COMMENT},				2},\
	{N_COMMENT,			"COMMENT",			FALSE,	refactor,		match_and,				{T_COMMENT, T_SKIP_EMPTY},					2},\
	{N_SIGNIFICATIF,	"SIGNIFICATIF",		FALSE,	NULL,			match_or,				{N_COMMAND, N_EXPRESSION},					2},\
	{N_COMMAND,			"COMMAND",			FALSE,	NULL,			match_and,				{N_ID_COMMAND, N_LITERAL},					2},\
	{N_ID_COMMAND,		"ID COMMAND",		FALSE,	refactor,		match_and,				{T_COMMAND, T_ID},							2},\
	{N_LITERAL,			"LITERAL",			FALSE,	refactor,		match_and,				{T_LITERAL, T_SKIP_LITERAL},				2},\
	{N_EXPRESSION,		"EXPRESSION",		FALSE,	NULL,			match_or,				{N_LABINSTR, N_LABEL, N_INSTRUCTION},		3},\
	{N_LABINSTR,		"LABINSTR",			FALSE,	NULL,			match_and,				{N_LABEL, N_INSTRUCTION},					2},\
	{N_LABEL,			"LABEL",			FALSE,	refactor,		match_and,				{T_ID, T_LABEL},							2},\
	{N_INSTRUCTION,		"INSTRUCTION",		FALSE,	NULL,			match_and,				{T_ID, N_SUITE_ARG},						2},\
	{N_SUITE_ARG,		"ARGUMENTS",		FALSE,	NULL,			match_or,				{N_SEP_ARG, N_ARGUMENT},					2},\
	{N_SEP_ARG,			"ARG SEPARATOR",	FALSE,	smart_delete,	match_and,				{N_ARGUMENT, T_SEPARATOR, N_SUITE_ARG},		3},\
	{N_ARGUMENT,		"ARGUMENT",			FALSE,	get_mask,		match_or,				{T_REGISTRE, T_INDIRECT, N_DIRECT},			3},\
	{N_DIRECT,			"DIRECT",			FALSE,	NULL,			match_or,				{N_DIR_LAB, N_DIR_ARG},						2},\
	{N_DIR_ARG,			"DIRECT VALUE",		FALSE,	refactor,		match_and,				{T_DIRECT, T_INDIRECT},						2},\
	{N_DIR_LAB,			"DIRECT LABEL",		FALSE,	refactor,		match_and,				{T_DIR_LAB, T_ID},							2},\
\
	{T_EMPTY,			"EMPTY",			TRUE,	NULL,			match_empty,			{},	0},\
	{T_COMMENT,			"CHAR COMMENT",		TRUE,	NULL,			match_comment,			{},	0},\
	{T_SKIP_EMPTY,		"SKIP EMPTY",		TRUE,	NULL,			match_skip_empty,		{},	0},\
	{T_COMMAND,			"CHAR COMMAND",		TRUE,	NULL,			match_command,			{},	0},\
	{T_ID,				"IDENTIFIER",		TRUE,	get_op,			match_id,				{},	0},\
	{T_LITERAL,			"CHAR LITERAL",		TRUE,	NULL,			match_literal,			{},	0},\
	{T_SKIP_LITERAL,	"SKIP LITERAL",		TRUE,	NULL,			match_skip_literal,		{},	0},\
	{T_LABEL,			"CHAR LABEL",		FALSE,	NULL,			match_label,			{},	0},\
	{T_SEPARATOR,		"CHAR SEPARATOR",	TRUE,	NULL,			match_separator,		{},	0},\
	{T_REGISTRE,		"REGISTRE",			TRUE,	NULL,			match_registre,			{},	0},\
	{T_INDIRECT,		"INDIRECT",			TRUE,	NULL,			match_num,				{},	0},\
	{T_DIRECT,			"CHAR DIRECT",		TRUE,	NULL,			match_direct,			{},	0},\
	{T_DIR_LAB,			"CHAR DIR LABEL",	TRUE,	NULL,			match_directlab,		{},	0}\
};
