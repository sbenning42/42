/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:48:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 19:43:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_OPT_CHARSET	"v"
# define ASM_VERBOSE_OPT	0x1

# define ASM_OPEN_ERROR_FMT	"%s: Can't open file: `%s`\n"

# include		"ft_parser.h"
# include		"proginfo.h"
# include		"get_next_line.h"
# include		"libft.h"
# include		"op.h"
# include		"asm_gramm.h"

typedef struct s_op	t_op;

struct				s_op
{
	char			*id;
	unsigned int	opcode;
	unsigned int	nb_arg;
	int				args_type[MAX_ARGS_NUMBER];
	char			*desc;
	unsigned int	cycle;
	unsigned int	carry;
	unsigned int	ocp;
	unsigned int	label_size;
};

int					match_t_comment(t_parser *self, char **scan, void *data);
int					match_t_command(t_parser *self, char **scan, void *data);
int					match_t_litteral(t_parser *self, char **scan, void *data);
int					match_t_separator(t_parser *self, char **scan, void *data);
int					match_t_direct(t_parser *self, char **scan, void *data);
int					match_t_label(t_parser *self, char **scan, void *data);
int					match_t_registre(t_parser *self, char **scan, void *data);
int					match_t_indirect(t_parser *self, char **scan, void *data);
int					match_t_identifier(t_parser *self, char **scan, void *data);
int					match_t_skip_litteral(t_parser *self, char **scan, void *data);
int					match_t_skip_all(t_parser *self, char **scan, void *data);
int					match_t_end_line(t_parser *self, char **scan, void *data);

#endif
