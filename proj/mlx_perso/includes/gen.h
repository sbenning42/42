/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 02:48:36 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/06 22:55:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_H
# define GEN_H

# include <errno.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"
# include "ft_math.h"

# define FDF_GAP_W(X) ((FDF_WIDTH / 2) /X)
# define FDF_GAP_H(X) ((FDF_HEIGHT / 2) / X)
# define GEN_QUIT(X) (X == 53 || X == 12 || X == 65037)
# define RGB_WHITE 0xffffff
# define RGB_BLACK 0x0

#define ERRMSG_MALLOC " Error: Memory allocation failed: "
# define ERRMSG_FORK " Error: Can't fork to handle: "
#define ERRMSG_MLX " Error: Can't load mlx: "
#define ERRMSG_WIN " Error: Can't create window: "

# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<escape>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<up-down>"
# define MSG_UPDOWN " : Change color\n\n"

typedef struct		s_gen_map
{
	t_cart_pt		*mat;
	int				y;
	int				x;
	int				z;
	int				gapx;
	int				gapy;
}					t_gen_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*av;
	t_gen_map		*map;
	int				color;
}					t_env;

typedef struct		s_mlx_px
{
	int				x;
	int				y;
	long int		color;
}					t_mlx_px;

#endif
