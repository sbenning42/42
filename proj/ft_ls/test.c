#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	struct stat	s;
	int			ret;

	errno = 0;
	ret = lstat("toto", &s);
	printf("[%s] [%d]\n", strerror(errno), ret);
	return (0);
}
