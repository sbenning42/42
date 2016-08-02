/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:58:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 09:19:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			parse_error(char *token)
{
	char	msg[1024];

	ft_bzero((void *)msg, 1024);
	ft_sprintf(msg, "parse error near token `%s`", token);
	ft_error(msg);
	return (-1);
}

void		parse_del(t_tree **root)
{
	if (*root && (*root)->l)
		parse_del(&(*root)->l);
	if (*root && (*root)->r)
		parse_del(&(*root)->r);
	cmd_destroy(&(*root)->cmd.arg);
	cmd_destroy(&(*root)->cmd.env);
	ft_memdel((void **)root);
}

t_lxem		*parse_prior(t_lxem *list)
{
	t_lxem	*tmp;

	tmp = NULL;
	while (list)
	{
		if (list->type == TY_Strict_sep)
			return (list);
		if (list->type == TY_And_sep || list->type == TY_Or_sep)
			tmp = list;
		else if (!tmp && list->type >= TY_Pipe)
			tmp = list;
		list = list->next;
	}
	return (tmp);
}

t_tree		*tree_create(t_lxem *lxem)
{
	t_tree	*node;

	if (!(node = ft_memalloc(sizeof(t_tree))))
		return (NULL);
	node->content = lxem;
	node->l = NULL;
	node->r = NULL;
	node->cmd.bitset |= (EX_WAIT | EX_NOPIPE);
	if (!(node->cmd.arg = cmd_arg(node->content)))
	{
		ft_memdel((void **)&node);
		return (NULL);
	}
	if (!(node->cmd.env = cmd_env()))
	{
		cmd_destroy(&node->cmd.arg);
		ft_memdel((void **)&node);
	}
	return (node);
}

int			ft_parser(t_tree **root, t_lxem *list)
{
	t_lxem	*prior;

	prior = NULL;
	if (!list)
		return (0);
	if (!(prior = parse_prior(list)))
	{
		if (!(*root = tree_create(list)))
			return (-1);
		return (0);
	}
	if (!prior->previous)
		return (parse_error(prior->value.str));
	prior->previous->next = NULL;
	prior->previous = NULL;
	if (!(*root = tree_create(prior)))
		return (-1);
	if (!ft_parser(&(*root)->l, list))
	{
 		if (!ft_parser(&(*root)->r, prior->next))
			return (0);
		parse_del(&(*root)->l);
		return (-1);
	}
	return (-1);
}
