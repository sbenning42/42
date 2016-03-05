/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 20:45:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 21:18:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lexstate		lx_entry(char c)
{
	char		*s;
	char		*f;

	s = LX_CSET_SEARCH;
	if ((f = ft_strchr(s, c)))
		return (g_state[f - s]);
	if (ft_isprint(c))
		return (ST_Word);
	return (ST_Error);
}
