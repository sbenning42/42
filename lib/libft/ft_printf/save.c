#include "ft_printf.h"

t_list			**buflist(void)
{
	static t_list	*bufs;

	return (&bufs);
}

void		save_buf(void *buf, size_t size)
{
	t_list	*cp;

	cp = ft_lstnew(buf, size);
	ft_lstadd_back(LIST__(), cp);
}
