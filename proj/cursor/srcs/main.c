/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:19:40 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 21:54:34 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_lxem			*lexread(char *prompt, t_hist *hist, int settings, int fd)
{
	t_lxem		*list;
	char		*line;

	list = NULL;
	line = ft_readline(prompt, hist, settings);
	if (line)
	{
		if (*line)
		{
			if (fd > 0)
				ft_fprintf(fd, "\t< %s >\n\n", line);
			list = ft_lexer(line);
			if (!list)
				ft_fprintf(2, "Memory fail in ft_lexer\n");
		}
		free(line);
	}
	return (list);
}

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

int				sh_init(t_sh *sh, int ac, char **av)
{
	int			fd;
	int			i;

	fd = -1;
	if (bin_load(bin) < 0)
		ft_error("loading binary... Fail");
	else if (ISO(o, SH_O_VERBOSE))
	{
		ft_error("loading binary... Success");
		if ((fd = open(".42sh_log.binary", O_WRONLY | O_CREAT | O_TRUNC, 0755)) < 0)
			ft_error("create `.42sh_log.binary`... Fail");
		else
		{
			ft_error("create `.42sh_log.binary`... Success");
			ft_dicdump(*bin, fd);
			close(fd);
		}
	}
	if (hist_load(hist) < 0)
		ft_error("loading history... Fail");
	else if (ISO(o, SH_O_VERBOSE))
	{
		ft_error("loading history... Success");
		if ((fd = open(".42sh_log.history", O_WRONLY | O_CREAT | O_TRUNC, 0755)) < 0)
			ft_error("create `.42sh_log.history`... Fail");
		else
		{
			ft_error("create `.42sh_log.history`... Success");
			hist_dump(*hist, fd);
			close(fd);
		}
		if ((fd = open(".42sh_log.parsing", O_WRONLY | O_CREAT | O_TRUNC, 0755)) < 0)
			ft_error("create `.42sh_log.parsing`... Fail");
		else
			ft_error("create `.42sh_log.parsing`... Success");
	}
	if (ISO(o, SH_O_PROMPT))
	{
		i = 0;
		while (av[++i][0] == '-')
			;
		*prompt = av[i];
	}
	else
		*prompt = "{42sh} $> ";
	return (fd);
}

int				main(int ac, char *av[])
{
	t_sh		sh;
	t_lxem		*list;
	t_tree		*root;

	ft_initname(av[0]);
	if (sh_init(&sh, ac, av))
		return (1);
	while (42)
	{
		root = NULL;
		if (!(list = lexread(prompt, &hist, RL_ECHO | RL_HISTORY, fd)))
			continue ;
		if (ft_parser(&root, list) < 0)
			continue;
		if (ISO(o, SH_O_VERBOSE))
		{
			dump_root_log(root, 0, bin, fd);
			ft_fprintf(fd, "\n=======================================================\n\n");
		}
		if (ISO(o, SH_O_DTREE))
			dump_root(root, 0, bin);
		exec_root(root, bin);
		if (root)
		{
			if (!ft_strcmp("exit", root->content->value.str))
			{
				parse_del(&root);
				break ;
			}
		}
		parse_del(&root);
	}
	hist_save(&hist);
	ft_dlstdel(&hist.list, NULL);
	ft_dicdel(&bin, NULL);
	if (ISO(o, SH_O_VERBOSE) && fd > 0)
		close(fd);
	return (0);	
}
