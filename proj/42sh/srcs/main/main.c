/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 14:32:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			sh_loop(t_sh *sh)
{
	t_lxem		*lexem_list;
	t_tree		*cmd_tree;

	while (42)
	{
		if (sh_readline(sh) < 0)												//Get the user command line
		{
			*gg_status() = 0;														//Default command status is set to 1 // BUG-02: gg_status() must be in the t_sh structure
			continue ;
		}
		*gg_status() = 1;														//Default command status is set to 1 // BUG-02: gg_status() must be in the t_sh structure
		if (sh_lexer(sh, &lexem_list) < 0)										//Split the line into lexem
			continue ;
		if (sh_parser(sh, &cmd_tree, &lexem_list) < 0)							//Parse the lexem list to get a binary command tree
			continue ;
		*gg_status() = (exec_root(sh, cmd_tree) ? 1 : 0);						//Execute all the command tree and get the status of the execution
		if (ISO(sh->o, SH_O_VERBOSE))											//If '-v' is specified in the arg_v, print a debug of the tree
			dump_root(cmd_tree, 0, sh->bin);
		parse_del(&cmd_tree);													//Clear the memory used by the tree
		ft_memdel((void **)&sh->line);											//Clear the memory used by the command line
	}
}

void			sh_clear(t_sh *sh)
{
	ft_dlstdel(&sh->hist.list, NULL);											//Cleaning dlist of char *
	ft_dicdel(&sh->bin, NULL);													//Cleaning dic of char *
}

int				main(int ac, char *av[])
{
	t_sh		sh;

	ft_init(av[0]);															//Init program name in libft (for error reporting purpose)
	sh_init(&sh, ac, av);														//Init 42sh options, binary collection, past history, prompt name and ft_readline settings
	sh.ac = ac;
	sh.av = av;
	sh_loop(&sh);																//MAIN LOOP
/*	hist_save(&sh.hist);														//Write the new command history in '.42sh_history'
	ft_printf("sh.ac = %d, sh.av = %p\n");
	sh_clear(&sh);																//Cleaning memory
*/	return (0);	
}
