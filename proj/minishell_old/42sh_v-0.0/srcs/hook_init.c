/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:37:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 17:12:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_private.h"

static struct termios	g_standard;

static void				sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (hook_close())
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGCONT)
	{
		if (hook_open())
			exit(EXIT_FAILURE);
	}
}

static void				start_handling(void)
{
	struct sigaction	handler;

	handler.sa_handler = sig_handler;
	sigaction(SIGCONT, &handler, NULL);
	sigaction(SIGINT, &handler, NULL);
}

int						hook_open(void)
{
	struct termios		hook;

	if (tcgetattr(0, &g_standard) < 0)
		return (1);
	hook = g_standard;
	hook.c_lflag &= ~(ICANON | ECHO);
	hook.c_cc[VTIME] = 0;
	hook.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSADRAIN, &hook) < 0)
		return (1);
	ft_bzero((void *)hook_buffer(), sizeof(t_hook_buffer));
	hook_buffer()->offset = HOOK_PRIVATE_BUFFER_OFFSET_SIZE;
	start_handling();
	return (0);
}

int						hook_close(void)
{
	if (tcsetattr(0, TCSANOW, &g_standard))
		return (1);
	return (0);
}
