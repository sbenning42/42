#include <stdio.h>
#include "libft.h"

int main()
{
	int	i = 0;

	while (i++ < 10)
		ft_printf("[{red|ss|f-yellow}%20s{eoc}]{cyan|f-pink}%15d{eoc}\n", "Salut!", 42);
	return (0);
}
