/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:42:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/22 19:32:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		compile(int fd)
{
	char	buffer[ASM_BUFFER_SIZE + 1];
	int		ret;
	int		i;

	reset_state_machina();
	while ((ret = read(fd, buffer, ASM_BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		i = -1;
		while (buffer[++i])
			maj_state_machina(buffer[i]);
	}

	t_list	*tmp;
	tmp = *s_lexem();
	t_ins	*ins;
	int		li;
	li = -1;
	while (tmp)
	{
		ins = (t_ins *)tmp->content;
		if (li != ins->line)
		{
			ft_printf("\n[%d]\t", ins->line);
			li = ins->line;
		}
		ft_printf("%d[%s]\t", ins->type, ins->token);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
