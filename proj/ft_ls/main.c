#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
	struct stat s1;
	struct stat s2;
	stat("fic1", &s1);
	stat("fic2", &s2);
	printf("[%ld][%ld]\n", s1.st_mtimespec.tv_sec, s2.st_mtimespec.tv_sec);
	printf("[%ld][%ld]\n", s1.st_mtimespec.tv_nsec, s2.st_mtimespec.tv_nsec);
	return (0);
}
