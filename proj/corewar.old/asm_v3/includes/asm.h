/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:31:00 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 12:01:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_OPT_CHARSET		"cv"
# define ASM_OPT_COLOR			1
# define ASM_OPT_VERBOSE		2

# define ASM_SRC_EXT			".s"
# define ASM_BIN_EXT			".cor"

# define ASM_LEXICAL_ERROR_FMT	"%s: Lexical error at [%d][%d] - `%c`\n"
# define ASM_OPEN_ERROR_FMT		"%s: Open error on file: '%s'\n"
# define ASM_TOKEN_DUMP_FMT		"TOKEN %03d: (%03d,%03d) -> [%s]-[%s]-[%zu]\n"

# define G_ASM_GRAMM			g_asm_gramm
# define ASM_PARSE(X)			(G_ASM_GRAMM + X)

# include						"op.h"
# include						"libft.h"
# include						"get_next_line.h"
# include						"proginfo.h"
# include						"asm_lexem.h"
# include						<fcntl.h>


struct							s_op
{
	char						*id;
	unsigned int				opcode;
	unsigned int				nb_arg;
	int							args_type[MAX_ARGS_NUMBER];
	char						*desc;
	unsigned int				cycle;
	unsigned int				carry;
	unsigned int				ocp;
	unsigned int				label_size;
};

int								asm_lexer(char **scan, t_asm_token **lexem);

#endif
