/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 09:38:26 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/19 10:03:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					parse_pop(char *line, int *state, t_cons *rules)
{
	*state = LEM_DEFAULT_STATE;
	rules->pop = ft_atoi(line);
	return ((rules->pop < 1 ? LEM_SMALLPOP_ERR : LEM_NOERR));
}
