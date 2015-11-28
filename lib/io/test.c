/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 16:11:21 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/14 16:51:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <termios.h>

int main(void)
{
	struct termios	term;
	char	buf[5];
	int		ret;
	int		i;

	tcgetattr(0, &term);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	tcsetattr(0, TCSADRAIN, &term);

	i = 10;
	while (i--)
	{
		ft_bzero((void *)buf, sizeof(char) * 5);
		ret = read(0, buf, 4);
		buf[ret] = '\0';
		printf("Input=%d\n", *(int *)buf);
	}

	tcgetattr(0, &term);
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);

	return (0);
}
