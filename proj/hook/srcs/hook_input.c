/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:8:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 13:19:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

char		*hk_input(t_hook_input *hook)
{
	char	input[POSIX_INPUT_SIZE + 1];
	int		code;

	while (42)
	{
		ft_bzero((void *)input, sizeof(char) * (POSIX_INPUT_SIZE + 1));
		read(0, input, POSIX_INPUT_SIZE);
		code = *(int *)input;
		if (code == 0xA)
			return (hk_flush(hook));
		else if (ft_isprint(input[0]))
		{
			if (hk_push_buffer(hook, input[0]))
				return (NULL);
		}
	}
	return (NULL);
}
