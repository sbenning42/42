/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:24:12 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/02 14:55:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

t_key	g_key[RL_GKEY_SIZE] = {\
	{0xa, rl_maj_nl},\
	{0x7f, rl_maj_retarr},\
};
