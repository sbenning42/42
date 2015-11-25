/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 11:03:26 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/05 12:04:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_mod_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	if (f)
		return (f - cset);
	else if (ft_isdigit(c))
		return (NB_MOD_FUNCTION - 1);
	else
		return (-1);
}

int			get_spec_index(char *cset, char c)
{
	char	*f;

	f = ft_strchr(cset, c);
	return (f ? f - cset : NB_SPEC_FUNCTION - 1);
}
