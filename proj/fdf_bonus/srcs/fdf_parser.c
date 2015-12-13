/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 03:21:09 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:11:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_parser(t_env *env, int fd)
{
	t_list		*lst;
	t_list		*el;
	char		*line;
	int			ret;

	lst = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(el = fdf_lexer(env->av, env->id, line)))
			break ;
		else if (el->next)
			ft_lstadd_back(&lst, el);
		else
			ft_lstdelone(&el, fdf_free_line);
	}
	if (ret < 0)
		ft_err(env->av, env->id, "Can't read (gnl)");
	else if (!ret && fdf_map_attr(env, lst))
		fdf_map_constructor(env, lst);
	ft_lstdel(&lst, fdf_free_line);
	return ((ret > 0 ? 0 : 1));
}
