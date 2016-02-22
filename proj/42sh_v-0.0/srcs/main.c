/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:30:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/22 12:35:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sb42sh.h"

int			main(int arg_c, char **arg_v, char **env_p)
{
	int		ret;
	char	input[HOOK_INPUT_SIZE + 1];

	if (hook_open())
	{
		ft_fprintf(2, "Here is the trap: [%s]\n", "main open FAILURE");
		exit(EXIT_FAILURE);
	}
	while (42)
	{
		ft_bzero((void *)input, HOOK_INPUT_SIZE + 1);
		ret = hook_input_log(input, 2);
		if (ret < 0)
			exit(EXIT_FAILURE);
		else if (!ret)
			break ;
	}
	if (hook_close())
	{
		ft_fprintf(2, "Here is the trap: [%s]\n", "main close FAILURE");
		exit(EXIT_FAILURE);
	}
	ft_fprintf(2, "Here is the trap: [%s]\n", "main SUCCESS");
	return (0);
	(void)arg_c;
	(void)arg_v;
	(void)env_p;
}
