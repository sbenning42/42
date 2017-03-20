/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:19 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/20 12:32:15 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*get_error_msg(int errcode)
{
	int		i;

	i = -1;
	while (g_err[++i].msg)
	{
		if (errcode == g_err[i].code)
			return (g_err[i].msg);
	}
	return (LEM_UNKNOW_CODE);
}

int			syn_error(char **line, int li, int errcode)
{
	if (PI_ISOPT(proginfo()->opt, O_VERB))
	{
		ft_fprintf(2, LEM_SYNERR_FMT,\
					proginfo()->name, li, (line ? *line : ""),\
					get_error_msg(errcode));
	}
	if (line)
		ft_memdel((void **)line);
	return (-1);
}

int			parse_line(char *line, t_graph *rooms, t_cons *rules, int *state)
{
	if (*line == LEM_COMMENT_CHAR)
		return (parse_tag(line, state));
	if (*state == LEM_POP_STATE)
		return (parse_pop(line, state, rules));
	else if (ft_strchr(line, LEM_ROOM_CHAR))
		return (parse_room(line, state, rooms, rules));
	else if (ft_strchr(line, LEM_HALL_CHAR))
		return (parse_hall(line, state, rooms));
	else
		return (LEM_LINE_FMT_ERR);
	return (LEM_NOERR);
}

int			parsing(int fd, t_graph *rooms, t_cons *rules)
{
	int		ret;
	int		errcode;
	int		li;
	int		state;
	char	*line;

	li = 0;
	state = LEM_POP_STATE;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!*line)
		{
			ft_memdel((void **)&line);
			break ;
		}
		if ((errcode = parse_line(line, rooms, rules, &state)))
			return (syn_error(&line, li, errcode));
		ft_memdel((void **)&line);
		li++;
	}
	if (ret >= 0 && (rules->id_s < 0 || rules->id_e < 0))
		return (syn_error(NULL, li, LEM_LOGIC_ERR));
	return ((ret < 0 ? ret : 0));
}
