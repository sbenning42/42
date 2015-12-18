/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:18:00 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/18 14:24:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		s_lex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	return ((ft_strcmp(e1->name, e2->name) < 0));
}

int		s_rlex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	return ((ft_strcmp(e1->name, e2->name) > 0));
}

int		s_modt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	return (0);				// HAVE TO IMPLEMENTE TIME SORT!!!
}

int		s_rmodt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	return (!avs_modt(s1, s2));
}
