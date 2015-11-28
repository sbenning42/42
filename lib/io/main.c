/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 19:51:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/15 19:07:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int 		main(void)
{
	struct termios	term;
	char	*input;
	t_dic_entry	*dic;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);



















	while (42)
	{
		io_smart_input("Input: ", &input, (dic = IO_DSET));
		if (!ft_strcmp(input, "STOP"))
		{
			free(input);
			ft_printf("\n");
			break ;
		}
		free(input);
		ft_printf("\n");
	}
	io_smart_input(NULL, NULL, NULL);
	
	












	ft_dicdel(&dic, NULL);

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}
