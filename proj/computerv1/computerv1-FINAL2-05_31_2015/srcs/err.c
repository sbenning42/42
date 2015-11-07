/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:37:48 by sbenning          #+#    #+#             */
/*   Updated: 2015/06/01 09:40:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"

static void			do_the_menage_et_dis_ou_le_gars_a_faux(t_dtab *token)
{
	unsigned int	i;

	i = 0;
	while (TDATA[i].type != ERROR && i < token->size)
		i++;
	ft_putstr("Error occur at:\t");
	write(1, TDATA[i].str, TDATA[i].size);
}

int					err_handle(int err_id, t_dtab *token)
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
	if (err_id != ERR_ARG && err_id != ERR_ML && err_id != NO_ERR)
		do_the_menage_et_dis_ou_le_gars_a_faux(token);
	return (err_id);
}
