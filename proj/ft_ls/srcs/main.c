#include "ft_ls.h"

static void			debug_dump_opt(int *opt)
{
	ft_printf("OPT: ");
	if (*opt)
		ft_printf("a");
	if (*(opt + 1))
		ft_printf("l");
	if (*(opt + 2))
		ft_printf("r");
	if (*(opt + 3))
		ft_printf("R");
	if (*(opt + 4))
		ft_printf("t");
	ft_printf("\n");
}

void				ft_ls_fic_handle(t_list *lst)
{
	struct stat		entry_info;
	int				i;

	i = 0;
	while (lst)
	{
		if (!*(char *)lst->content)
		{
			lst = lst->next;
			continue ;
		}
		/*
		 *	Clean stat
		*/
		ft_bzero((void *)&entry_info, sizeof(struct stat));
		/*
		 *	If there is a fic print it
		*/
		if (stat((char *)lst->content, &entry_info) == -1)
			ft_ls_put_error_entry((char *)lst->content, errno);
		else if ((entry_info.st_mode & S_IFDIR) != S_IFDIR)
		{
			ft_printf("%s\n", (char *)lst->content);
			*(char *)lst->content = 0;
		}
		lst = lst->next;
	}
}

void				ft_ls_error_handle(t_list *lst)
{
	struct stat		entry_info;
	int				i;

	i = 0;
	while (lst)
	{
		/*
		 *	Clean stat
		*/
		ft_bzero((void *)&entry_info, sizeof(struct stat));
		/*
		 *	If there is an error call put err
		*/
		if (stat((char *)lst->content, &entry_info) == -1)
		{
			ft_ls_put_error_entry((char *)lst->content, errno);
			*(char *)lst->content = 0;
		}
		lst = lst->next;
	}
}

int		main(int ac, char *av[])
{
	t_list	*avl;
	int	opt[OPT_SIZE];
	int	ret;

	ft_bzero((void *)opt, sizeof(int) * OPT_SIZE);
	/*
	 *	set opt array while av
	*/
	if ((ret = get_opt(OPT_CSET, opt, ac, av)) == -1)
		return (0);
	else
	{
		av += ret;
		ac -= ret;
	}
	if (!(avl = ft_ls_sort_av(opt, ac, av)))
		return (0);
	/*
	 *	dump opt array
	*/
	debug_dump_opt(opt);
	/*
	 *	print error in arg
	*/
	ft_ls_error_handle(avl);
	ft_ls_fic_handle(avl);
//	ft_ls(opt, lav);
	return (0);
}
