#include "ft_str.h"

char		*ft_strupper(char *const s)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
	{
		*cp = ft_toupper(*cp);
		cp++;
	}
	return (s);
}
