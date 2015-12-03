/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/03 18:27:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"
# include "lexer.h"
/*
# define FDF_BS 1024
# define FDF_MIDDLE 512 
# define FDF_TILE_HEIGHT 32
*/

# define FDF_WIDTH 1024
# define FDF_HEIGHT 1024
# define FDF_GAP 64 

typedef struct		s_fdf_map
{
	int				x;
	int				y;
	int				**mat;
	t_list			*lst;
	char			path[65];
}					t_fdf_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_fdf_map		map;
}					t_env;

typedef struct		s_fdf_point
{
	int				x;
	int				y;
	int				z;
}					t_fdf_point;

t_fdf_map			fdf_parse_map(char *path, t_lex_rule rule);
/*
void				fdf_handle_point(t_env *e);
void				fdf_mlx(t_list *lst, char *title);
void				fdf_exec(t_list *lst, int ac, char **av);
int					fdf_lexing(t_list **lst, char *s, int y, t_lex_rule rule);
t_list				*fdf(char *path);
*/
void				fdf(t_fdf_map map);

#endif
