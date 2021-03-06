/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:24:20 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/24 11:23:28 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define LABEL_CHAR			':'
# define SEPARATOR_CHAR		','
# define DIRECT_CHAR		'%'
# define COMMENT_CHAR		'#'
# define COMMAND_CHAR		'.'
# define LITERAL_CHAR		'"'
# define REGISTRE_CHAR		'r'
# define MINUS_CHAR			'-'
# define END_LINE_CHAR		'\0'

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

# define MAX_ARGS_NUMBER	4
# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048

# define ASM_LIVE_ID		"live"
# define ASM_LIVE_DESC		"alive"
# define ASM_LIVE_ARGS		T_DIR
# define ASM_LD_ID			"ld"
# define ASM_LD_DESC		"load"
# define ASM_LD_ARGS		T_DIR | T_IND, T_REG
# define ASM_ST_ID			"st"
# define ASM_ST_DESC		"store"
# define ASM_ST_ARGS		T_REG, T_REG | T_IND
# define ASM_ADD_ID			"add"
# define ASM_ADD_DESC		"addition"
# define ASM_ADD_ARGS		T_REG, T_REG, T_REG
# define ASM_SUB_ID			"sub"
# define ASM_SUB_DESC		"soustraction"
# define ASM_SUB_ARGS		T_REG, T_REG, T_REG
# define ASM_AND_ID			"and"
# define ASM_AND_DESC		"et (and  r1, r2, r3   r1&r2 -> r3"
# define ASM_AND_ARGS		T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG
# define ASM_OR_ID			"or"
# define ASM_OR_DESC		"ou  (or   r1, r2, r3   r1 | r2 -> r3"
# define ASM_OR_ARGS		T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG
# define ASM_XOR_ID			"xor"
# define ASM_XOR_DESC		"ou (xor  r1, r2, r3   r1^r2 -> r3"
# define ASM_XOR_ARGS		T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG
# define ASM_ZJMP_ID		"zjmp"
# define ASM_ZJMP_DESC		"jump if zero"
# define ASM_ZJMP_ARGS		T_DIR
# define ASM_LDI_ID			"ldi"
# define ASM_LDI_DESC		"load index"
# define ASM_LDI_ARGS		T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG
# define ASM_STI_ID			"sti"
# define ASM_STI_DESC		"store index"
# define ASM_STI_ARGS		T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR
# define ASM_FORK_ID		"fork"
# define ASM_FORK_DESC		"fork"
# define ASM_FORK_ARGS		T_DIR
# define ASM_LLD_ID			"lld"
# define ASM_LLD_DESC		"long load"
# define ASM_LLD_ARGS		T_DIR | T_IND, T_REG
# define ASM_LLDI_ID		"lldi"
# define ASM_LLDI_DESC		"lomg load index"
# define ASM_LLDI_ARGS		T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG
# define ASM_LFORK_ID		"lfork"
# define ASM_LFORK_DESC		"long fork"
# define ASM_LFORK_ARGS		T_DIR
# define ASM_AFF_ID			"aff"
# define ASM_AFF_DESC		"aff"
# define ASM_AFF_ARGS		T_REG

typedef char				t_arg_type;
typedef struct header_s		header_t;

struct						header_s
{
	unsigned int			magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	unsigned int			prog_size;
	char					comment[COMMENT_LENGTH + 1];
};

#endif
