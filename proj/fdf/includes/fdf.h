/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/01 21:35:36 by sbenning         ###   ########.fr       */
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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_list			*lst;
}					t_env;

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

void				fdf_mlx(t_list *lst, char *title);
void				fdf_exec(t_list *lst, int ac, char **av);
int					fdf_lexing(t_list **lst, char *s, int y, t_lex_rule rule);
t_list				*fdf(char *path);

#endif
