#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"

typedef struct			s_fdf_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_fdf_point;

int			fdf_parse(t_list **info, int fd, int *y);

#endif
