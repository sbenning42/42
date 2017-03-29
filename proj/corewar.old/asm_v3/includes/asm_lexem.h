/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lexem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 11:15:56 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 12:03:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_LEXEM_H
# define ASM_LEXEM_H

# define ASM_TERMINAL_LEXEM		0x1
# define ASM_TERMINAL_COM_LEXEM	0x2
# define ASM_TERMINAL_CMD_LEXEM	0x4
# define ASM_TERMINAL_SEP_LEXEM	0x8
# define ASM_TERMINAL_QUO_LEXEM	0x10
# define ASM_TERMINAL_DIR_LEXEM	0x20
# define ASM_TERMINAL_LAB_LEXEM	0x40

# define ASM_NUMBER_LEXEM		0x80
# define ASM_REGISTRE_LEXEM		0x100

# define ASM_INSTRUCTION_LEXEM	0x200
# define ASM_LD_LEXEM			0x400
# define ASM_STI_LEXEM			0x800
# define ASM_LIVE_LEXEM			0x1000
# define ASM_ZJMP_LEXEM			0x2000
# define ASM_WORD_LEXEM			0x4000


typedef struct s_asm_token			t_asm_token;
typedef struct s_asm_token_ref		t_asm_token_ref;

struct								s_asm_token_ref
{
	int								type;
	char							*value;
};

struct								s_asm_token
{
	long int						type;
	char							*value;
	size_t							size;
	int								line;
	int								column;
	t_asm_token						*previous;
	t_asm_token						*next;
	void							*meta;
};

t_asm_token_ref						g_asm_token_ref[] = {\
	{ASM_TERMINAL_LEXEM | ASM_TERMINAL_COM_LEXEM, "#"},\
	{ASM_TERMINAL_LEXEM | ASM_TERMINAL_CMD_LEXEM, "."},\
	{ASM_TERMINAL_LEXEM | ASM_TERMINAL_SEP_LEXEM, ","},\
	{ASM_TERMINAL_LEXEM | ASM_TERMINAL_QUO_LEXEM, "\""},\
	{ASM_TERMINAL_LEXEM | ASM_TERMINAL_DIR_LEXEM, "%"},\
	{ASM_TERMINAL_LEXEM | ASM_TERMINAL_LAB_LEXEM, ":"},\
	{ASM_NUMBER_LEXEM, "-?[0-9]+"},\
	{SM_REGISTRE_LEXEM, "r[0-9]+"},\
	{ASM_INSTRUCTION_LEXEM | SM_LD_LEXEM, "ld"},\
	{ASM_INSTRUCTION_LEXEM | SM_STI_LEXEM, "sti"},\
	{ASM_INSTRUCTION_LEXEM | SM_LIVE_LEXEM, "live"},\
	{ASM_INSTRUCTION_LEXEM | SM_ZJMP_LEXEM, "zjmp"},\
	{ASM_WORD_LEXEM, "[a-z|A-Z][a-z|A-Z|0-9|_]*"},\
	{0, NULL}\
};

#endf
