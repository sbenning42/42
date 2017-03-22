/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:31:11 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 14:21:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_print(t_printf_spec_function *print_fmt)
{
	print_fmt[0] = print_d;
	print_fmt[1] = print_d;
	print_fmt[2] = print_ld;
	print_fmt[3] = print_x;
	print_fmt[4] = print_lx;
	print_fmt[5] = print_u;
	print_fmt[6] = print_lu;
	print_fmt[7] = print_o;
	print_fmt[8] = print_lo;
	print_fmt[9] = print_p;
	print_fmt[10] = print_s;
	print_fmt[11] = print_ls;
	print_fmt[12] = print_c;
	print_fmt[13] = print_lc;
	print_fmt[14] = (t_printf_spec_function)print_def;
}

void	ini_set(t_printf_set_function *set_mod)
{
	set_mod[0] = (t_printf_set_function)set_alt;
	set_mod[1] = (t_printf_set_function)set_space;
	set_mod[2] = (t_printf_set_function)set_plus;
	set_mod[3] = (t_printf_set_function)set_minus;
	set_mod[4] = (t_printf_set_function)set_zero;
	set_mod[5] = set_prec;
	set_mod[6] = (t_printf_set_function)set_h;
	set_mod[7] = (t_printf_set_function)set_l;
	set_mod[8] = (t_printf_set_function)set_j;
	set_mod[9] = (t_printf_set_function)set_z;
	set_mod[10] = set_aster;
	set_mod[11] = (t_printf_set_function)set_width;
}

void	ini_color_i(t_printf_color *color, char *id, int val, char *attrib)
{
	color->id = id;
	color->val = val;
	color->len = ft_strlen(id);
	color->attrib = attrib;
}

void	ini_color(t_printf_color *color)
{
	ini_color_i(color, "blank", COL_BLK, "30");
	ini_color_i(color + 1, "red", COL_RED, "31");
	ini_color_i(color + 2, "green", COL_GREE, "32");
	ini_color_i(color + 3, "yellow", COL_YEL, "33");
	ini_color_i(color + 4, "blue", COL_BLU, "34");
	ini_color_i(color + 5, "pink", COL_PIN, "35");
	ini_color_i(color + 6, "cyan", COL_CYA, "36");
	ini_color_i(color + 7, "grey", COL_GRE, "37");
	ini_color_i(color + 8, "eoc", COL_DEF, "0");
	ini_color_i(color + 9, "f-blank", COL_FBLK, "40");
	ini_color_i(color + 10, "f-red", COL_FRED, "41");
	ini_color_i(color + 11, "f-green", COL_FGREE, "42");
	ini_color_i(color + 12, "f-yellow", COL_FYEL, "43");
	ini_color_i(color + 13, "f-blue", COL_FBLU, "44");
	ini_color_i(color + 14, "f-pink", COL_FPIN, "45");
	ini_color_i(color + 15, "f-cyan", COL_FCYA, "46");
	ini_color_i(color + 16, "f-grey", COL_FGRE, "47");
	ini_color_i(color + 17, "gr", COL_GR, "1");
	ini_color_i(color + 18, "ss", COL_SS, "4");
	ini_color_i(color + 19, "sr", COL_SR, "7");
}
