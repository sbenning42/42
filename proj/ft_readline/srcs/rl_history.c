/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:56:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 14:55:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_parse_history_file(int fd, t_rl *rl)
{
	t_dlist	*entry;
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		if (line && *line)
		{
			entry = ft_dlstnew((void *)line, sizeof(char) * (ft_strlen(line) + 1));
			ft_memdel((void **)&line);
			if (!entry)
				return (-1);
			ft_dlstaddp(&rl->history, entry);
		}
		else if (line && !*line)
			ft_memdel((void **)&line);
		if ((ret = get_next_line(fd, &line)) < 0)
			return (-1);
	}
	return (0);
}

void		rl_history_save(char *line)
{
	int		fd;
	size_t	len;

	if ((fd = open(RL_SAVE_FILE, (O_CREAT | O_WRONLY | O_APPEND), 0740)) < 0)
		return ;
	len = ft_strlen(line);
	line[len] = '\n';
	write(fd, line, len + 1);
	line[len] = 0;
	close(fd);
}

int			rl_history_load(t_rl *rl)
{
	int		fd;

	if ((fd = open(RL_LOAD_FILE, O_RDONLY)) < 0)
		return (0);
	if (rl_parse_history_file(fd, rl) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
