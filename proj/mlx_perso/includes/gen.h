/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:48:36 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 11:48:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_H
# define GEN_H

# include <errno.h>
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define GEN_QUIT(X) (X == 53 || X == 12 || X == 65037)
# define SCREEN 680

# define BLACK 0x0
# define BLUE 0xff
# define GREEN 0xff00
# define RED 0xff0000
# define WHITE 0xffffff

# define ERRMSG_MALLOC " Error: Memory allocation failed: "
# define ERRMSG_FORK " Error: Can't fork to handle: "
# define ERRMSG_MLX " Error: Can't load mlx: "
# define ERRMSG_WIN " Error: Can't create window: "

# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<escape>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<up-down>"
# define MSG_UPDOWN " : Change color\n\n"

typedef float		t_fdf_px[9];

typedef enum		s_fdf_px_i
{
	Fix,
	X_rel,
	Y_rel,
	Z_rel,
	X_iso,
	Y_iso,
	X_scr,
	Y_scr,
	Color
}					t_fdf_px_i;

typedef struct		s_gen_map
{
	t_fdf_px		*m;
	int				y;
	int				x;
	int				z;
	float			gap;
}					t_gen_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*av;
	t_gen_map		*map;
}					t_env;

#endif
