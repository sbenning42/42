/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:37:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 13:45:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sb42sh.h"

static struct termios	g_standard;

int						hook_open(void);
int						hook_close(void);

static void				sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (hook_close())
		{
			ft_fprintf(2, "Here is the trap: [%s]\n", "sigint_handler FAILURE");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGCONT)
	{
		if (hook_open())
		{
			ft_fprintf(2, "Here is the trap: [%s]\n", "sigcont_handler");
			exit(EXIT_FAILURE);
		}
		ft_fprintf(2, "SIG HOOKED\n");
	}
}

static void				start_handling(void)
{
	struct sigaction	handler;
	sigset_t			mask_int;
	sigset_t			mask_cont;

	sigemptyset(&mask_int);
	sigaddset(&mask_int, SIGINT);
	sigemptyset(&mask_cont);
	sigaddset(&mask_cont, SIGCONT);
	handler.sa_mask = mask_cont;
	handler.sa_flags = 0;
	handler.sa_handler = sig_handler;
	sigaction(SIGINT, &handler, NULL);
	handler.sa_mask = mask_int;
	sigaction(SIGCONT, &handler, NULL);
}

int						hook_open(void)
{
	static int			init;
	struct termios		hook;

	if (tcgetattr(0, &g_standard) < 0)
	{
		ft_fprintf(2, "Here is the trap: [%s]\n", "hook_open FAILURE 1");
		return (1);
	}
	hook = g_standard;
	hook.c_lflag &= ~(ICANON | ECHO);
	hook.c_cc[VTIME] = 0;
	hook.c_cc[VMIN] = 1;
	if (tcsetattr(0, TCSADRAIN, &hook) < 0)
	{
		ft_fprintf(2, "Here is the trap: [%s]\n", "hook_open FAILURE 2");
		return (1);
	}
	if (!init)
	{
		init = 1;
		start_handling();
	}
	return (0);
}

int						hook_close(void)
{
	if (tcsetattr(0, TCSANOW, &g_standard))
	{
		ft_fprintf(2, "Here is the trap: [%s]\n", "hook_close FAILURE");
		return (1);
	}
	ft_fprintf(2, "Here is the trap: [%s]\n", "hook_close SUCCESS");
	return (0);
}
