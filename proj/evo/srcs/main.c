/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:32:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/01/18 12:50:18 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "evo.h"

int			main(int ac, char **av)
{
	t_env	e;

	(void)ac;
	if (!(e.mlx = mlx_init()))
		evo_err(av[0], "mlx init", EXIT_FAILURE);
	else
		evo_success(av[0], "mlx init");
	if (!(e.win = mlx_new_window(e.mlx, HEIGHT, WIDTH, "Evo GAME")))
		evo_err(av[0], "mlx new window", EXIT_FAILURE);
	else
		evo_success(av[0], "mlx new window");
	e.av = av[0];
	init_random();
	if (!(e.pop = random_pop(POPSIZE)))
		evo_err(av[0], "random pop", EXIT_FAILURE);
	else
		evo_success(av[0], "random pop");
	mlx_loop_hook(e.mlx, evo_loop, &e);
	mlx_key_hook(e.win, evo_key, &e);
	mlx_expose_hook(e.win, evo_expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
