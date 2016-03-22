/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_strpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:03:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/22 12:53:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			dyn_expand(t_dyn *dyn, size_t size)
{
	char	*tmp;

//	ft_fprintf(2, "size=[%zu], dyn->offset=[%zu], dyn->real=[%zu], dyn->used=[%zu]\n", size, dyn->offset, dyn->real, dyn->used);
	if (dyn->offset <= size)
		dyn->offset = size + 1;
	tmp = dyn->str;
	if (!(dyn->str = ft_strnew(dyn->real + dyn->offset)))
		return (-1);
	ft_strncpy(dyn->str, tmp, dyn->used);
	free(tmp);
	dyn->real += dyn->offset;
	return (0);
}

int			dyn_strpush(t_dyn *dyn, char *str, size_t size)
{
	if (dyn->real <= (dyn->used + size))
	{
		if (dyn_expand(dyn, size) < 0)
			return (-1);
	}
	ft_strncpy(dyn->str + dyn->ante, str, size);
	dyn->ante += size;
	dyn->used += size;
	return (0);
}
