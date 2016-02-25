/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:26:25 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 16:17:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int			hook_cc(t_hook_input *hook, int code)
{
	size_t		i;

	i = 0;
	while (i < hook->size)
	{
		if (code == hook->keymap[i].k_code)
			return (hook->keymap[i].k_handle(hook));
		i++;
	}
	return (0);
}

int			hk_get_input_code(void)
{
	char	input[POSIX_INPUT_SIZE + 1];
	int		ret;

	ft_bzero((void *)input, sizeof(char) * (POSIX_INPUT_SIZE + 1));
	if ((ret = read(0, input, POSIX_INPUT_SIZE)) < 0)
		return (0);
	input[ret] = 0;
	return (*(int *)input);
}

char		*hk_input(t_hook_input *hook)
{
	int		code;

	while (!HOOK_FLUSH)
	{
		if (!(code = hk_get_input_code()))
			return (NULL);
		if (IS_PRINT(code))
		{
			if (hk_push_buffer(hook, (char)code))
				return (NULL);
		}
		else if (hook_cc(hook, code))
			return (NULL);
		hk_output(hook);
	}
	return (hk_flush(hook));
}
