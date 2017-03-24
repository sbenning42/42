/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:57:18 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 15:47:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

typedef struct s_test	t_test;

struct					s_test
{
	char				*parser_name;
	t_gramm_rule		*parser;
	char				*str;
	int					ref_ret;
};

t_test					g_test[] = {\
	{"MINUS C",			ASM_PARSE(GR_C_MINUS),			"-",					1},\
	{"MINUS C",			ASM_PARSE(GR_C_MINUS),			"toto",					0},\
	{"IDENTIFIER",		ASM_PARSE(GR_IDENTIFIER),		"identifier_42",		1},\
	{"IDENTIFIER",		ASM_PARSE(GR_IDENTIFIER),		"_42_identifier",		1},\
	{"IDENTIFIER",		ASM_PARSE(GR_IDENTIFIER),		"42_identifier",		0},\
	{"INTEGER",			ASM_PARSE(GR_INTEGER),			"42",					1},\
	{"INTEGER",			ASM_PARSE(GR_INTEGER),			"-42",					1},\
	{"INTEGER",			ASM_PARSE(GR_INTEGER),			"-",					0},\
	{"INTEGER",			ASM_PARSE(GR_INTEGER),			"toto",					0},\
	{"INTEGER",			ASM_PARSE(GR_INTEGER),			"-toto",				0},\
	{"END_LITERAL",		ASM_PARSE(GR_END_LITERAL),		" end literal \"",		1},\
	{"END_LITERAL",		ASM_PARSE(GR_END_LITERAL),		" end literal ",		0},\
	{"S_DIRECT_LABEL",	ASM_PARSE(GR_S_DIRECT_LABEL),	"%:",					1},\
	{"S_DIRECT_LABEL",	ASM_PARSE(GR_S_DIRECT_LABEL),	"%;",					0},\
	{"S_DIRECT_LABEL",	ASM_PARSE(GR_S_DIRECT_LABEL),	"%",					0},\
	{"S_DIRECT_LABEL",	ASM_PARSE(GR_S_DIRECT_LABEL),	":",					0},\
	{"LITERAL",			ASM_PARSE(GR_LITERAL),			"\" literal 42 \"",		1},\
	{"LITERAL",			ASM_PARSE(GR_LITERAL),			"literal\" 42 ",		0},\
	{"COMMENT",			ASM_PARSE(GR_COMMENT),			"# comment 42 ",		1},\
	{"COMMENT",			ASM_PARSE(GR_COMMENT),			"    #",				1},\
	{"COMMENT",			ASM_PARSE(GR_COMMENT),			"comment 42 ",			0},\
	{"COMMAND",			ASM_PARSE(GR_COMMAND),			".name\" literal \"",	1},\
	{"COMMAND",			ASM_PARSE(GR_COMMAND),			".name  \" literal \"",	1},\
	{"COMMAND",			ASM_PARSE(GR_COMMAND),			".name",				0},\
	{"COMMAND",			ASM_PARSE(GR_COMMAND),			".name\" literal ",		0},\
	{"COMMAND",			ASM_PARSE(GR_COMMAND),			"\" literal \"",		0},\
	{"LABEL",			ASM_PARSE(GR_LABEL),			"   label:",			1},\
	{"LABEL",			ASM_PARSE(GR_LABEL),			" _42:",				1},\
	{"LABEL",			ASM_PARSE(GR_LABEL),			"42_:",					0},\
	{"LABEL",			ASM_PARSE(GR_LABEL),			"_42",					0},\
	{"LABEL",			ASM_PARSE(GR_LABEL),			":",					0},\
	{"LABEL",			ASM_PARSE(GR_LABEL),			"label :",				0},\
	{"REGISTRE",		ASM_PARSE(GR_REGISTRE),			" r42",					1},\
	{"REGISTRE",		ASM_PARSE(GR_REGISTRE),			"r0",					1},\
	{"REGISTRE",		ASM_PARSE(GR_REGISTRE),			"r",					0},\
	{"REGISTRE",		ASM_PARSE(GR_REGISTRE),			"42",					0},\
	{"REGISTRE",		ASM_PARSE(GR_REGISTRE),			"r-42",					0},\
	{"REGISTRE",		ASM_PARSE(GR_REGISTRE),			"r-0",					0},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		"%:label",				1},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		" %:_42",				1},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		"%:",					0},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		"%:42",					0},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		"_42",					0},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		":label",				0},\
	{"DIRECT_LABEL",	ASM_PARSE(GR_DIRECT_LABEL),		"%_42",					0},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		"%42",					1},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		" %-42",				1},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		"%0",					1},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		"42",					0},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		"-42",					0},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		"%",					0},\
	{"DIRECT_VALUE",	ASM_PARSE(GR_DIRECT_VALUE),		"% 42",					0},\
	{"DIRECT",			ASM_PARSE(GR_DIRECT),			" %-42",				1},\
	{"DIRECT",			ASM_PARSE(GR_DIRECT),			"%:_42",				1},\
	{"DIRECT",			ASM_PARSE(GR_DIRECT),			"-42",					0},\
	{"DIRECT",			ASM_PARSE(GR_DIRECT),			"%_42",					0},\
	{"NUMERIC_ARG",		ASM_PARSE(GR_NUMERIC_ARG),		" r42",					1},\
	{"NUMERIC_ARG",		ASM_PARSE(GR_NUMERIC_ARG),		"42",					1},\
	{"NUMERIC_ARG",		ASM_PARSE(GR_NUMERIC_ARG),		"-42",					1},\
	{"NUMERIC_ARG",		ASM_PARSE(GR_NUMERIC_ARG),		"%-42",					0},\
	{"NUMERIC_ARG",		ASM_PARSE(GR_NUMERIC_ARG),		"%:label",				0},\
	{"NUMERIC_ARG",		ASM_PARSE(GR_NUMERIC_ARG),		"identifier",			0},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"r42",					1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			" 42",					1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"-42",					1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"%42",					1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"%-42",					1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			" %:label",				1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"%:_42",				1},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"identifier",			0},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"#comment",				0},\
	{"ARGUMENT",		ASM_PARSE(GR_ARGUMENT),			"%:42",					0},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"42  ,  ",				1},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"-42,",					1},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"%42,",					1},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"%-42 , ",				1},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"r42,",					1},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"%:label,",				1},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"_42,",					0},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"-42",					0},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"%42",					0},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"%-42",					0},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		"r42",					0},\
	{"SEPARATOR",		ASM_PARSE(GR_SEPARATOR),		",r42",					0},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"42,42",				1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"42  ,  %-42",			1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"42,%:_42",				1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"r42, -42",				1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"r42, r42",				1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"%:r42 , %42",			1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"r42 , %:r42,%42",		1},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"%42",					0},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"r42,",					0},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			",r42",					0},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"r42r42",				0},\
	{"ARG_SEP",			ASM_PARSE(GR_ARG_SEP),			"42,identifier",		0},\
	{"ARG_SUITE",		ASM_PARSE(GR_ARG_SUITE),		"42",					1},\
	{"ARG_SUITE",		ASM_PARSE(GR_ARG_SUITE),		" r42",					1},\
	{"ARG_SUITE",		ASM_PARSE(GR_ARG_SUITE),		"%:r42",				1},\
	{"ARG_SUITE",		ASM_PARSE(GR_ARG_SUITE),		"r42,r42",				1},\
	{"ARG_SUITE",		ASM_PARSE(GR_ARG_SUITE),		"r42, %:r42, %42",		1},\
	{"ARG_SUITE",		ASM_PARSE(GR_ARG_SUITE),		",r42",					0},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"_42 r42",				1},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"_42 %-42",				1},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		" _42 %:r42",			1},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"_42 r42,%-42,%:label",	1},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"42 r42",				0},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"_42,r42,%-42",			0},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"_42",					0},\
	{"INSTRUCTION",		ASM_PARSE(GR_INSTRUCTION),		"%42,42",				0},\
	{"EXPRESSION",		ASM_PARSE(GR_EXPRESSION),		" label:",				1},\
	{"EXPRESSION",		ASM_PARSE(GR_EXPRESSION),		" _42 r42,%0",			1},\
	{"EXPRESSION",		ASM_PARSE(GR_EXPRESSION),		"label: _42 r42, %0",	1},\
	{"EXPRESSION",		ASM_PARSE(GR_EXPRESSION),		"42,%0",				0},\
	{"CONTENT",			ASM_PARSE(GR_CONTENT),			" label:  _42  r42 , %0",1},\
	{"CONTENT",			ASM_PARSE(GR_CONTENT),			"# comment",			1},\
	{"CONTENT",			ASM_PARSE(GR_CONTENT),			"label:     #comment",	1},\
	{"CONTENT",			ASM_PARSE(GR_CONTENT),			"_42 r12, %42 #comment ",1},\
	{"LINE",			ASM_PARSE(GR_LINE),				"_42 r12, %42 #comment",1},\
	{"LINE",			ASM_PARSE(GR_LINE),				"_42 r12, %42, #comment",0},\
	{"LINE",			ASM_PARSE(GR_LINE),				"_42 r12, identifier #comment",0},\
	{"LINE",			ASM_PARSE(GR_LINE),				"identifier",			0},\
	{"LINE",			ASM_PARSE(GR_LINE),				"label: 42,%0",			0},\
	{"LINE",			ASM_PARSE(GR_LINE),				"",						0},\
	{NULL, NULL, NULL, 0}\
};

int		main(int ac, char **av)
{
	int	i = -1;
	int	ret;
	char	*tmp;

	proginfo_init(ac, av, NULL, NULL);
	while (g_test[++i].str)
	{
		tmp = g_test[i].str;
		ret = asm_parse(&tmp, NULL, g_test[i].parser);
		if (ret != g_test[i].ref_ret)
			ft_printf("PARSE %s: res: %d, ref: %d --> test: [%s]\n", g_test[i].parser_name, ret, g_test[i].ref_ret, g_test[i].str);
	}
	return (0);
}
