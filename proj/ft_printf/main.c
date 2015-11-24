#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("%3c\n", '0');
	printf("%3c\n", '0');
	return (0);
}
/*
	test_printf("%00.3c\n", '0');
	test_printf("%01.3c\n", '0');
	test_printf("%03.3c\n", '0');
	test_printf("%05.3c\n", '0');

*/
