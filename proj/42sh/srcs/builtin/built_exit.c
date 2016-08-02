/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:14:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/29 14:23:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		built_exit(t_sh *sh, t_tree *root)
{
	hist_save(&sh->hist);
	exit(EXIT_SUCCESS);
	return (0);
	(void)root;
}
