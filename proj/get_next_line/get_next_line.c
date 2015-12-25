/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 02:17:33 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/20 03:31:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
***		SET LINE (MALLOC) RETURN 0 IF EOF 1 OTHERWISE
***		IF MALLOC OR READ ERROR RETURN -1
***
***		1)	HANDLE STATIC + BEGIN_LINE -> MAYBE RETURN (0|1|-1)
***		2)	HANDLE END_LINE + STATIC -> MAYBE RETURN (1|-1)
***		3)	RETURN 0 (BEGIN_LINE & END_LINE ARE BOTH EMPTY)
***
*/

#include "get_next_line.h"

static int			handle_begin(char *tmpread, char *begin_line, char **line)
{
	char			*f;

	if ((f = ft_strchr(tmpread, NLCHAR)))
	{
		*f = 0;
		if (!(*line = ft_strdup(tmpread)))
			return (-1);
		ft_strcpy(tmpread, f + 1);
		return (1);
	}
	ft_strcpy(begin_line, tmpread);
	ft_bzero((void *)tmpread, BUFFER_SIZE + 1);
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		tmpread[NOFILE][BUFFER_SIZE + 1];
	char			begin_line[BUFFER_SIZE + 1];
	char			*end_line;
	int				ret;

	static int i = 0;
	if (!i++)
		ft_strcpy(tmpread[fd], "this is my holy test\nBitch!!\n\nyou win");
	ft_bzero((void *)begin_line, BUFFER_SIZE + 1);
	if ((ret = handle_begin(tmpread[fd], begin_line, line)))
		return (ret);
	(void)end_line;
	return (0);
}
