#include "ft_str.h"

char		*ft_strlower(char *const s)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
	{
		*cp = ft_tolower(*cp);
		cp++;
	}
	return (s);
}
