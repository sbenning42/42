/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/30 09:34:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cursor.h"

int			main(int ac, char *av[])
{
	ft_initname(av[0]);
	cur_init(ft_getenv("TERM"));
	cur_initterm();

	ft_printf("scrli: %d\nscrco: %d\n", cur_scrli(), cur_scrco());
	while (42);
	
	cur_resetterm();
	return (0);
	(void)ac;
}
