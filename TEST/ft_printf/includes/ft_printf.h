/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 10:11:37 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/05 12:04:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "ft_lst.h"
# include "ft_str.h"
# include "ft_put.h"

# define FMT format

# define SPEC_CSET "idDxXuUoOpsScC"
# define MOD_CSET "# +-0.hljz["
# define UP_HEX_CSET "0123456789ABCDEF"
# define LOW_HEX_CSET "0123456789abcdef"

# define NB_SPEC_FUNCTION 15
# define NB_MOD_FUNCTION 12
# define NB_COLOR_ATTRIB /*22*/21

# define ESCAPE_SEQ_SIZE 5
# define BUF_SIZE 32
# define BUF_COLOR_SIZE /*64*/1024

# define SPEC__(X) get_spec_index(SPEC_CSET, X)
# define MOD__(X) get_mod_index(MOD_CSET, X)
# define COLOR__(X) color_attrib(X)
# define LIST__ buflist

# define ALT 0x1
# define LADJUST 0x2
# define LONGINT 0x4
# define LLONGINT 0x8
# define SHORTINT 0x10
# define ZEROPAD 0x20
# define SIZET 0x40
# define INTMAXT 0x80
# define CHARINT 0x100

# define INTMAX_SIZE (INTMAXT|LLONGINT|SIZET)

# define COL_BLK 0x1
# define COL_RED 0x2
# define COL_GREE 0x4
# define COL_YEL 0x8
# define COL_BLU 0x10
# define COL_PIN 0x20
# define COL_CYA 0x40
# define COL_GRE 0x80
# define COL_DEF 0x100
# define COL_FBLK 0x200
# define COL_FRED 0x400
# define COL_FGREE 0x800
# define COL_FYEL 0x1000
# define COL_FBLU 0x2000
# define COL_FPIN 0x4000
# define COL_FCYA 0x8000
# define COL_FGRE 0x10000
# define COL_FDEF 0x20000
# define COL_GR 0x40000
# define COL_SS 0x80000
# define COL_SR 0x100000
# define COL_CLI 0x200000

typedef struct	s_printf_color
{
	char		*id;
	int			len;
	int			val;
	char		*attrib;
}				t_printf_color;

typedef struct	s_printf_mod
{
	int			flag;
	int			width;
	int			prec;
	int			spec;
//	int			color;
	char		sign;
	char		*xdigit;
	char		ox[2];
}				t_printf_mod;

typedef enum	e_printf_pad_char
{
	ZeroChar,
	BlankChar
}				t_printf_pad_char;


typedef unsigned long	t_ulong;
typedef unsigned short	t_ushort;
typedef int		(*t_printf_spec_function)(t_printf_mod, va_list);
typedef int		(*t_printf_set_function)(t_printf_mod *, const char *);

void			save_buf(void *buf, size_t size);
void			deb_saving(void *cp, int size);
t_list			**buflist(void);
void			print(t_list *elem);
void			del(t_list *elem);
void			flush_fd(int fd);
void			flush_str(char *str);
void			flush_nstr(char *str, size_t size);
void			ini_print(t_printf_spec_function *print_fmt);
void			ini_set(t_printf_set_function *set_mod);
void			ini_color_i\
				(t_printf_color *color, char *id, int val, char *attrib);
void			ini_color(t_printf_color *color);
t_printf_color	*color_attrib(int i);
int				color_flag(const char *fmt);
void			ft_printf_finaly_print\
				(char *cp, int size, int realsize, \
				t_printf_mod mod);
char			*tool_ujtoa\
				(uintmax_t val, int base, \
				t_printf_mod mod, char *cp);
char			*tool_ultoa\
				(t_ulong val, int base, \
				t_printf_mod mod, char *cp);
int				ft_printf_diuoxp_val\
				(uintmax_t ujval, t_ulong ulval, int base, \
				t_printf_mod mod);
int				ft_printf_p_val\
				(uintmax_t ujval, t_printf_mod mod);
int				ft_printf_cs_val\
				(char *cp, int size, t_printf_mod mod);
int				get_spec_index(char *cset, char c);
int				get_mod_index(char *cset, char c);
intmax_t		get_sjarg(va_list ap, t_printf_mod mod);
long			get_sarg(va_list ap, t_printf_mod mod);
uintmax_t		get_ujarg(va_list ap, t_printf_mod mod);
t_ulong			get_uarg(va_list ap, t_printf_mod mod);
int				print_d(t_printf_mod mod, va_list ap);
int				print_ld(t_printf_mod mod, va_list ap);
int				print_u(t_printf_mod mod, va_list ap);
int				print_lu(t_printf_mod mod, va_list ap);
int				print_x(t_printf_mod mod, va_list ap);
int				print_lx(t_printf_mod mod, va_list ap);
int				print_o(t_printf_mod mod, va_list ap);
int				print_lo(t_printf_mod mod, va_list ap);
int				print_p(t_printf_mod mod, va_list ap);
int				print_c(t_printf_mod mod, va_list ap);
int				print_lc(t_printf_mod mod, va_list ap);
int				print_s(t_printf_mod mod, va_list ap);
int				print_ls(t_printf_mod mod, va_list ap);
int				print_def(t_printf_mod mod, va_list ap);
int				set_space(t_printf_mod *mod);
int				set_plus(t_printf_mod *mod);
int				set_alt(t_printf_mod *mod);
int				set_minus(t_printf_mod *mod);
int				set_zero(t_printf_mod *mod);
int				set_h(t_printf_mod *mod);
int				set_l(t_printf_mod *mod);
int				set_j(t_printf_mod *mod);
int				set_z(t_printf_mod *mod);
/*int*/void				set_color(/*t_printf_mod *mod*/int *color, const char *fmt);
int				set_prec(t_printf_mod *mod, const char *fmt);
int				set_width(t_printf_mod *mod, const char *fmt);

void				ft_printf_write_color(int color);
void				ft_printf_apply_color(const char *format);


int				set_fmt_mod\
				(const char *fmt, t_printf_mod *mod, \
				t_printf_set_function *set_mod);
int				ft_vlprintf(const char *format, va_list ap);
int				ft_vfprintf(int fd, const char *format, va_list ap);
int				ft_vsprintf(char *str, const char *format, va_list ap);
int				ft_vsnprintf\
				(char *str, size_t size, const char *format, va_list ap);

int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *str, size_t size, const char *format, ...);

#endif
