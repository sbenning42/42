/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 18:00:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/16 18:00:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftio.h"

t_ftio_env	*ftio_env(void)
{
	static t_ftio_env	ftio_env;

	return (&ftio_env);
}