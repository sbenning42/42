#include "ft_printf.h"

void	flush_fd(int fd)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *LIST__();
	while (drive)
	{
		tmp = drive->next;
		write(fd, drive->content, drive->content_size);
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		free(drive);
		drive = tmp;
	}
	*LIST__() = NULL;
}

void	flush_str(char *str)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *LIST__();
	while (drive)
	{
		tmp = drive->next;
		ft_memcpy(str, drive->content, drive->content_size);
		str += drive->content_size;
		free(drive->content);
		ft_bzero(drive, sizeof(t_list));
		free(drive);
		drive = tmp;
	}
	*LIST__() = NULL;
	*str = '\0';
}

void	flush_nstr(char *str, size_t size)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *LIST__();
	while (drive)
	{
		if (tmp->content_size >= size)
			break ;
		size -= size > drive->content_size ? drive->content_size : size;
		tmp = drive->next;
		ft_memcpy(str, drive->content, size > drive->content_size ? drive->content_size : size);
		str += size ? drive->content_size : 0;
		free(drive->content);
		ft_bzero(drive, sizeof(t_list));
		free(drive);
		drive = tmp;
	}

	*LIST__() = NULL;
	*str = '\0';
}
