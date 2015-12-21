#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
	struct stat s1;
	stat("/nfs/zfs-student-4/users/sbenning/Library/Application Support/Google/Chrome/SingletonSocket", &s1);
	printf("S_IFIFO [%#o]\n", s1.st_mode & S_IFIFO);
	printf("S_IFCHR [%#o]\n", s1.st_mode & S_IFCHR);
	printf("S_IFDIR [%#o]\n", s1.st_mode & S_IFDIR);
	printf("S_IFBLK [%#o]\n", s1.st_mode & S_IFBLK);
	printf("S_IFREG [%#o]\n", s1.st_mode & S_IFREG);
	printf("S_IFLNK [%#o]\n", s1.st_mode & S_IFLNK);
	printf("S_IFSOCK [%#o]\n", s1.st_mode & S_IFSOCK);
	printf("S_IFWHT [%#o]\n", s1.st_mode & S_IFWHT);
	return (0);
}
