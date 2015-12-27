/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 10:06:42 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/27 13:21:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <limits.h>
# include <fcntl.h>

# define TETRIMINOEND (USHRT_MAX + 1)
# define SHRTEND 0x10000

typedef unsigned short int	t_tetrimino;

void						put_tetrimino(t_tetrimino t, char c);
int							ft_err(char *av, char *id, char *msg, int rvalue);
t_tetrimino					*parse(char *file);

#endif
