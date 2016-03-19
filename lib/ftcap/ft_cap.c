/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:49:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 16:53:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cap.h"

int			mput(int i)
{
	ft_putchar((char)i);
	return (i);
}

void		ft_cap(char *cap, int flag, int x, int y)
{
	char	*str;

	if (!ft_strcmp("cm", cap))
	{
		if (!(str = tgoto(tgetstr("cm", NULL), x, y)))
			ft_exit(EXIT_FAILURE, CAP_ERROR);
		if (tputs(str, 1, mput))
			ft_exit(EXIT_FAILURE, CAP_ERROR);
	}
	else if (flag)
	{
		if (!(str = tparm(tgetstr(cap, NULL), x, y)))
			ft_exit(EXIT_FAILURE, CAP_ERROR);
		if (tputs(str, 1, mput))
			ft_exit(EXIT_FAILURE, CAP_ERROR);
	}
	else
	{
		if (!(str = tgetstr(cap, NULL)))
			ft_exit(EXIT_FAILURE, CAP_ERROR);
		tputs(str, 1, mput);
	}
}
