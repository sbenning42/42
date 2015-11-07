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
	print_fmt[14] = print_def;
}

void	ini_set(t_printf_set_function *set_mod)
{
	set_mod[0] = (t_printf_set_function)set_alt;
	set_mod[1] = (t_printf_set_function)set_space;
	set_mod[2] = (t_printf_set_function)set_plus;
	set_mod[3] = (t_printf_set_function)set_minus;
	set_mod[4] = (t_printf_set_function)set_zero;
	set_mod[5] = (t_printf_set_function)set_prec;
	set_mod[6] = (t_printf_set_function)set_h;
	set_mod[7] = (t_printf_set_function)set_l;
	set_mod[8] = (t_printf_set_function)set_j;
	set_mod[9] = (t_printf_set_function)set_z;
	set_mod[10] = (t_printf_set_function)set_color;
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
	ini_color_i(color, "Blk", COL_BLK, "30");
	ini_color_i(color + 1, "Red", COL_RED, "31");
	ini_color_i(color + 2, "Gree", COL_GREE, "32");
	ini_color_i(color + 3, "Yel", COL_YEL, "33");
	ini_color_i(color + 4, "Blu", COL_BLU, "34");
	ini_color_i(color + 5, "Pin", COL_PIN, "35");
	ini_color_i(color + 6, "Cya", COL_CYA, "36");
	ini_color_i(color + 7, "Gre", COL_GRE, "37");
	ini_color_i(color + 8, "Def", COL_DEF, "0");
	ini_color_i(color + 9, "Fblk", COL_FBLK, "40");
	ini_color_i(color + 10, "Fred", COL_FRED, "41");
	ini_color_i(color + 11, "Fgree", COL_FGREE, "42");
	ini_color_i(color + 12, "Fyel", COL_FYEL, "43");
	ini_color_i(color + 13, "Fblu", COL_FBLU, "44");
	ini_color_i(color + 14, "Fpin", COL_FPIN, "45");
	ini_color_i(color + 15, "Fcya", COL_FCYA, "46");
	ini_color_i(color + 16, "Fgre", COL_FGRE, "47");
	ini_color_i(color + 17, "Fdef", COL_FDEF, "0");
	ini_color_i(color + 18, "Gr", COL_GR, "1");
	ini_color_i(color + 19, "Ss", COL_SS, "4");
	ini_color_i(color + 20, "Sr", COL_SR, "7");
	ini_color_i(color + 21, "Cli", COL_CLI, "5");
}
