#include <term.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *term = getenv("TERM");
	printf("%s\n", term);
	printf("%d\n", tgetent(NULL, term));
	return (0);
}
