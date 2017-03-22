#include <stdio.h>

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

int main()
{
	header_t	h;

	printf("header: %zu\n", sizeof(h));
	printf("magic: %zu\n", sizeof(h.magic));
	printf("prog_name: %zu\n", sizeof(h.prog_name));
	printf("prog_size: %zu\n", sizeof(h.prog_size));
	printf("comment: %zu\n", sizeof(h.comment));
	printf("sigma: %zu\n\n", sizeof(h.magic) + sizeof(h.prog_name) + sizeof(h.prog_size) + sizeof(h.comment));
	printf("header: %p\n", &h);
	printf("magic: %p\n", &h.magic);
	printf("prog_name: %p\n", &h.prog_name);
	printf("prog_size: %p\n", &h.prog_size);
	printf("comment: %p\n\n", &h.comment);
	printf("magic: %zu\n", (void *)&h.prog_name - (void *)&h.magic);
	printf("prog_name: %zu\n", (void *)&h.prog_size - (void *)&h.prog_name);
	printf("prog_size: %zu\n", (void *)&h.comment - (void *)&h.prog_size);
	printf("comment: %zu\n", (void *)((void *)&h + sizeof(h)) - (void *)&h.comment);
	return (0);
}
