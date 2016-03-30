/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:55:51 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 14:56:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_maj(t_rl *rl, long int code)
{
	int	ret;

	if (!(ret = rl_searchcode(rl, code)))
		rl_defcode(rl, code);
	else if (ret < 0)
		return (-1);
	return (0);
}
