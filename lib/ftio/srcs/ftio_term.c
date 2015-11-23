/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 21:15:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/19 21:14:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

void		ftio_init(int fd)
{
	char			*term_name;

//	ftio_signal_handle();
	if (!isatty(fd) \
			|| !(term_name = ttyname(fd)) \
			|| (tcgetattr(fd, &ftio_env()->term) == -1))
		ftio_error_handle();
	if (!ftio_init_cc())
		ftio_error_handle();
	ftio_env()->fd = fd;
	ftio_env()->cp = ftio_env()->term;
	ftio_env()->cp.c_lflag &= ~ICANON;
	ftio_env()->cp.c_lflag &= ~ECHO;
	ftio_env()->cp.c_lflag |= ISIG;
	ftio_env()->cp.c_cc[VTIME] = 0;
	ftio_env()->cp.c_cc[VMIN] = 1;
	if (tcsetattr(fd, TCSADRAIN, &ftio_env()->cp) == -1)
		ftio_error_handle();
}

void		ftio_reset(int fd)
{
	if (tcsetattr(fd, TCSANOW, &ftio_env()->term) == -1)
		ftio_error_handle();
}
