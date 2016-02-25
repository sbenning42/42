/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler_arrow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:57:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 14:48:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int		right_handler(t_hook_input *hook)
{
	hk_push_stack_to_buffer(hook);
	return (0);
}

int		left_handler(t_hook_input *hook)
{
	hk_push_buffer_to_stack(hook);
	return (0);
}

int		up_handler(t_hook_input *hook)
{
	(void)hook;
	return (0);
}

int		down_handler(t_hook_input *hook)
{
	(void)hook;
	return (0);
}
