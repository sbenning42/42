/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 17:32:00 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/17 03:26:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

void	ftio_sigint(int signum)
{
	ft_printf("SIGINT Hooked\n");
	ftio_reset(ftio_env()->fd);
	exit (signum);
}

void		ftio_sigtstp(int signum)
{
	char	cmd[2];

	cmd[0] = ftio_env()->term.c_cc[VSUSP];
	cmd[1] = 0;
	ftio_reset(ftio_env()->fd);
	ft_printf("SIGTSTP Hooked\n");
	signal(SIGTSTP, SIG_DFL);
	ioctl(ftio_env()->fd, TIOCSTI, cmd);
}

void	ftio_sigcont(int signum)
{
	ftio_init(ftio_env()->fd);
	ft_printf("SIGCONT Hooked\n");
	signal(SIGTSTP, ftio_sigtstp);
}

void	ftio_signal_handle(void)
{
//	signal(SIGINT, ftio_sigint);
	signal(SIGTSTP, ftio_sigtstp);
	signal(SIGCONT, ftio_sigcont);
}
