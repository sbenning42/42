/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/01 12:59:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"
# include "lexer.h"

# define FDF_BS 1024

typedef struct		s_param
{
	t_list			*lst;
	void			*mlx;
	void			*win;
}					t_param;

typedef struct		s_fdf_point
{
	int				x;
	int				y;
	int				z;
}					t_fdf_point;

int					fdf_lexing(t_list **lst, char *s, int y, t_lex_rule rule);
void				fdf(char *path);

#endif
