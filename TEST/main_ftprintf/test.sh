#!/bin/sh

rm -f outprintf outftprintf
make re -C ft_printf
gcc main_ftprintf.c ft_printf/libftprintf.a -iquote ft_printf/includes -o main_ftprintf
./main_ftprintf
diff outprintf outftprintf
