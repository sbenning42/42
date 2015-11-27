#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int	a = 42;
//	ft_printf("[%d]\n", 2, 9);
	ft_printf("[%042.p]\n", &a);
	printf("[%042.p]\n", &a);
	return (0);
}
