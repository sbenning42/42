/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 18:00:13 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/15 18:19:57 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int					io_retarr_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	t_dlist			*cp;

	if (*curs && (*curs)->p)
	{
		ft_printf("\b \b");
		cp = (*curs)->p;
		*diff -= 1;
		(*curs)->p->n = (*curs)->n;
		if ((*curs)->n)
		{
			(*curs)->n->p = (*curs)->p;
			io_dlstdprint((*curs)->n);
		}
		ft_dlstdelone(curs, io_del_input);
		*curs = cp;
	}
	return (0);
}

int					io_suppr_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	t_dlist			*cp;

	if (*curs && (*curs)->n)
	{
		cp = *curs;
		*curs = (*curs)->n;
		if ((*curs)->n)
			(*curs)->n->p = (*curs)->p;
		(*curs)->p->n = (*curs)->n;
		io_dlstdprint((*curs)->n);
		ft_dlstdelone(curs, io_del_input);
		*curs = cp;
	}
	return (0);
}

int					io_nl_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	return (1);
}

int					io_ctrlc_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	return (1);
}

int					io_ctrld_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	return (1);
}

int					io_ctrlz_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	return (1);
}

int					io_tab_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	return (0);
}

int					io_up_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	t_dlist			*cp;

	cp = *io_save_input(NULL);
	if (cp && cp->p && cp->p->content)
	{
		cp = cp->p;
		*io_save_input(NULL) = cp;
		io_clear_input(*linput, *diff);
		ft_dlstdel(linput, io_del_input);
		*linput = ft_dlstmap(*(t_dlist **)cp->content, NULL);
		if (!(cp = *linput))
			return (-1);
		io_dlstnprint(cp);
		*diff = 0;
		while (cp && cp->n)
		{
			cp = cp->n;
			*diff += 1;
		}
		*curs = cp;
	}
	return (0);
}

int					io_right_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	if (*curs && (*curs)->n)
	{
		*curs = (*curs)->n;
		ft_printf("%c", *(char *)(*curs)->content);
		*diff += 1;
	}
	return (0);
}

int					io_down_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	t_dlist			*cp;

	cp = *io_save_input(NULL);
	if (cp && cp->n && cp->n->content)
	{
		cp = cp->n;
		*io_save_input(NULL) = cp;
		io_clear_input(*linput, *diff);
		ft_dlstdel(linput, io_del_input);
		if (cp->content)
		{
			*linput = ft_dlstmap(*(t_dlist **)cp->content, NULL);
			if (!(cp = *linput))
				return (-1);
		}
		else
			*linput = NULL;
		io_dlstnprint(cp);
		*diff = 0;
		while (cp && cp->n)
		{
			cp = cp->n;
			*diff += 1;
		}
		*curs = cp;
	}
	return (0);
}

int					io_left_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	if (*curs && (*curs)->p)
	{
		*curs = (*curs)->p;
		ft_printf("\b");
		*diff -= 1;
	}
	return (0);
}
