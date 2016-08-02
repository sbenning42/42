/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/29 21:09:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			dump_root(t_tree *root, int i, t_dic_entry *bin)
{
	t_lxem		*list;

	if (!root)
	{
		ft_printf("\n");
		return ;
	}
	if (root->l)
		dump_root(root->l, i + 1, bin);
	if (!root->l && !root->r)
	{
		ft_printf("{green|gr}%*s%s{eoc}", i * 5, "", "-");
		list = root->content;
		ft_printf("{red|gr}");
		while (list)
		{
			ft_printf("%s%c", list->value.str, (list->next ? ' ' : 0));
			list = list->next;
			ft_printf("{eoc}{red}");
		}
		ft_printf("{eoc}{green|gr}-|:{eoc}\n");
	}
	else
	{
		ft_printf("{cyan|gr}%*s-{red|gr}%s{eoc}{cyan|gr}-[{eoc}\n", i * 5, "", root->content->value.str);
	}
	if (root->r)
		dump_root(root->r, i + 1, bin);
}

void			dump_root_log(t_tree *root, int i, t_dic_entry *bin, int fd)
{
	t_lxem		*list;

	if (!root)
	{
		ft_fprintf(fd, "\n");
		return ;
	}
	if (root->l)
		dump_root_log(root->l, i + 1, bin, fd);
	if (!root->l && !root->r)
	{
		ft_fprintf(fd, "%*s%s", i * 5, "", "-");
		list = root->content;
		while (list)
		{
			ft_fprintf(fd, "%s", list->value.str);
			if ((list = list->next))
				ft_fprintf(fd, " ");
		}
		ft_fprintf(fd, "-|:\n");
	}
	else
	{
		ft_fprintf(fd, "%*s-%s-[\n", i * 5, "", root->content->value.str);
	}
	if (root->r)
		dump_root_log(root->r, i + 1, bin, fd);
}

int					bin_create(t_dic_entry **root, char *path)
{
	DIR				*bpath;
	struct dirent	*entry;
	t_dic_entry		*node;
	size_t			len;

	if (!(bpath = opendir(path)))
		return (-1);
	len = ft_strlen(path) + 1;
	while ((entry = readdir(bpath)))
	{
		if (!(node = ft_dicnew(entry->d_name, (void *)path, len)))
		{
			closedir(bpath);
			return (-1);
		}
		ft_dicadd(root, node, dic_sort);
	}
	closedir(bpath);
	return (0);
}

int				bin_load(t_dic_entry **root)
{
	char		*raw_path;
	char		*path;
	char		*find;


	if (!(raw_path = ft_getenv("PATH")))
		return (-1);
	if (!(raw_path = ft_strdup(raw_path)))
		return (-1);
	path = raw_path;
	while (*path)
	{
		find = NULL;
		if ((find = ft_strchr(path, ':')))
			*find = 0;
		if (bin_create(root, path) < 0)
		{
			if (*root)
				ft_dicdel(root, dic_del);
			return (-1);
		}
		if (!find)
			break ;
		path = find + 1;
	}
	return (0);
}

void			sh_init(t_sh *sh, int ac, char **av)
{
	int			i;

	sh->bin = NULL;
	if ((sh->o = ft_getopt(ac, av, SH_OPTION)) < 0)
		exit(EXIT_FAILURE);
	if (bin_load(&sh->bin) < 0)
		ft_error("loading binary... Fail");
	if (hist_load(&sh->hist) < 0)
		ft_error("loading history... Fail");
	if (ISO(sh->o, SH_O_PROMPT))
	{
		i = 0;
		while (++i < ac)
		{
			if (av[i][0] != '-')
				break ;
		}
		sh->prompt = av[i];
	}
	else
		sh->prompt = SH_DEFAULT_PROMPT;
	sh->settings = SH_DEFAULT_SETTINGS;
}

int				sh_parser(t_sh *sh, t_tree **root, t_lxem **list)
{
	int			error;

	*root = NULL;
	error = ft_parser(root, *list);
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

int				sh_lexer(t_sh *sh, t_lxem **list)
{
	*list = ft_lexer(sh->line);
	if (!*list)
	{
		ft_memdel((void **)&sh->line);
		ft_error("memory allocation fail. `ft_lexer`");
		return (-1);
	}
	return (0);
}

int				sh_break(char **line)
{
	if (!ft_strcmp("exit", *line))
	{
		ft_memdel((void **)line);
		return (1);
	}
	return (0);
}

int				sh_readline(t_sh *sh)
{
	sh->line = ft_readline(sh->prompt, &sh->hist, sh->settings);
	if (!sh->line)
		return (-1);
	return (0);
}

void			sh_loop(t_sh *sh)
{
	t_lxem		*lexem_list;
	t_tree		*cmd_tree;

	while (42)
	{
		if (sh_readline(sh) < 0)
			continue ;
		if (sh_break(&sh->line))
			break ;
		if (sh_lexer(sh, &lexem_list) < 0)
		{
			*gg_status() = 1;
			continue ;
		}
		if (sh_parser(sh, &cmd_tree, &lexem_list) < 0)
		{
			*gg_status() = 1;
			continue ;
		}
		if (exec_root(sh, cmd_tree))
			*gg_status() = 1;
		else
			*gg_status() = 0;
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

	ft_initname(av[0]);
	sh_init(&sh, ac, av);
	sh_loop(&sh);
	hist_save(&sh.hist);
	sh_clear(&sh);
	return (0);	
}
