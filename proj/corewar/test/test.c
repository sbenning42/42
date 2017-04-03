#include <stdio.h>
#include "libft.h"
#include <limits.h>

# define MASK_0 (0xff000000)
# define MASK_1 (0xff0000)
# define MASK_2 (0xff00)
# define MASK_3 (0xff)

# define SHRT_FIRST(X) ((X & MASK_2) >> 0x8)
# define SHRT_SECOND(X) ((X & MASK_3) << 0x8)
# define SHRT_BIG2LITTLE(X) (SHRT_FIRST(X) + SHRT_SECOND(X))

# define INT_FIRST(X) ((X & MASK_0) >> 0x18)
# define INT_SECOND(X) ((X & MASK_1) >> 0x8)
# define INT_THIRD(X) ((X & MASK_2) << 0x8)
# define INT_FOURTH(X) ((X & MASK_3) << 0x18)
# define INT_COUPLE_FIRST(X) (INT_FIRST(X) + INT_SECOND(X))
# define INT_COUPLE_SECOND(X) (INT_THIRD(X) + INT_FOURTH(X))
# define INT_BIG2LITTLE(X) (INT_COUPLE_FIRST(X) + INT_COUPLE_SECOND(X))


void test(short s)
{
	unsigned char	tab[2];
	unsigned char	*repr;

	repr = (unsigned char *)&s;
	printf("BIG[%hd]-->[%#x][%#x]\n", s, repr[0], repr[1]);
	s = SHRT_BIG2LITTLE(s);
	repr = (unsigned char *)&s;
	printf("LITTLE[%hd]-->[%#x][%#x]\n", s, repr[0], repr[1]);
}

void testi(int s)
{
	unsigned char	tab[4];
	unsigned char	*repr;

	repr = (unsigned char *)&s;
	printf("BIG[%d]-->[%#x][%#x][%#x][%#x]\n", s, repr[0], repr[1], repr[2], repr[3]);
	s = INT_BIG2LITTLE(s);
	repr = (unsigned char *)&s;
	printf("LITTLE[%d]-->[%#x][%#x][%#x][%#x]\n", s, repr[0], repr[1], repr[2], repr[3]);
}

int main()
{
	test(6);
	test(-6);
	testi(6);
	testi(-6);
	return (0);
}
