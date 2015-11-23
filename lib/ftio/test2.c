/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 01:23:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/20 02:10:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <strings.h>
#include <errno.h>
#include <termios.h>

#define FTIO_BS 5

extern void ftio_init_term(void);

typedef struct		s_ftio
{
	int				fd;
	struct termios	term;
	struct termios	cp;
}					t_ftio;

t_ftio				*ftio(void)
{
	static t_ftio	env;

	return (&env);
}

void				ftio_error_handle(void)
{
	/*
	 * Affichage de l'erreur en fonction d'errno à implementer
	*/
	exit(EXIT_FAILURE);
}

void				ftio_sigcont_handle(int sig)
{
	/*
	 * -Wall -Wextra // Ce test ne me sert qu'a cacher le warn gcc :/
	*/
	if (sig)
		ftio_init_term();
}

void				ftio_signal_handle(void)
{
	/*
	 * J'ai observé que l'arret du programme par Ctrl+(C|Z)
	 * remet de lui même la structure termios par defaut...
	 * Je ne comprend pas comment ^^
	*/

	signal(SIGCONT, ftio_sigcont_handle);
}

void				ftio_init_term(void)
{
	ftio_signal_handle();
	if (!isatty(ftio()->fd) || (tcgetattr(ftio()->fd, &ftio()->term) == -1))
		ftio_error_handle();
	ftio()->cp = ftio()->term;
	ftio()->cp.c_lflag &= ~(ICANON | ECHO);
	ftio()->cp.c_lflag |= ISIG;
	ftio()->cp.c_cc[VTIME] = 0;
	ftio()->cp.c_cc[VMIN] = 1;
	if (tcsetattr(ftio()->fd, TCSADRAIN, &ftio()->cp) == -1)
		ftio_error_handle();
}

void				ftio_reset_term(void)
{
	if (tcsetattr(ftio()->fd, TCSANOW, &ftio()->term) == -1)
		ftio_error_handle();
}

int					main(void)
{
	char			buf[FTIO_BS + 1];
	int				ret;

	ftio()->fd = 0;
	ftio_init_term();

	while (42)
	{
		bzero((void *)buf, FTIO_BS + 1);
		ret = read(ftio()->fd, buf, FTIO_BS);
		if (ret < 0)
		{
			ftio_reset_term();
			ftio_error_handle();
		}
		buf[ret] = 0;
		/*
		 * Juste pour la demo, dans la version final,
		 * j'aimerai bien gerer les wchar_t // Mais la c'est pas le propos
		*/
		if (isprint(*buf))
			write(ftio()->fd, buf, ret);
	}

	ftio_reset_term();
	return (0);
}














