/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 02:32:56 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/17 04:03:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <signal.h>
#include <termios.h>
#define FTIO_BS 5

static struct termios *term(void)
{
	static struct termios term_instance;

	return (&term_instance);
}

static struct termios *cp(void)
{
	static struct termios term_instance;

	return (&term_instance);
}

static void hdsigint(int sig)
{
	tcsetattr(0, TCSANOW, term());
	exit(EXIT_SUCCESS);
}

static void hdsigcont(int sig)
{
	tcsetattr(0, TCSADRAIN, cp());
}

int main(int ac, char **av)
{
//****************[ &=~(ICANON|ECHO) |=ISIG ]***********************************
	tcgetattr(0, term());
	*cp() = *term();
	cp()->c_lflag &= ~(ICANON | ECHO);
	cp()->c_lflag |= ISIG;
	cp()->c_cc[VTIME] = 0;
	cp()->c_cc[VMIN] = 1;
	tcsetattr(0, TCSADRAIN, cp());
//******************************************************************************
//****************[ SIGNAL HANDLER ]********************************************	
	signal(SIGCONT, hdsigcont);
//******************************************************************************
//****************[ TRAITEMENT ]************************************************
	char	buf[FTIO_BS + 1];
	int		ret;
	int		i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr_fd(av[i++], 2);
		bzero((void *)buf, sizeof(char) * FTIO_BS + 1);
		ret = read(0, buf, FTIO_BS);
		buf[ret] = 0;
		ft_putstr("[");
		ft_putnbr(*(long int *)buf);
		ft_putendl("]");
	}
//******************************************************************************
//****************[ RESTAURE ]**************************************************
	tcsetattr(0, TCSANOW, term());
//******************************************************************************
	return (0);
}
