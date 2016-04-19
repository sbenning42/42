/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:39:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 19:12:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_rlterm		*term(void)
{
	static t_rlterm	t;

	return (&t);
}

int					rl_initterm(void)
{
	if (tcgetattr(0, &term()->global) < 0)
	{
		ft_error("Failed to load terminfo");
		return (-1);
	}
	term()->local = term()->global;
	term()->local.c_lflag &= ~(ECHO | ICANON | ISIG);
	term()->local.c_cc[VMIN] = 1;
	term()->local.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term()->local) < 0)
	{
		ft_error("Failed to set terminfo");
		return (-1);
	}
	return (0);
}

int					rl_destroyterm(void)
{
	if (tcsetattr(0, TCSANOW, &term()->global) < 0)
	{
		ft_error("Failed to reset terminfo");
		return (-1);
	}
	return (0);
}
