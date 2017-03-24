/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:22:10 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/27 12:09:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flush_fd(int fd)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *buflist();
	while (drive)
	{
		tmp = drive->next;
		write(fd, drive->content, drive->content_size);
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		drive = tmp;
	}
	*buflist() = NULL;
}

void		flush_str(char *str)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *buflist();
	while (drive)
	{
		tmp = drive->next;
		ft_memcpy(str, drive->content, drive->content_size);
		str += drive->content_size;
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		drive = tmp;
	}
	*buflist() = NULL;
	*str = '\0';
}

void		flush_nstr(char *str, size_t size)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *buflist();
	while (drive)
	{
		tmp = drive->next;
		if (drive->content_size < size)
		{
			ft_memcpy(str, drive->content, drive->content_size);
			str += drive->content_size;
			size -= drive->content_size;
		}
		else
		{
			ft_memcpy(str, drive->content, size);
			str += size;
			size = 0;
		}
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		drive = tmp;
	}
	*buflist() = NULL;
	*str = '\0';
}
