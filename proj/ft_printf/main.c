#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	void	*data;
	int	ret;
	int	ret2;
	
	data = (void *)&ret;
	ret = ft_printf("[%.p]\n", data);
	ret2 = printf("[%.p]\n", data);
	ft_printf("[%d][%d]\n", ret, ret2);
	ret = ft_printf("[%.p]\n", NULL);
	ret2 = printf("[%.p]\n", NULL);
	ft_printf("[%d][%d]\n", ret, ret2);
	return (0);
}
/*
	test_printf("%00.3c\n", '0');
	test_printf("%01.3c\n", '0');
	test_printf("%03.3c\n", '0');
	test_printf("%05.3c\n", '0');

*/
