#ifndef DYNTAB_H
# define DYNTAB_H

# include "libft.h"

# define INT_EXT_DIFF sizeof(unsigned int) * 4

typedef struct			s_dynt
{
	void			*data;
	const unsigned char	offset[INT_EXT_DIFF];
}				t_dynt;

int				dt_tabnew(t_dynt *edtab, unsigned int dsize, unsigned int offset);
int				dt_tabpush(t_dynt *edtab, void *data);
void				dt_tabdel(t_dynt *edtab);
void				dt_tabput_dump(t_dynt *edtab);

#endif
