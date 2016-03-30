/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:45:07 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/29 19:30:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

static int			*call()
{
	static int		i;

	return (&i);
}

static t_term		*term(void)
{
	static t_term	t;

	return (&t);
}

int					cur_initterm(void)
{
	*call() += 1;
	if (*call() > 1)
		return (0);
	if (tcgetattr(0, &term()->global) < 0)
	{
		ft_exit(EXIT_FAILURE, "Failed to load terminfo");
		return (-1);
	}
	term()->local = term()->global;
	term()->local.c_lflag &= ~(ECHO | ICANON);
	term()->local.c_cc[VMIN] = 1;
	term()->local.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term()->local) < 0)
	{
		ft_exit(EXIT_FAILURE, "Failed to set terminfo");
		return (-1);
	}
	return (0);
}

int					cur_resetterm(void)
{
	*call() -= 1;
	if (*call())
		return (0);
	if (tcsetattr(0, TCSANOW, &term()->global) < 0)
	{
		ft_exit(EXIT_FAILURE, "Failed to reset terminfo");
		return (-1);
	}
	return (0);
}

void				cur_exit(int rval, char *msg)
{
	*call() = 1;
	cur_resetterm();
	ft_exit(rval, msg);
}
