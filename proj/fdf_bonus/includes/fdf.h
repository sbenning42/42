/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:03:46 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/08 03:52:55 by sbenning         ###   ########.fr       */
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

# define X_SCR 680
# define Y_SCR 420

# define ERRFMT "%s: {red}%s{eoc}: %s\n"
# define MSG_RULES " This is the rules when focus on window:"
# define MSG_KESC "<escape>"
# define MSG_ESC " : Close the window\n"
# define MSG_KUPDOWN "<up-down>"
# define MSG_UPDOWN " : Change color\n\n"

# define NB_KHBS 5

typedef void		(*t_fkhdl)(t_env *);

typedef struct		s_khdl
{
	int				key;
	t_fkhdl			*f;
}					t_khdl;

typedef enum		e_fdf_px_attr
{
	X_rel,
	Y_rel,
	Z_rel,
	X_scr,
	Y_scr,
	Color
}					t_fdf_px_attr;

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
	int				c_gap;
}					t_fdf_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_fdf_map		*map;
	char			*av;
	char			*id;
	t_khdl			khdl[NB_KHDL];
}					t_env;

typedef int			t_fdf_px[6];

void				khdl_none(t_env *env);
void				khdl_quit(t_env *env);
void				khdl_default(t_env *env);
void				khdl_zoom_inc(t_env *env);
void				khdl_zoom_dec(t_env *env);

int					ft_err(char *av, char *id, char *msg);
int					fdf_draw(void *p);
int					fdf_key(int key, void *p);
int					fdf_parse(t_env *env, int fd);
void				fdf_mlx(char *av, char *id, int fd);

#endif
