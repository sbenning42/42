/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:15:21 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/14 09:43:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_default_action(t_env *e)
{
	free(e->map->m);
	*e->map = *fdf_save_map(NULL);
	fdf_save_map(e);
}

void	fdf_quit_action(t_env *e)
{
	free(e->map->m);
	mlx_destroy_window(e->mlx, e->win);
	close(e->fd);
	exit(EXIT_SUCCESS);
}
