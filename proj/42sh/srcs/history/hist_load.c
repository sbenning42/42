/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:21:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 12:25:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history.h"

static int	hist_parse(t_hist *hist, int fd)
{
	int		ret;
	char	*line;
	size_t	len;
	t_dlist	*entry;

	while (42)
	{
		if ((ret = get_next_line(fd, &line)) <= 0)
			return (ret);
		if ((len = ft_strlen(line)))
		{
			if (!(entry = ft_dlstnew(line, len + 1)))
			{
				free(line);
				ft_dlstdel(&hist->list, NULL);
				return (-1);
			}
			ft_dlstaddn(&hist->list, entry);
		}
		free(line);
	}
	return (0);
}

int			hist_load(t_hist *hist)
{
	int		fd;

	hist->list = NULL;
	hist->cursor = NULL;
	if ((fd = open(".42sh_history", O_RDONLY)) < 0)
		return (-1);
	if (hist_parse(hist, fd) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
