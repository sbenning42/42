/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:47:07 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 18:21:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_dlist		**history(void)
{
	static t_dlist	*hist;

	return (&hist);
}

static int			histload(int fd)
{
	t_dlist			*entry;
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(entry = ft_dlstnew(line, ft_strlen(line))))
		{
			free(line);
			ft_dlstdel(history(), NULL);
			return (-1);
		}
		ft_dlstaddn(history(), entry);
		free(line);
	}
	return (ret);
}

int					rl_loadhistory(void)
{
	char			msg[2048];
	char			*file;
	int				fd;

	if (!(file = ft_getenv("MSHISTORY")))
		file = ".ms_history_file";
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		if (access(file, F_OK) > -1)
		{
			ft_sprintf(msg, "Can't open '%s' file to load history", file);
			ft_error(msg);
		}
		return (0);
	}
	if (histload(fd) < 0)
		ft_error("Fail to load history for some obscur reason");
	return (0);
}

void				rl_destroyhistory(void)
{
	ft_dlstdel(history(), NULL);
}
