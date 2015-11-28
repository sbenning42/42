#include "lem.h"
#include <fcntl.h>

static int	lem_open(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Lem: Error. Can't open file\n");
		exit(1);
	}
	return (fd);
}

int			main(int ac, char **av)
{
	if (ac < 2)
		lem(0);
	else
	{
		while (ac-- > 1)
			lem(lem_open(*++av));
	}
	return (0);
}
