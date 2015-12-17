/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_avsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:51:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/17 16:07:39 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		avs_lex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return ((ft_strcmp(e1->name, e2->name) < 0));
}

int		avs_rlex(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	if (e1->type == T_ERROR)
		return ((ft_strcmp(e1->name, e2->name) < 0));
	return ((ft_strcmp(e1->name, e2->name) > 0));
}

int		avs_modt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return (0);				// HAVE TO IMPLEMENTE TIME SORT!!!
}

int		avs_rmodt(void *s1, void *s2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)s1;
	e2 = (t_ls_entry *)s2;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return (!avs_modt(s1, s2));
}
