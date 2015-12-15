/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:18:14 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/15 17:06:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ls_add_entry(t_node **ar, char *av, char *path, \
							int (*s)(t_node *, t_node *))
{
	struct stat	buf;
	t_ls_entry	e;
	t_node		*no;

	ft_bzero((void *)&e, sizeof(t_ls_entry));
	errno = 0;
	if (lstat(path, &buf) == -1 || errno)
	{
		ft_printf("%s: %s: %s\n", av, path, strerror(errno));
		errno = 0;
	}
	else
	{
		ft_strncpy(e.key, path, KEYSIZE_LS);
		e.type |= ((buf.st_mode & S_IFDIR) == S_IFDIR ? T_DIR : T_NODIR);
		e.info = buf;
		if (!(no = tree_newnode(&e, sizeof(t_ls_entry))))
			return (ls_err(av, path, errno, "Memory allocation failed"));
		tree_add(ar, no, s);
	}
	return (1);
}

static t_node	*ls_tab_sort(int ac, char **av, t_ls_func f)
{
	t_node		*root;
	int			i;

	root = NULL;
	i = 0;
	while (++i < ac)
	{
		if (*av[i] != '-')
			break ;
	}
	while (i < ac)
	{
		if (!ls_add_entry(&root, av[0], av[i], f.av_s))
		{
			tree_del(&root, NULL);
			return (NULL);
		}
		i++;
	}
	return (root);
}

void		ft_avls(int ac, char **av, int o, t_ls_func f)
{
	t_node	*root;
	int		i;
	int		fake_ac;
	char	*fake_av[2];

	i = 0;
	while (++i < ac)
	{
		if (*av[i] != '-')
			break;
	}
	if (ac - i == 1)
	{
		fake_ac = 2;
		fake_av[0] = av[0];
		fake_av[1] = ".";
		root = ls_tab_sort(fake_ac, fake_av, f);
	}
	else
		root = ls_tab_sort(ac, av, f);
	if (root)
		ft_ls_avp(av[0], o, &root, f);
}
