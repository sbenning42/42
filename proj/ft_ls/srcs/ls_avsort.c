/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_avsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:51:54 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/15 16:24:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		avs_lex(t_node *n1, t_node *n2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)n1->content;
	e2 = (t_ls_entry *)n2->content;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return ((ft_strcmp(e1->key, e2->key) < 0));
}

int		avs_rlex(t_node *n1, t_node *n2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)n1->content;
	e2 = (t_ls_entry *)n2->content;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return ((ft_strcmp(e1->key, e2->key) > 0));
}

int		avs_time(t_node *n1, t_node *n2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)n1->content;
	e2 = (t_ls_entry *)n2->content;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return (0);				// HAVE TO IMPLEMENTE TIME SORT!!!
	(void)n1;
	(void)n2;
}

int		avs_rtime(t_node *n1, t_node *n2)
{
	t_ls_entry	*e1;
	t_ls_entry	*e2;

	e1 = (t_ls_entry *)n1->content;
	e2 = (t_ls_entry *)n2->content;
	if (e2->type > e1->type)
		return (1);
	else if (e2->type < e1->type)
		return (0);
	return (!avs_time(n1, n2));
}
