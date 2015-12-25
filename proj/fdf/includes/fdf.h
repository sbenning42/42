/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/25 11:29:09 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

/*
***
***			***			OS SPECIFICATION			***
***
***
***	# define MACOS
***
***	# define LINUX
***
***	You have to define ONE of them to get the values' OS keys
***
*/

# define LINUX

/*
***
***			***			SETTINGS			***
***
***
***	FORK have to be 0|1. 1 allow you to open multiple MLX Window
***
***	FDF_SCREEN is the Width and Height of the MLX Window
***
***	NB_KHDL is the number of handled key
***
***	FDF_SNPRINTF_BS is the ft_snprintf buffer size.
***	It is used by the parser to print some message.
***
*/

# define FORK 1
# define FDF_SCREEN 680
# define NB_KHDL 6
# define FDF_SNPRINTF_BS 128

/*
***			***			KEY ID			***
*/

# define DEF_K_ID 0
# define ZOOI_K_ID 1
# define ZOOD_K_ID 2
# define QUIT_K_ID 3
# define ALTI_K_ID 4
# define ALTD_K_ID 5

/*
***			***			OS KEY'S VALUE			***
*/

/*
***			***			FOR MACOS			***
*/

# ifdef MACOS
#  define FDF_DEF_K 87
#  define FDF_ZOOI_K 69
#  define FDF_ZOOD_K 78
#  define FDF_ALTI_K 126
#  define FDF_ALTD_K 125
#  define FDF_QUIT_K 53
# endif

/*
***			***			FOR LINUX			***
*/

# ifdef LINUX
#  define FDF_DEF_K 65437
#  define FDF_ZOOI_K 65451
#  define FDF_ZOOD_K 65453
#  define FDF_ALTI_K 65362
#  define FDF_ALTD_K 65364
#  define FDF_QUIT_K 65307
# endif

/*
***			***			IDENTIFIED VALUE			***
*/

# define CLEAR 1
# define FDF_COLOR_POS (0xff0000 - 0xff00)
# define FDF_COLOR_NEG (0xff00 - 0xff)
# define WHITE 0xffffff
# define RED 0xff0000
# define GREEN 0xff00
# define BLUE 0xff
# define BLACK 0x0

/*
***			***			FT_PRINTF FORMAT			***
*/

# define FMT_FORK "'{pink}%s{eoc} {green}%s{eoc}'"
# define FMT_SYN "l{red}%d{eoc}: %s: '{red}%.*1s{eoc}'"
# define FMT_ERR "%s: {red}%s{eoc}: %s\n"
# define FMT_VERB "%s {yellow}<verbose>{eoc}: {yellow}%s{eoc}: %s\n"
# define FMT_1RULE "%s:{ss}%s{eoc}\n\n{green}%-20s{eoc}%s{green}%-20s{eoc}%s"
# define FMT_2RULE "{green}%-20s{eoc}%s{green}%-20s{eoc}%s"

/*
***			***			FT_PRINTF MESSAGE			***
*/

# define MSG_SYN "Syntax error near token"
# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<'escape'>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<'up' and 'down'>"
# define MSG_UPDOWN " : Change altitude\n"
# define MSG_KPLUSMINUS "<'+' and '-'>"
# define MSG_PLUSMINUS " : Zoom and unzoom\n"
# define MSG_KFIVE "<'5'>"
# define MSG_FIVE " : Restore default\n\n"

/*
***			***			MACRO TO HANDLE GEOMETRIC CONVERTION			***
*/

# define ABSI(X) (X > 0 ? X : X * -1)
# define ABSF(X) (X > 0.0 ? X : X * -1.0)
# define TOXISO(F, X, Y) ((F(2.0) / 2.0) * (X - Y))
# define TOYISO(F, X, Y, Z) ((F(2.0 / 3.0) * -Z) + ((1.0 / F(6.0)) * (X + Y)))
# define TOSCREEN(V, G) (V * G + (FDF_SCREEN / 2))
# define TOCOLORPOS(Z) ((RED + GREEN) - ((GREEN / BLUE) * Z))
# define TOCOLORNEG(Z) ((BLUE + GREEN) - ((GREEN / BLUE) * Z))
# define TOCOLORUNK(Z) (Z > 0.0 ? TOCOLORPOS((int)Z) : TOCOLORNEG(ABSI((int)Z)))

