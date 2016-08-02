/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 09:12:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/25 11:40:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libft.h"

# define EXC_STDIN 0
# define EXC_STDOUT 1
# define EXC_STDERR 2

typedef struct		s_cmd
{
	char			*id;
	int				ac;
	char			**av;
	char			**ep;
	int				fd[3];
}					t_cmd;

int					exec_list(t_lxem *list);

#endif
