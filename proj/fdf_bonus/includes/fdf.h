/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/11 18:51:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
***
*/

# define MACOS

/*
***	# define LINUX
*/

# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

# define FORK 1
# define FDF_SCREEN 1024
# define NB_KHDL 6

# define DEF_K_ID 0
# define ZOOI_K_ID 1
# define ZOOD_K_ID 2
# define QUIT_K_ID 3
# define ALTI_K_ID 4
# define ALTD_K_ID 5

# ifdef MACOS
#  define FDF_DEF_K 87
#  define FDF_ZOOI_K 69
#  define FDF_ZOOD_K 78
#  define FDF_ALTI_K 126
#  define FDF_ALTD_K 125
#  define FDF_QUIT_K 53
# endif

/*
***	MACOS	***
*/

# ifdef NUX
#  define FDF_DEF_K 65437
#  define FDF_ZOOI_K 65451
#  define FDF_ZOOD_K 65453
#  define FDF_ALTI_K 
#  define FDF_ALTD_K 
#  define FDF_QUIT_K 65307
# endif

/*
***	LINUX	***
*/

# define FDF_SNPRINTF_BS 96
# define FDF_COLOR_POS (0xff0000 - 0xff00)
# define FDF_COLOR_NEG (0xff00 - 0xff)
# define ERRFMT "%s: {red}%s{eoc}: %s\n"
# define FDF_1RULEFMT "%s:{ss}%s{eoc}\n\n{green}%-20s{eoc}%s{green}%-20s{eoc}%s"
# define FDF_2RULEFMT "{green}%-20s{eoc}%s{green}%-20s{eoc}%s"
# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<'escape'>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<'up' and 'down'>"
# define MSG_UPDOWN " : Change altitude\n"
# define MSG_KPLUSMINUS "<'+' and '-'>"
# define MSG_PLUSMINUS " : Zoom and unzoom\n"
# define MSG_KFIVE "<'5'>"
# define MSG_FIVE " : Restore default\n\n"

# define CLEAR 1
# define WHITE 0xffffff 
# define RED 0xff0000
# define GREEN 0xff00
# define BLUE 0xff
# define BLACK 0x0

# define ABSI(X) (X > 0 ? X : X * -1)
# define ABSF(X) (X > 0.0 ? X : X * -1.0)
# define TOXISO(F, X, Y) ((F(2.0) / 2.0) * (X - Y))
# define TOYISO(F, X, Y, Z) ((F(2.0 / 3.0) * -Z) /*-*/+ ((1.0 / F(6.0)) * (X + Y)))
# define TOSCREEN(V, G) (V * G + (FDF_SCREEN / 2))
# define TOCOLORPOS(Z) ((RED + GREEN) - ((GREEN / BLUE) * Z))
# define TOCOLORNEG(Z) ((BLUE + GREEN) - ((GREEN / BLUE) * Z))
# define TOCOLORUNK(Z) (Z > 0.0 ? TOCOLORPOS((int)Z) : TOCOLORNEG(ABSI((int)Z)))

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
	Fix,
	X_rel,
	Y_rel,
	Z_rel,
	X_iso,
	Y_iso,
	X_scr,
	Y_scr,
	Color
}					t_fdf_px_attr;

typedef float		t_fdf_px[9];
typedef int			t_fdf_pxi[9];

typedef struct		s_fdf_map
{
	t_fdf_px		*m;
	int				x;
	int				y;
	int				z_min;
	int				z_max;
	float			gap;
}					t_fdf_map;

typedef struct		s_khdl
{
	int				key;
	int				(*hdl)(void *, int);
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

typedef struct		s_bres_info
{
	t_fdf_px_attr	id;
	t_fdf_px_attr	id_e;
	int				d1;
	int				d2;
	int				i0;
	int				i1;
	int				i2;
	int				c1;
	int				c2;
	int				diff;
}					t_bres_info;

void				fdf_default_action(t_env *e);
void				fdf_zoomi_action(t_fdf_map *map);
void				fdf_zoomd_action(t_fdf_map *map);
void				fdf_alti_action(t_fdf_map *map);
void				fdf_altd_action(t_fdf_map *map);
void				fdf_quit_action(t_env *e);

int					khdl_none(void *p, int key);

int					khdl_quit(void *p, int key);
int					khdl_default(void *p, int key);
int					khdl_zoom_inc(void *p, int key);
int					khdl_zoom_dec(void *p, int key);
int					khdl_alt_inc(void *p, int key);
int					khdl_alt_dec(void *p, int key);

void				fdf_getscr_attr(t_fdf_map *map, t_fdf_px px);
void				fdf_maj_alt_map(t_fdf_map *map, float inc);
void				fdf_majmat(t_env *e);

void				fdf_bresenham_px(t_env *e, t_fdf_px p1, t_fdf_px p2, int clr);

t_fdf_map			*fdf_save_map(t_env *e);
int					ft_err(char *av, char *id, char *msg);
void				fdf_draw_m(t_env *e, t_fdf_map *map, int clr);
int					fdf_draw(void *p);
int					fdf_key(int key, void *p);
void				fdf_free_line(void *content, size_t size);
t_list				*fdf_lexer(char *av, char *id, char *s);
int					fdf_parser(t_env *e, int fd);
void				fdf_mlx(char *av, char *id, int fd);

#endif
