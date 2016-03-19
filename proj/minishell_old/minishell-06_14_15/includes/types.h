#ifndef TYPES_H
# define TYPES_H

# include "dyntab.h"

# define K_SIZE 5
# define NB_SIG 10

typedef enum		e_sigt
{
	SIG_RET_ARR,
	SIG_NL,
	SIG_UP,
	SIG_DOWN,
	SIG_LEFT,
	SIG_RIGHT,
	SIG_CTRL_Z,
	SIG_CTRL_C,
	SIG_CTRL_D,
	NO_SIG
}			t_sigt;

typedef struct		s_sig
{
	t_sigt		type;
	char		val[K_SIZE + 1];
}			t_sig;

typedef struct		s_input
{
	char		buff[K_SIZE + 1];
	char		*cmd;
	t_dynt		*cmd_tab;
	unsigned int	size;
	t_sigt		sig;
}			t_input;

typedef int		(*t_handle)(t_input *input);

#endif
