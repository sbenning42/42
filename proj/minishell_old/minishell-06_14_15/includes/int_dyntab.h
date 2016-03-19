#ifndef INT_DYNTAB_H
# define INT_DYNTAB_H

typedef struct		s_int_dynt
{
	void		*data;
	unsigned int	size;
	unsigned int	ability;
	unsigned int	dsize;
	unsigned int	offset;
}			t_int_dynt;

#endif
