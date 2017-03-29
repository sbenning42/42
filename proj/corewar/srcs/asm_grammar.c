/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_grammar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:16:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 10:22:21 by sbenning         ###   ########.fr       */
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

t_token					*match_comment(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, COMMENT_CHAR));
}

t_token					*match_command(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, COMMAND_CHAR));
}

t_token					*match_literal(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, '"'));
}

t_token					*match_label(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, LABEL_CHAR));
}

t_token					*match_separator(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, SEPARATOR_CHAR));
}

t_token					*match_direct(t_parser *self, char **scan, void *data)
{
	return (match_char(self, scan, data, DIRECT_CHAR));
}

t_token		*match_directlab(t_parser *self, char **scan, void *data)
{
	t_token	*token;

	if (**scan != DIRECT_CHAR || *((*scan) + 1) != LABEL_CHAR)
		return (NULL);
	if (!(token = new_token(self->id, *scan, 2, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	*scan += 2;
	inc_co_position(2);
	return (token);
	(void)data;
}

t_token		*match_registre(t_parser *self, char **scan, void *data)
{
	t_token	*token;
	size_t	i;

	if (**scan != 'r')
		return (NULL);
	i = 1;
	while (ft_isdigit((*scan)[i]))
		++i;
	if (!(token = new_token(self->id, *scan, i, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	*scan += i;
	inc_co_position(i);
	return (token);
	(void)data;
}

t_token					*match_skip_literal(t_parser *self, char **scan, void *data)
{
	t_token	*token;
	size_t	i;

	i = 0;
	while ((*scan)[i] && (*scan)[i] != '"')
		++i;
	if (!(*scan)[i])
		return (NULL);
	++i;
	if (!(token = new_token(self->id, *scan, i, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	*scan += i;
	inc_co_position(i);
	return (token);
	(void)data;
}

t_token					*match_skip_empty(t_parser *self, char **scan, void *data)
{
	t_token	*token;

	while (**scan)
		*scan += 1;
	if (!(token = new_token(self->id, *scan, 1, *single_position())))
		return (NULL);
	token->id = self->id;
	token->key = self->key;
	return (token);
	(void)data;
}

t_token					*match_empty(t_parser *self, char **scan, void *data)
{
	t_token	*token;

	if (!**scan)
	{
		if (!(token = new_token(self->id, *scan, 1, *single_position())))
		{
			ft_fprintf(2, "MALLOC ERROR\n");
			return (NULL);
		}
		token->id = self->id;
		token->key = self->key;
		return (token);
	}
	return (NULL);
	(void)data;
}

int					cleanup(t_parser *self, t_token **lst)
{
	t_token			*drive;
	t_token			*tmp;

	drive = *lst;
	while (drive && drive->next)
	{
		tmp = drive;
		drive = drive->next;
	}
	if (drive == *lst)
		return (0);
	del_token(&drive);
	tmp->next = NULL;
	return (0);
	(void)self;
}

int					refactor(t_parser *self, t_token **lst)
{
	char			*tmp;

	if (!(tmp = ft_strjoin((*lst)->value, (*lst)->next->value)))
		return (-1);
	(*lst)->size += (*lst)->next->size;
	del_token(&(*lst)->next);
	free((*lst)->value);
	(*lst)->value = tmp;
	(*lst)->id = self->id;
	(*lst)->key = self->key;
	return (0);
}

int					smart_delete(t_parser *self, t_token **lst)
{
	t_token			*smart;

	smart = (*lst)->next->next;
	(*lst)->next->next = NULL;
	del_token(&(*lst)->next);
	(*lst)->next = smart;
	return (0);
	(void)self;
}

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
	{N_ARGUMENT,		"ARGUMENT",			FALSE,	NULL,			match_or,				{T_REGISTRE, T_INDIRECT, N_DIRECT},			3},\
	{N_DIRECT,			"DIRECT",			FALSE,	NULL,			match_or,				{N_DIR_LAB, N_DIR_ARG},						2},\
	{N_DIR_ARG,			"DIRECT VALUE",		FALSE,	refactor,		match_and,				{T_DIRECT, T_INDIRECT},						2},\
	{N_DIR_LAB,			"DIRECT LABEL",		FALSE,	refactor,		match_and,				{T_DIR_LAB, T_ID},							2},\
\
	{T_EMPTY,			"EMPTY",			TRUE,	NULL,			match_empty,			{},	0},\
	{T_COMMENT,			"CHAR COMMENT",		TRUE,	NULL,			match_comment,			{},	0},\
	{T_SKIP_EMPTY,		"SKIP EMPTY",		TRUE,	NULL,			match_skip_empty,		{},	0},\
	{T_COMMAND,			"CHAR COMMAND",		TRUE,	NULL,			match_command,			{},	0},\
	{T_ID,				"IDENTIFIER",		TRUE,	NULL,			match_id,				{},	0},\
	{T_LITERAL,			"CHAR LITERAL",		TRUE,	NULL,			match_literal,			{},	0},\
	{T_SKIP_LITERAL,	"SKIP LITERAL",		TRUE,	NULL,			match_skip_literal,		{},	0},\
	{T_LABEL,			"CHAR LABEL",		FALSE,	NULL,			match_label,			{},	0},\
	{T_SEPARATOR,		"CHAR SEPARATOR",	TRUE,	NULL,			match_separator,		{},	0},\
	{T_REGISTRE,		"REGISTRE",			TRUE,	NULL,			match_registre,			{},	0},\
	{T_INDIRECT,		"INDIRECT",			TRUE,	NULL,			match_num,				{},	0},\
	{T_DIRECT,			"CHAR DIRECT",		TRUE,	NULL,			match_direct,			{},	0},\
	{T_DIR_LAB,			"CHAR DIR LABEL",	TRUE,	NULL,			match_directlab,		{},	0}\
};
