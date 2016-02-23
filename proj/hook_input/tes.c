#include <stdio.h>

int main()
{
	void	*p;

	p = (void *)&printf;

	printf("[%p][%p]\n", *(char **)p, **(char ***)p/*, ***(char ****)p, ****(char *****)p*/);
	return (0);
}
