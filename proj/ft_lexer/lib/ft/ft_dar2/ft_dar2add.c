/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dar2add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:16:51 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 11:16:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar2.h"

static int	ft_dar2add_safe(t_dar2 *dar, void *data)
{
	void	*cp;

	cp = ft_memalloc(dar->size_content);
	if (!cp)
		return (ft_dar2del(dar));
	ft_memcpy(cp, data, dar->size_content);
	dar->ar[dar->size++] = cp;
	return (0);
}

static int	ft_dar2exp(t_dar2 *dar, void *data)
{
	void	**tmp;

	tmp = dar->ar;
	dar->ar = ft_memalloc(sizeof(void *) * (dar->size_max * 2));
	if (!dar->ar)
	{
		dar->ar = tmp;
		return (ft_dar2del(dar));
	}
	ft_memcpy(dar->ar, tmp, dar->size_max * sizeof(void *));
	free(tmp);
	dar->size_max *= 2;
	return (ft_dar2add_safe(dar, data));
}

int			ft_dar2add(t_dar2 *dar, void *data)
{
	if (dar->size < dar->size_max)
	{
		return (ft_dar2add_safe(dar, data));
	}
	else
	{
		return (ft_dar2exp(dar, data));
	}
	return (0);
}
