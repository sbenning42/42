/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:05:32 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 12:54:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dyn.h"

static int	static_dyn_expand(t_dynstr *dynstr, size_t optoffset)
{
	char	*tmp;

	while (dynstr->expand_offset <= optoffset)
		dynstr->expand_offset *= 2;
	dynstr->real += dynstr->expand_offset;
	if (!(tmp = ft_strnew(dynstr->real)))
	{
		dyn_strdel(dynstr);
		return (-1);
	}
	if (dynstr->str)
	{
		ft_strncpy(tmp, dynstr->str, dynstr->used);
		ft_memdel((void **)&dynstr->str);
	}
	dynstr->str = tmp;
	return (0);
}

int			dyn_strnew(t_dynstr *dynstr, size_t offset)
{
	if (offset && !(dynstr->str = ft_strnew(offset)))
		return (-1);
	dynstr->expand_offset = offset;
	dynstr->real = offset;
	return (0);
}

int			dyn_strdel(t_dynstr *dynstr)
{
	if (dynstr->str)
		ft_memdel((void **)&dynstr->str);
	else
		return (-1);
	return (0);
}

int					dyn_strpushstr(t_dynstr *dynstr, char *str, size_t len)
{
	if (!dynstr->str)
		return (-1);
	if ((dynstr->used + len) >= dynstr->real)
	{
		if (static_dyn_expand(dynstr, len) < 0)
			return (-1);
	}
	dynstr->used += ft_strlcpy(dynstr->str + dynstr->used, str, len);
	return (0);
}

int					dyn_strpopstr(t_dynstr *dynstr, size_t len)
{
	size_t			llen;

	if (!dynstr->str)
		return (-1);
	llen = (dynstr->used >= len ? len : dynstr->used);
	dynstr->used -= llen;
	ft_bzero((void *)(dynstr->str + dynstr->used), llen);
	return (0);
}

void				dyn_strclr(t_dynstr *dynstr)
{
	ft_bzero((void *)dynstr->str, dynstr->used);
	dynstr->used = 0;
}
