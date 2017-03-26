/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 13:31:41 by sbenning          #+#    #+#             */
/*   Updated: 2015/09/21 13:33:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dar.h"

void	ft_dardel(t_dar *ar)
{
	free(ar->data);
	free(ar->address);
	ft_bzero((void *)ar, sizeof(t_dar));
}
