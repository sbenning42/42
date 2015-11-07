#include "ft_dar2.h"

void ft_dar2dump(t_dar2 *dar, void (*f)(void *))
{
	t_uint	i;

	i = 0;
	while (i < dar->size)
	{
		if (f)
			f(dar->ar[i]);
		i++;
	}
}
