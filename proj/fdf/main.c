#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	ret;
	char	buf[1024];

	fd = open("test", O_RDONLY);
	ret = read(fd, buf, 1024);
	buf[ret] = 0;
	printf("[%d] {%s}\n", ret, buf);
	ret = read(fd, buf, 1024);
	buf[ret] = 0;
	printf("[%d] {%s}\n", ret, buf);
	close(fd);
	return (0);
}
