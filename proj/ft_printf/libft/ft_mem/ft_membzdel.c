#include "ft_mem.h"

void	ft_membzdel(void **ap, size_t n)
{
	if (!ap)
		return ;
	ft_bzero(*ap, n);
	ft_memdel(ap);
}
