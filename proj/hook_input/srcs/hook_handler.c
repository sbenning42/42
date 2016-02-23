/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:58:39 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/23 18:03:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

int		up_arrow_handler(t_hook_input *hk)
{
	ft_printf("OK\n");
	(void)hk;
	return (0);
}

int		down_arrow_handler(t_hook_input *hk)
{
	ft_printf("KO\n");
	(void)hk;
	return (0);
}
