#include "ft_readline.h"

int main()
{
	char buff[1024];
	int	co;

	tgetent(getenv("TERM"), NULL);
	tm_init();
	write(1, "\033[10B", 5);
	tm_quit();
	return (0);
}
