/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/09 03:33:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define FORK 1
# define X_SCR 680
# define Y_SCR 420
# define NB_KHDL 4
# define FDF_SNPRINTF_BS 96

//# define MACOS
# define NUX

# ifdef MACOS
#  define FDF_DEF_K 87
#  define FDF_ZOOI_K 69
#  define FDF_ZOOD_K 78
#  define FDF_QUIT_K 53
# endif
# ifdef NUX
#  define FDF_DEF_K 65437
#  define FDF_ZOOI_K 65451
#  define FDF_ZOOD_K 65453
#  define FDF_QUIT_K 65307
# endif

/*
***	MACOS || NUX	***
*/

# define FDF_COLOR_POS (0xff0000 - 0xff00)
# define FDF_COLOR_NEG (0xff00 - 0xff)
# define ERRFMT "%s: {red}%s{eoc}: %s\n"
# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<escape>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<up-down>"
# define MSG_UPDOWN " : Change color\n\n"

# define NAM(X, Y) ((Y = ft_strrchr(X, '/')) ? Y + 1 : X)
# define FDF_PCGAP(X) (FDF_COLOR_POS / X)
# define FDF_NCGAP(X) (FDF_COLOR_NEG / (int)ft_math_abs((float)X))
# define FDF_COLOR(X, Y, Z) (X < 0 ? X * FDF_NCGAP(Y) : X * FDF_PCGAP(Z))

typedef enum		e_lex_tk_type
{
	None,
	Unknow,
	Const_nu,
	Eol
}					t_lex_tk_type;

typedef struct		s_lex_tk
{
	t_lex_tk_type	type;
	char			*value;
	size_t			size;
}					t_lex_tk;

typedef enum		e_fdf_px_attr
{
	X_rel,
	Y_rel,
	Z_rel,
	X_scr,
	Y_scr,
	Color
}					t_fdf_px_attr;

typedef int			t_fdf_px[6];

typedef struct		s_fdf_map
{
	t_fdf_px		*mat;
	int				x;
	int				x_gap;
	int				x_rts;
	int				y;
	int				y_gap;
	int				y_rts;
	int				z_min;
	int				z_max;
}					t_fdf_map;

typedef struct		s_khdl
{
	int				key;
	int				(*handle)(void *, int);
}					t_khdl;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_fdf_map		*map;
	char			*av;
	char			*id;
	int				fd;
	t_khdl			khdl[NB_KHDL];
}					t_env;

int					khdl_none(void *p, int key);

int					khdl_quit(void *p, int key);
int					khdl_default(void *p, int key);
int					khdl_zoom_inc(void *p, int key);
int					khdl_zoom_dec(void *p, int key);

float				ft_math_abs(float f);
int					ft_err(char *av, char *id, char *msg);
void				fdf_bresenham(t_env *env, t_fdf_map *map, int clr);
int					fdf_draw(void *p);
int					fdf_key(int key, void *p);
t_list				*fdf_lexer(char *av, char *id, char *s);
int					fdf_parser(t_env *env, int fd);
void				fdf_mlx(char *av, char *id, int fd);

#endif
