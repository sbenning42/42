/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:37:48 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/28 23:45:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"

int			err_handle(int err_id)
{
	if (err_id != NO_ERR)
		ft_putstr(MYNAME);
	if (err_id == ERR)
		ft_putendl(ERR_MSG);
	else if (err_id == ERR_ML)
		ft_putendl(ML_MSG);
	else if (err_id == ERR_LEX)
		ft_putendl(LEX_MSG);
	else if (err_id == ERR_PAR)
		ft_putendl(PAR_MSG);
	else if (err_id == ERR_ARG)
		ft_putendl(ARG_MSG);
	return (err_id);
}
