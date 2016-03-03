#include "ft_readline.h"

int main()
{
	int	co;

	tgetent(getenv("TERM"), NULL);
	tm_init();
	co = tgetnum("co");
	co += 1;
	int i = 0;
	char buff[1024];
	while (i < ((2 * co) + 1))
	{
		write(1, "A", 1);
		i++;
		sleep(2);
		if (i % co)
		{
			ft_sprintf(buff, "\033[%dD", i % co);
			write(1, buff, ft_strlen(buff));
		}
	}
	write(1, "\033[10A", 5);
	write(1, "\033[0B", 4);
	write(1, "\033[10C", 5);
	write(1, "\033[10D", 5);
	tm_quit();
	return (0);
}
