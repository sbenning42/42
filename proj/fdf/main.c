#include <stdio.h>
#include <strings.h>
int main()
{
	char	p1[] = "\100";
	char	p2[] = "\0";
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)p1;
	s2 = (unsigned char *)p2;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			printf("[%d]\n", *s1 - *s2);
			break ;
		}
		s1++;
		s2++;
	}

	printf("[%d]\n", *s1 - *s2);
	printf("[%d]\n", strcmp(p1, p2));
	return (0);
}
