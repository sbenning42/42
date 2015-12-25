/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 12:09:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/25 13:30:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			handlebuf(int ret, char *buf, t_tetrimino *t)
{
	int				i;
	int				cpt;

	if (ret < 0)
		return (ft_err("Parser", "Read", "error", 1));
	else if (ret == 0)
		return (1);
	else if (ret != 20)
		return (ft_err("Parser", "Tetrimino format", "error", 1));
	*t = 0;
	i = 0;
	cpt = 0x1;
	buf[ret] = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && !((i + 1) % 5))
		{
			i++;
			continue ;
		}
		else if (buf[i] == '.')
			;
		else if (buf[i] == '#')
			*t |= cpt;
		else
			return (ft_err("Parser", "Tetrimino format", "error", 1));
		i++;
		cpt <<= 0x1;
	}
	return (0);
}

static int			handlenl(int ret, char *nl)
{
	if (ret == 0)
		return (0);
	else if (ret == 1 && *nl == '\n')
		return (0);
	else
		return (ft_err("Parser", (ret < 0 ? "Read" : "Tetrimino format"), "error", 1));
}

static int			add_tetrimino(t_list **al, t_tetrimino t)
{
	t_list			*e;

	e = ft_lstnew((void *)&t, sizeof(t_tetrimino));
	if (!e)
		return (ft_err("Parser", "Malloc", "error", 1));
	ft_lstadd_back(al, e);
	return (0);
}

static int			get_tetrimino(int fd, t_list **al)
{
	t_tetrimino		t;
	int				ret;
	char			buf[21];
	char			nl[2];

	ret = read(fd, buf, 20);
	if (handlebuf(ret, buf, &t))
		return (ret ? -1 : 0);
	ret = read(fd, nl, 1);
	if (handlenl(ret, nl))  // if ret == 0 return 0
		return (-1);
	if (add_tetrimino(al, t))
		return (-1);
	return (1);
}

static t_tetrimino	*convert_ltoset(t_list **al, int i)
{
	t_tetrimino		*set;
	t_list			*cp;

	set = (t_tetrimino *)ft_memalloc(sizeof(t_tetrimino) * (i + 1));
	if (!set)
	{
		ft_lstdel(al, NULL);
		return ((t_tetrimino *)(long)ft_err("Parser", "Malloc", "error", 0));
	}
	ft_memset((void *)set, UCHAR_MAX, sizeof(t_tetrimino) * (i + 1));
	cp = *al;
	i = 0;
	while (cp)
	{
		set[i++] = *(t_tetrimino *)cp->content;
		cp = cp->next;
	}
	ft_lstdel(al, NULL);
	return (set);
}

t_tetrimino		*parse(char *file)
{
	t_list		*l;
	int			fd;
	int			ret;
	int			i;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		return ((t_tetrimino *)(long)ft_err("Parser", "Open", "error", 0));
	l = NULL;
	i = 0;
	while (42)
	{
		ret = get_tetrimino(fd, &l);
		if (ret < 0)
		{
			ft_lstdel(&l, NULL);
			return (NULL);
		}
		else if (!ret)
			break ;
		i++;
	}
	return (convert_ltoset(&l, i));
}
