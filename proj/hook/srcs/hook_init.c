/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:37:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/24 17:18:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void		ft_atexit(int code, char *msg)
{
	ft_fprintf(2, "Error occured: %s\n", msg);
	exit(code);
}

void		hk_open(t_hook_input *hook, t_keymap *kmap, size_t size, size_t off)
{
	if (tcgetattr(0, &hook->term.std) < 0)
		ft_atexit(EXIT_FAILURE, "hk_open: tcgetattr");
	hook->term.hook = hook->term.std;
	hook->term.hook.c_lflag &= ~(ICANON | ECHO | ISIG);
	hook->term.hook.c_cc[VTIME] = 0;
	hook->term.hook.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSANOW, &hook->term.hook) < 0)
		ft_atexit(EXIT_FAILURE, "hk_open: tcsetattr");
	hook->term.lin = 0;
	hook->term.col = 0;
	hook->inputs = NULL;
	hook->keymap = kmap;
	hook->size = size;
	hook->buffer.flag = 0x0;
	hook->buffer.offset = (sizeof(char) * off);
	if (hk_reset_buffer(hook))
		ft_atexit(EXIT_FAILURE, "hk_open: hk_reset_buffer");
}

void		hk_close(t_hook_input *hook)
{
	t_dlist	*cp;
	int		fd;

	if (tcsetattr(0, TCSANOW, &hook->term.std) < 0)
	{
		ft_dlstdel(&hook->inputs, NULL);
		ft_atexit(EXIT_FAILURE, "hk_close: tcsetattr");
	}
	/*
	if (hook->inputs->n)
	{
		if ((fd = open(HOOK_INPUTS_FILE, O_CREAT | O_WRONLY, 0750)) < 0)
		{
			ft_dlstdel(&hook->inputs, NULL);
			ft_atexit(EXIT_FAILURE, "hk_close: open");
		}
		cp = hook->inputs;
		while (cp)
		{
			write(fd, (char *)cp->content, cp->content_size);
			write(fd, "\n", 1);
			cp = cp->n;
		}
		close(fd);
	}
	*/
	ft_dlstdel(&hook->inputs, NULL);
}
