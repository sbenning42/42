/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:54:03 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/02 10:31:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_exec(t_list *lst, int ac, char **av)
{
	char	title[1024];
	int		son_pid;
	int		i;
	i = 0;
	
	while (++i < ac || lst)
	{
		ft_snprintf(title, 1024, "FDF: %s", ac != 1 ? av[i] : "Standrd input");
		son_pid = fork();
		if (!son_pid)
			fdf_mlx(*((t_list **)lst->content), title);
		else
		{
			if (son_pid < 0)
				ft_printf("fdf: {red}Error: %s fork{eoc}\n");
			lst = lst->next;
		}
	}
	ft_printf("fdf: {ss}This is the rules when focus on window:{eoc}\n\n\
{green}<escape>{eoc} : Close the window\n\
{green}<up-down>{eoc} : Change color\n\n");
}


