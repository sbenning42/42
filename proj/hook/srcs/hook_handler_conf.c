/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler_conf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 20:48:06 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 14:47:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int		exit_handler(t_hook_input *hook)
{
	write(1, "\n", 1);
	hk_close(hook);
	exit(EXIT_SUCCESS);
	return (0);
}

int		nline_handler(t_hook_input *hook)
{
	hook->buffer.flag |= HOOK_F_FLUSH;
	return (0);
}

int		retarr_handler(t_hook_input *hook)
{
	hk_pop_buffer(hook);
	return (0);
}

int		suppr_handler(t_hook_input *hook)
{
	hk_pop_stack(hook);
	return (0);
}

int		inser_handler(t_hook_input *hook)
{
	(void)hook;
	return (0);
}
