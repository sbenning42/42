/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:31:00 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/22 19:46:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define ASM_SRC_EXT		".s"
# define ASM_BIN_EXT		".cor"

# define ASM_BUFFER_SIZE	512

# define ASM_ST_DEFAULT		0
# define ASM_ST_INID		1
# define ASM_ST_INARGS		2
# define ASM_ST_INCMD		3
# define ASM_ST_INCOM		4
# define ASM_ST_INLIT		5
# define ASM_ST_INDIR		6

# include					"op.h"
# include					"libft.h"
# include					<fcntl.h>

typedef struct s_op			t_op;

struct						s_op
{
	char					*id;
	unsigned int			opcode;
	unsigned int			nb_arg;
	int						args_type[MAX_ARGS_NUMBER];
	char					*desc;
	unsigned int			cycle;
	unsigned int			carry;
	unsigned int			ocp;
	unsigned int			label_size;
};

typedef struct s_ins t_ins;
struct s_ins
{
	int		type;
	char	*token;
	int		line;
};


t_list						**s_lexem(void);
void						compile(int fd);
int							maj_state_machina(char c);
void						reset_state_machina(void);
#endif
