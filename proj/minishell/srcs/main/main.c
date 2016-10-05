/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 11:51:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			sh_loop(t_sh *sh)
{
	t_lxem		*lexem_list;
	t_tree		*cmd_tree;

	while (42)
	{
		if (sh_readline(sh) < 0)
		{
			*gg_status() = 0;
			continue ;
		}
		*gg_status() = 1;
		if (sh_lexer(sh, &lexem_list) < 0)
			continue ;
		if (sh_parser(sh, &cmd_tree, &lexem_list) < 0)
			continue ;
		*gg_status() = (exec_root(sh, cmd_tree) ? 1 : 0);
		if (ISO(sh->o, SH_O_VERBOSE))
			dump_root(cmd_tree, 0, sh->bin);
		parse_del(&cmd_tree);
		ft_memdel((void **)&sh->line);
	}
}

void			sh_clear(t_sh *sh)
{
	ft_dlstdel(&sh->hist.list, NULL);
	ft_dicdel(&sh->bin, NULL);
}

int				main(int ac, char *av[])
{
	t_sh		sh;

	ft_init(av[0]);
	sh_init(&sh, ac, av);
	sh_loop(&sh);
	return (0);
}
