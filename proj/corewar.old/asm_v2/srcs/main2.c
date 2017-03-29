/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:12:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 12:38:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main(int ac, char **av)
{
	char	*test;
	char	*tmp;

	proginfo_init(ac, av, NULL, "");

	/*TRUE COMMENT*/
	test = "#comment";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	test = "#           comment         ";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	test = "#               comment";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	test = "#";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	
	ft_printf("\n");

	/*FALSE COMMENT*/
	test = "";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	test = "comment     ";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	test = "t";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);
	test = "               ";
	tmp = test;
	ft_printf("COMMENT %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_COMMENT)), test);

	ft_printf("\n");

	/*TRUE INTEGER*/
	test = "42";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);
	test = "-42";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);
	test = "0    ";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);
	test = "-0";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);

	ft_printf("\n");

	/*FALSE INTEGER*/
	test = "- 42";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);
	test = "-a";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);
	test = "";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);
	test = "#42";
	tmp = test;
	ft_printf("INTEGER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_INTEGER)), test);

	ft_printf("\n");

	/*TRUE IDENTIFIER*/
	test = "identifier";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);
	test = "i_42";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);
	test = "_identi42fier";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);
	test = "_42";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);

	ft_printf("\n");

	/*FALSE IDENTIFIER*/
	test = "42identifier";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);
	test = "[identifier]";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);
	test = "Identi42fier";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);
	test = "-identifier";
	tmp = test;
	ft_printf("IDENTIFIER %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_IDENTIFIER)), test);

	ft_printf("\n");

	/*TRUE LABEL*/
	test = "label:";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);
	test = "_label:";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);
	test = "l_42:";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);
	test = "a:";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);

	ft_printf("\n");

	/*FALSE LABEL*/
	test = "label :";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);
	test = "42_label:";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);
	test = "l_42";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);
	test = ":";
	tmp = test;
	ft_printf("LABEL %d --> [%s]\n", asm_parse(&tmp, NULL, ASM_PARSE(GR_LABEL)), test);


	return (0);
}
