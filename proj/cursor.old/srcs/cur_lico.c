/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_lico.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:37:49 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:39:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int				*li(void)
{
	static int	lli;

	return (&lli);
}

int				*co(void)
{
	static int	lco;

	return (&lco);
}
