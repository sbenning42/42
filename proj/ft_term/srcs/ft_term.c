/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:43:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 14:49:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

t_term				*tm_term(void)
{
	static t_term	term;

	return (&term);
}

int					myput(int c)
{
	ft_putchar((char)c);
	return (c);
}

void				tm_cap(char *id)
{
	tputs(tgetstr(id, NULL), 1, myput);
}

int					tm_init(void)
{
	if (tcgetattr(0, &tm_term()->global) < 0)
		return (-1);
	tm_term()->local = tm_term()->global;
	tm_term()->local.c_lflag &= ~(ICANON | ECHO);
	tm_term()->local.c_cc[VMIN] = 1;
	tm_term()->local.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &tm_term()->local) < 0)
		return (-1);
	return (0);
}

int					tm_quit(void)
{
	if (tcsetattr(0, TCSANOW, &tm_term()->global) < 0)
		return (-1);
	return (0);
}
