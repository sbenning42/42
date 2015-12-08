/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/05 17:27:22 by sbenning         ###   ########.fr       */
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

# define FDF_WIDTH 680
# define FDF_HEIGHT 420
# define FDF_GAP_W(X) ((FDF_WIDTH / 2) /X)
# define FDF_GAP_H(X) ((FDF_HEIGHT / 2) / X)

# define FDF_FAKE_AV "Standard input"

#define ERRMSG_MALLOC " Error: Memory allocation failed: "
# define ERRMSG_FORK " Error: Can't fork to handle: "
#define ERRMSG_MLX " Error: Can't load mlx: "
#define ERRMSG_WIN " Error: Can't create window: "

# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<escape>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<up-down>"
# define MSG_UPDOWN " : Change color\n\n"

typedef enum		s_fdf_coo_name
{
	Coo_x,
	Coo_y,
	Coo_z
}					t_fdf_coo_name;

typedef struct		s_fdf_map
{
	int				x;		//set by parse
	int				y;		//set by parse
	int				z_min;
	int				z_max;
	t_list			*lst;	//set by parse
	char			*name;   //set by parse
	int				***mat;	//set by mlx
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

void				fdf_mlx(t_fdf_map map, char *av);
int					fdf_parse_file(char **av, int i, t_fdf_map *map);
void				fdf(t_fdf_map map);

#endif