/*
***			***			FDF TYPE			***
*/

typedef float		t_fdf_px[9];
typedef int			t_fdf_pxi[9];

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

typedef struct		s_khdl
{
	int				key;
	int				(*hdl)(void *, int);
}					t_khdl;

typedef struct		s_fdf_map
{
	t_fdf_px		*m;
	int				x;
	int				y;
	int				z_min;
	int				z_max;
	float			gap;
}					t_fdf_map;

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
	int				clr;
}					t_bres_info;

/*
***			***			fdf_lexer.c			***
*/

t_list				*fdf_lexer(char *av, char *id, char *s);

/*
***			***			fdf_parser.c			***
*/

int					fdf_parser(t_env *e, int fd);

/*
***			***			fdf_mlx.c			***
*/

void				fdf_mlx(char *av, char *id, int fd);

/*
***			***			fdf_map.c			***
*/

int					fdf_map_attr(t_env *e, t_list *lst);
void				fdf_map_constructor(t_env *env, t_list *lst);

/*
***			***			fdf_maj.c			***
*/

void				fdf_maj_alt_map(t_fdf_map *map, float inc);
void				fdf_majmat(t_env *e);

/*
***			***			fdf_get.c			***
*/

void				fdf_getscr_attr(t_fdf_map *map, t_fdf_px px);

/*
***			***			fdf_draw.c			***
*/

void				fdf_draw_m(t_env *e, t_fdf_map *map, int clr);
int					fdf_draw(void *p);

/*
***			***			fdf_key.c			***
*/

int					fdf_key(int key, void *p);

/*
***			***			fdf_khdl.c			***
*/

int					khdl_none(void *p, int key);
int					khdl_quit(void *p, int key);
int					khdl_default(void *p, int key);

/*
***			***			fdf_khdl2.c			***
*/

int					khdl_zoom_inc(void *p, int key);
int					khdl_zoom_dec(void *p, int key);
int					khdl_alt_inc(void *p, int key);
int					khdl_alt_dec(void *p, int key);

/*
***			***			fdf_action.c			***
*/

void				fdf_default_action(t_env *e);
void				fdf_quit_action(t_env *e);

/*
***			***			fdf_action2.c			***
*/

void				fdf_zoomi_action(t_fdf_map *map);
void				fdf_zoomd_action(t_fdf_map *map);
void				fdf_alti_action(t_fdf_map *map);
void				fdf_altd_action(t_fdf_map *map);

/*
***			***			fdf_free.c			***
*/

void				fdf_free_line(void *content, size_t size);

/*
***			***			fdf_info.c			***
*/

void				bres_fill_info_o1o2(int dx, int dy, t_bres_info *info);
void				bres_fill_info_o3o4(int dx, int dy, t_bres_info *info);
void				bres_fill_info_o5o6(int dx, int dy, t_bres_info *info);
void				bres_fill_info_o7o8(int dx, int dy, t_bres_info *info);
void				bres_fill_info_verthor(int dx, int dy, t_bres_info *info);

/*
***			***			fdf_bresenham.c			***
*/

void				fdf_bresenham_px\
					(t_env *e, t_fdf_px p1, t_fdf_px p2, int clr);

/*
***			***			fdf_msg.c			***
*/

int					ft_err(char *av, char *id, char *msg);
int					ft_verbose(char *av, char *id, char *msg);
int					fdf_synerror(t_env *env, t_lex_tk *t, int y);

/*
***			***			fdf_save.c			***
*/

t_fdf_map			*fdf_save_map(t_env *e);

#endif
