/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_strpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:03:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 18:35:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			dyn_expand(t_dyn *dyn, size_t size)
{
	char	*tmp;
	char	*tmppost;

	if (dyn->offset <= size)
		dyn->offset = size + 1;
	tmp = dyn->str;
	tmppost = dyn->strend - dyn->post;
	if (!(dyn->str = ft_strnew(dyn->real + dyn->offset)))
		return (-1);
	dyn->real += dyn->offset;
	dyn->strend = dyn->str + dyn->real;
	ft_strncpy(dyn->str, tmp, dyn->ante);
	ft_strncpy(dyn->strend - dyn->post, tmppost, dyn->post);
	free(tmp);
	return (0);
}

int			dyn_strpushante(t_dyn *dyn, char *str, size_t size)
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

int			dyn_strpushpost(t_dyn *dyn, char *str, size_t size)
{
	if (dyn->real <= (dyn->used + size))
	{
		if (dyn_expand(dyn, size) < 0)
			return (-1);
	}
	dyn->post += size;
	ft_strncpy(dyn->strend - dyn->post, str, size);
	dyn->used += size;
	return (0);
}

int			dyn_strpopante(t_dyn *dyn, char *str, size_t size)
{
	if (size > dyn->ante)
		return (-1);
	dyn->ante -= size;
	if (str)
		ft_strncpy(str, dyn->str + dyn->ante, size);
	ft_bzero((void *)(dyn->str + dyn->ante), size);
	dyn->used -= size;
	return (0);
}

int			dyn_strpoppost(t_dyn *dyn, char *str, size_t size)
{
	if (size > dyn->post)
		return (-1);
	if (str)
		ft_strncpy(str, dyn->strend - dyn->post, size);
	ft_bzero((void *)(dyn->strend - dyn->post), size);
	dyn->post -= size;
	dyn->used -= size;
	return (0);
}
