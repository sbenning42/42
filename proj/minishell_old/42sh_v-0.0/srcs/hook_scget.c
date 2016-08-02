/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_scget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:33:37 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 16:36:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int			hook_scget_flush(void)
{
	return (hook->control()->flush);
}

size_t		hook_scget_size_max(void)
{
	return (hook->control()->size_max);
}

size_t		hook_scget_size(void)
{
	return (hook->control()->size);
}

size_t		hook_scget_offset(void)
{
	return (hook->control()->offset);
}
