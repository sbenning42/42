/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 17:20:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 18:00:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

static int	hook_alloc(void)
{
	char	*cp;
	size_t	*size_max;
	size_t	*size;
	size_t	*offset;

	size_max = &hook_buffer()->size_max;
	size = &hook_buffer()->size;
	offset = &hook_buffer()->offset;
	if (*size + HOOK_PRIVATE_INPUT_SIZE >= *size_max)
	{
		cp = hook_buffer()->buffer;
		if (!(hook_buffer()->buffer = ft_strnew(*size_max + *offset)))
		{
			ft_memdel((void **)&cp);
			return (-1);
		}
		*size_max += *offset;
		ft_strcpy(hook_buffer()->buffer, cp);
		ft_memdel((void **)&cp);
	}
	return (0);
}

static void	hook_default(char *input)
{
	if (!(input[0] && !input[1]))
		return ;
	hook_buffer()->buffer[hook_buffer()->size] = input[0];
	hook_buffer()->size += 1;
	write(1, input, 1);
}

int			hook_input_handle(char *input)
{
	if (hook_alloc())
		return (-1);
	if (hook_control(input))
		return (0);
	hook_default(input);
	return (0);
}
