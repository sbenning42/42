/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 10:37:48 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/27 10:37:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

int		err_malloc(t_dtab *dtab)
{
	ft_putendl(MALLOC_MSG);
	dtab_del(dtab);
	return (ERROR);
}

int		err_lexer(t_dtab *dtab)
{
	ft_putendl(LEXER_MSG);
	dtab_del(dtab);
	return (ERROR);
}

int		err_parser(t_dtab *dtab)
{
	ft_putendl(PARSER_MSG);
	dtab_del(dtab);
	return (ERROR);
}
