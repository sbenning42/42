/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:8:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 17:19:59 by sbenning         ###   ########.fr       */
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
		{
			hook->buffer.flag |= HOOK_F_CC;
			return (hook->keymap[i].k_handle(hook));
		}
		i++;
	}
	return (0);
}

char		*hk_input(t_hook_input *hook)
{
	char	input[POSIX_INPUT_SIZE + 1];
	int		code;

	while (42)
	{
		if (HOOK_FLUSH)
			return (hk_flush(hook));
		ft_bzero((void *)input, sizeof(char) * (POSIX_INPUT_SIZE + 1));
		if ((ret = read(0, input, POSIX_INPUT_SIZE)) < 0)
			continue ;
		code = *(int *)input;
		if ((hook_cc(hook, code)))
			return (NULL);
		else if (!IS(hook->buffer.flag, HOOK_F_CC) && ft_isprint(*input))
		{
			if (hk_push_buffer(hook, input[0]))
				return (NULL);
		}
		else if (!IS(hook->buffer.flag, HOOK_F_CC))
			ft_fprintf(2, "K_code unhandled: [%#X]\n", code);
		else
			hook->buffer.flag &= ~HOOK_F_CC;
	}
	return (NULL);
}
