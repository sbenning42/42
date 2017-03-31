#include <stdio.h>

# define MASK_0 (0xff << 0x18)
# define MASK_1 (0xff << 0x10)
# define MASK_2 (0xff << 0x8)
# define MASK_3 (0xff)

# define SHORT_FIRST(X) ((X & MASK_2) >> 0x8)
# define SHORT_SECOND(X) ((X & MASK_3) << 0x8)
# define SHORT_BIG2LITTLE(X) (SHORT_FIRST(X) + SHORT_SECOND(X))

# define INT_FIRST(X) ((X & MASK_0) >> 0x18)
# define INT_SECOND(X) ((X & MASK_1) >> 0x8)
# define INT_THIRD(X) ((X & MASK_2) << 0x8)
# define INT_FOURTH(X) ((X & MASK_3) << 0x18)
# define INT_COUPLE_FIRST(X) (INT_FIRST(X) + INT_SECOND(X))
# define INT_COUPLE_SECOND(X) (INT_THIRD(X) + INT_FOURTH(X))
# define INT_BIG2LITTLE(X) (INT_COUPLE_FIRST(X) + INT_COUPLE_SECOND(X))



int main()
{
	short	s = 4242;
	unsigned char	tab[2];

	printf("[%#x][%#x]", s, SHORT_BIG2LITTLE(s));
	tab[0] = (s & 0xff00) >> 8;
	tab[1] = s & 0xff;
	printf("[%#x][%#x]\n", tab[0], tab[1]);
	return (0);
}
