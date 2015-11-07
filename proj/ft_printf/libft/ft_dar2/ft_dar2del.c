#include "ft_dar2.h"

int		ft_dar2del(t_dar2 *dar)
{
	t_uint	i;

	i = 0;
	while (i < dar->size)
	{
		if (dar->del)
			dar->del(dar->ar[i]);
		free(dar->ar[i]);
		i++;
	}
	free(dar->ar);
	ft_bzero(dar, sizeof(t_dar2));
	return (1);
}
