/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:15:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 17:51:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

static void	hook_destroy(void)
{
	if (hook_buffer()->buffer)
		ft_memdel((void **)&hook_buffer()->buffer);
	ft_bzero((void *)hook_buffer(), sizeof(t_hook_buffer));
}

static int	hook_flush(void)
{
	return (hook_buffer()->flush);
}

int			hook_input(char **buffer)
{
	char	input[HOOK_PRIVATE_INPUT_SIZE + 1];
	
	*buffer = NULL;
	while (!hook_flush())
	{
		ft_bzero((void *)input, sizeof(char) * HOOK_PRIVATE_INPUT_SIZE + 1);
		if (hook_input_read(input))
		{
			hook_destroy();
			return (-1);
		}
		if (hook_input_handle(input))
		{
			hook_destroy();
			return (-1);
		}
	}
	if (!(*buffer = ft_strdup(hook_buffer()->buffer)))
	{
		hook_destroy();
		return (-1);
	}
	hook_destroy();
	return (0);
}
