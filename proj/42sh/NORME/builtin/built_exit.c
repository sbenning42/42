/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:14:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 14:45:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		built_exit(t_sh *sh, t_tree *root)
{
	hist_save(&sh->hist);
	sh_clear(sh);
	exit(EXIT_SUCCESS);
	return (0);
	(void)root;
}
