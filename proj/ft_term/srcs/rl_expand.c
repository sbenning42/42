/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:33:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 11:48:52 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_expand(t_rl *rl)
{
	char	*cp;
	size_t	postlen;

	cp = rl->buffer;
	if (!(rl->buffer = ft_strnew(rl->real + rl->offset)))
	{
		rl->buffer = cp;
		return (-1);
	}
	ft_strcpy(rl->buffer, cp);
	postlen = rl->real - rl->post_cursor;
	rl->real += rl->offset;
	ft_strcpy(rl->buffer - postlen, cp + rl->post_cursor);
	rl->post_cursor += rl->offset;
	ft_memdel((void **)&cp);
	return (0);
}
