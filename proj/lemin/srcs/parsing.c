/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:56:19 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 10:30:20 by sbenning         ###   ########.fr       */
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

int			syn_error(char **line, int li, int err)
{
	if (PI_ISOPT(proginfo()->opt, O_VERB))
	{
		ft_fprintf(2, (err != LEM_LOGIC_ERR ? LEM_SYNERR_FMT : LEM_LOGERR_FMT),\
					proginfo()->name, li, (line ? *line : ""),\
					get_error_msg(err));
	}
	if (line)
		ft_memdel((void **)line);
	return (((err == LEM_MALLOC_ERR || err == LEM_LOGIC_ERR) ? -1 : 0));
}

int			parse_line(char *rawline, t_graph *rooms, t_cons *rules, int *state)
{
	char	*line;
	int		ret;

	if (!(line = ft_strtrim(rawline)))
		return (LEM_MALLOC_ERR);
	else if (*line == LEM_COMMENT_CHAR)
		ret = parse_tag(line, state);
	else if (*state == LEM_POP_STATE)
		ret = parse_pop(line, state, rules);
	else if (ft_strchr(line, LEM_ROOM_CHAR))
		ret = parse_room(line, state, rooms, rules);
	else if (ft_strchr(line, LEM_HALL_CHAR))
		ret = parse_hall(line, state, rooms);
	else
		ret = LEM_LINE_FMT_ERR;
	free(line);
	return (ret);
}

static int	bad_rules(t_cons *rules)
{
	return ((rules->id_s < 0 || rules->id_e < 0 || rules->id_s == rules->id_e));
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
			break ;
		if ((errcode = parse_line(line, rooms, rules, &state)))
		{
			syn_error(&line, li, errcode);
			break ;
		}
		ft_memdel((void **)&line);
		li++;
	}
	if (ret >= 0 && bad_rules(rules))
		return (syn_error(NULL, li, LEM_LOGIC_ERR));
	return ((ret < 0 ? ret : 0));
}
