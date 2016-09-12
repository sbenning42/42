/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:32:07 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/09 09:34:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				sh_readline(t_sh *sh)
{
	sh->line = ft_readline(sh->prompt, &sh->hist, sh->settings);				//Simple ft_readline wrapping
	if (!sh->line)
		return (-1);
	return (0);
}

int				sh_break(char **line)											//'exit' command handler // BUG-01: have to be in a builtin executed as all command in the execution tree... Have nothing to do in that part!
{
	if (!ft_strcmp("exit", *line))
	{
		ft_memdel((void **)line);
		return (1);
	}
	return (0);
}

int				sh_lexer(t_sh *sh, t_lxem **list)
{
	*list = ft_lexer(sh->line);													//Simple ft_lexer wrapping
	if (!*list)
	{
		ft_memdel((void **)&sh->line);
		ft_error("memory allocation fail. `ft_lexer`");
		return (-1);
	}
	return (0);
}

int				sh_parser(t_sh *sh, t_tree **root, t_lxem **list)
{
	int			error;

	*root = NULL;
	error = ft_parser(root, *list);												//Simple ft_parser wrapping
	if (error)
	{
		if (error < 0)
			ft_error("memory allocation fail. `ft_parser`");
		lx_del(list);
		ft_memdel((void **)&sh->line);
		return (-1);
	}
	return (0);
}
