/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_gramm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:53:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 19:08:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_GRAMM_H
# define ASM_GRAMM_H

# define ASM_PARSE(X)			(g_asm_parser + X)

# define ASM_LINE				0
# define ASM_CONTENT			1
# define ASM_SINGLE_CONTENT		2
# define ASM_DOUBLE_CONTENT		3
# define ASM_COMMENT			4
# define ASM_SIGNIFICATIF		5
# define ASM_COMMAND			6
# define ASM_ID_COMMAND			7
# define ASM_LITTERAL			8
# define ASM_EXPRESSION			9
# define ASM_SINGLE_EXPRESSION	10
# define ASM_DOUBLE_EXPRESSION	11
# define ASM_LABEL				12
# define ASM_INSTRUCTION		13
# define ASM_SUITE_ARGUMENT		14
# define ASM_SEP_ARGUMENT		15
# define ASM_SEPARATOR			16
# define ASM_ARGUMENT			17
# define ASM_REG_IND			18
# define ASM_DIRECT				19
# define ASM_ARG_DIRECT			20
# define ASM_LAB_DIRECT			21
# define ASM_T_COMMENT			22
# define ASM_T_COMMAND			23
# define ASM_T_LITTERAL			24
# define ASM_T_SEPARATOR		25
# define ASM_T_DIRECT			26
# define ASM_T_LABEL			27
# define ASM_T_REGISTRE			28
# define ASM_T_INDIRECT			29
# define ASM_T_IDENTIFIER		30
# define ASM_T_WOSW_IDENTIFIER	31
# define ASM_T_SKIP_LITTERAL	32
# define ASM_T_SKIP_ALL			33
# define ASM_T_END_LINE			34

extern t_parser					g_asm_parser[];

#endif
