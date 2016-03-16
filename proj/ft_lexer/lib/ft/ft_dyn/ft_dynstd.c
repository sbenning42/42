/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynstd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 18:55:52 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 12:59:53 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dyn.h"

char		*dyn_strcpy(t_dynstr *dynstr, char *dest)
{
	if (!dynstr->str)
		return (NULL);
	return (ft_strncpy(dest, dynstr->str, dynstr->used));
}

char		*dyn_strdup(t_dynstr *dynstr)
{
	if (!dynstr->str)
		return (NULL);
	return (ft_strsub(dynstr->str, 0, dynstr->used));
}

char		*dyn_strncpy(t_dynstr *dynstr, size_t len, char *dest)
{
	size_t	llen;

	if (!dynstr->str)
		return (NULL);
	llen = (dynstr->used >= len ? len : dynstr->used);
	return (ft_strncpy(dest, dynstr->str, llen));
}

char		*dyn_strndup(t_dynstr *dynstr, size_t len)
{
	size_t	llen;

	if (!dynstr->str)
		return (NULL);
	llen = (dynstr->used >= len ? len : dynstr->used);
	return (ft_strsub(dynstr->str, 0, llen));
}

char		*dyn_strsub(t_dynstr *dynstr, size_t from, size_t len)
{
	size_t	llen;

	if (!(dynstr->str) || (from > dynstr->used))
		return (NULL);
	llen = ((from + len) <= dynstr->used ? len : (dynstr->used - from));
	return (ft_strsub(dynstr->str, from, llen));
}
