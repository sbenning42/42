#include <unistd.h>

int main()
{
	char	buff[43];

	write(1, "\naaa\033[1A\b\b\b", 12);
	read(0, buff, 42);
	return (0);
}
