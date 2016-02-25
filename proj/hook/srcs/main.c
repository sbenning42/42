/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/25 15:20:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

t_keymap		g_kmap[] = {\
	{0xa, nline_handler},\
	{0x7f, retarr_handler},\
	{0x435b1b, right_handler},\
	{0x445b1b, left_handler},\
	{0x7e335b1b, suppr_handler},\
	{0x4, exit_handler}\
};

size_t			g_size = 6;

char				*ft_getenv(char **env_p, char *key)
{
	size_t			len;

	len = ft_strlen(key);
	while (*env_p)
	{
		if (ft_strstr(*env_p, key))
			return (*env_p + len + 1);
		env_p++;
	}
	return (NULL);
}

int					main(int arg_c, char **arg_v)
{
	t_hook_input	hook;
	char			*input;

	hook.keymap = g_kmap;
	hook.size = g_size;
	hk_open(&hook, g_kmap, g_size, POSIX_INPUT_OFFSET);
	while (42)
	{
		ft_fprintf(1, "{green}$>{eoc}");
		input = hk_input(&hook);
		ft_putstr(input);
		if (*input)
			write(1, "\n", 1);
	}
	hk_close(&hook);
	return (0);
	(void)arg_c;
	(void)arg_v;
}
