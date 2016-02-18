#include <unistd.h>
#include <stdio.h>

int main()
{
	char p[1024] = {0};
	char *a[1] = {"pwd"};
	char *e[1] = {"PWD=/etc"};

	chdir("/etc");
	if (!fork())
		execve("/bin/pwd", a, e);
	getcwd(p, 1024);
	printf("[%s]\n", p);
	//chdir("/private/etc");
	//execve("/bin/pwd", a, NULL);
	//getcwd(p, 1024);
	//printf("[%s]\n", p);
}
