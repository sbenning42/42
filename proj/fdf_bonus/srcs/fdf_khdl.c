/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_khdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:47:24 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 18:48:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		khdl_none(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	ft_printf("%s: %s: [%d]\n", env->av, env->id, key);
	return (0);
}

int		khdl_quit(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)key;
	mlx_destroy_window(env->mlx, env->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int		khdl_default(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)env;
	(void)key;
	return (0);
}

int		khdl_zoom_inc(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)env;
	(void)key;
	return (0);
}

int		khdl_zoom_dec(void *p, int key)
{
	t_env	*env;

	env = (t_env *)p;
	(void)env;
	(void)key;
	return (0);
}
