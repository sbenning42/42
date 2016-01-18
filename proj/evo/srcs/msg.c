/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:40:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/01/18 11:55:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evo.h"

void		evo_err(char *id, char *msg, int rtnval)
{
	ft_fprintf(2, "{cyan}%s{eoc}: {ss|red}Error{eoc}: {yellow}%s{eoc}\n", id, msg);
	exit(rtnval);
}

void		evo_success(char *id, char *msg)
{
	ft_fprintf(2, "{cyan}%s{eoc}: {ss|green}Success{eoc}: {yellow}%s{eoc}\n", id, msg);
}
