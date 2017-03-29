/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_gramm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 09:15:52 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 15:58:29 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_gramm_rule	G_ASM_GRAMM[] = {\
/*C_MINUS*/			{gt_match, match_c_minus,		NULL, NULL, NULL, 0},\
/*C_COMMENT*/		{gt_match, match_c_comment,		NULL, NULL, NULL, 0},\
/*C_COMMAND*/		{gt_match, match_c_command,		NULL, NULL, NULL, 1},\
/*C_LABEL*/			{gt_match, match_c_label,		NULL, NULL, NULL, 0},\
/*C_SEPARATOR*/		{gt_match, match_c_separator,	NULL, NULL, NULL, 1},\
/*C_DIRECT*/		{gt_match, match_c_direct,		NULL, NULL, NULL, 1},\
/*C_REGISTRE*/		{gt_match, match_c_registre,	NULL, NULL, NULL, 0},\
/*C_LITERAL*/		{gt_match, match_c_literal,		NULL, NULL, NULL, 1},\
/*C_END_LINE*/		{gt_match, match_c_end_line,	NULL, NULL, NULL, 0},\
/*IDENTIFIER*/		{gt_match, match_identifier,	NULL, NULL, NULL, 0},\
/*UINTEGER*/		{gt_match, match_uinteger,		NULL, NULL, NULL, 0},\
/*END_LITERAL*/		{gt_match, match_end_literal,	NULL, NULL, NULL, 0},\
/*S_DIRECT_LABEL*/	{gt_logic, NULL, logic_and, ASM_PARSE(GR_C_DIRECT), ASM_PARSE(GR_C_LABEL), 1},\
/*S_COMMAND*/		{gt_logic, NULL, logic_and, ASM_PARSE(GR_C_COMMAND), ASM_PARSE(GR_IDENTIFIER), 1},\
/*INTEGER*/			{gt_logic, NULL, logic_or_and, ASM_PARSE(GR_C_MINUS), ASM_PARSE(GR_UINTEGER), 0},\
/*LITERAL*/			{gt_logic, NULL, logic_and, ASM_PARSE(GR_C_LITERAL), ASM_PARSE(GR_END_LITERAL), 1},\
/*COMMENT*/			{gt_logic, NULL, logic_and_or, ASM_PARSE(GR_C_COMMENT), ASM_PARSE(GR_C_END_LINE), 1},\
/*COMMAND*/			{gt_logic, NULL, logic_and, ASM_PARSE(GR_S_COMMAND), ASM_PARSE(GR_LITERAL), 1},\
/*LABEL*/			{gt_logic, NULL, logic_and, ASM_PARSE(GR_IDENTIFIER), ASM_PARSE(GR_C_LABEL), 1},\
/*REGISTRE*/		{gt_logic, NULL, logic_and, ASM_PARSE(GR_C_REGISTRE), ASM_PARSE(GR_UINTEGER), 1},\
/*DIRECT_LABEL*/	{gt_logic, NULL, logic_and, ASM_PARSE(GR_S_DIRECT_LABEL), ASM_PARSE(GR_IDENTIFIER), 1},\
/*DIRECT_VALUE*/	{gt_logic, NULL, logic_and, ASM_PARSE(GR_C_DIRECT), ASM_PARSE(GR_INTEGER), 1},\
/*DIRECT*/			{gt_logic, NULL, logic_xor, ASM_PARSE(GR_DIRECT_LABEL), ASM_PARSE(GR_DIRECT_VALUE), 1},\
/*NUMERIC_ARG*/		{gt_logic, NULL, logic_xor, ASM_PARSE(GR_REGISTRE), ASM_PARSE(GR_INTEGER), 1},\
/*ARGUMENT*/		{gt_logic, NULL, logic_xor, ASM_PARSE(GR_DIRECT), ASM_PARSE(GR_NUMERIC_ARG), 1},\
/*SEPARATOR*/		{gt_logic, NULL, logic_and, ASM_PARSE(GR_ARGUMENT), ASM_PARSE(GR_C_SEPARATOR), 1},\
/*ARG_SEP*/			{gt_logic, NULL, logic_and, ASM_PARSE(GR_SEPARATOR), ASM_PARSE(GR_ARG_SUITE), 1},\
/*ARG_SUITE*/		{gt_logic, NULL, logic_xor, ASM_PARSE(GR_ARG_SEP), ASM_PARSE(GR_ARGUMENT), 1},\
/*INSTRUCTION*/		{gt_logic, NULL, logic_and, ASM_PARSE(GR_IDENTIFIER), ASM_PARSE(GR_ARG_SUITE), 1},\
/*EXPRESSION*/		{gt_logic, NULL, logic_or, ASM_PARSE(GR_LABEL), ASM_PARSE(GR_INSTRUCTION), 1},\
/*EXT_EXPRESSION*/	{gt_logic, NULL, logic_xor, ASM_PARSE(GR_EXPRESSION), ASM_PARSE(GR_COMMAND), 1},\
/*CONTENT*/			{gt_logic, NULL, logic_or, ASM_PARSE(GR_EXT_EXPRESSION), ASM_PARSE(GR_COMMENT), 1},\
/*LINE*/			{gt_logic, NULL, logic_and, ASM_PARSE(GR_CONTENT), ASM_PARSE(GR_C_END_LINE), 1}\
};
