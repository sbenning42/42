/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:45:42 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/03 13:40:13 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			write_binary(t_payload payload, char *source_file)
{
	char			*tmp;
	char			*extention;
	char			*object_file;
	int				fd;

	if (!(object_file = ft_strdup(source_file)))
		exit(1);
	extention = ft_strstr(object_file, ASM_SOURCE_EXTENTION);
	if (extention)
		*extention = 0;
	tmp = object_file;
	if (!(object_file = ft_strjoin(object_file, ASM_OBJECT_EXTENTION)))
		exit(1);
	free(tmp);
	if ((fd = open(object_file, O_WRONLY | O_CREAT, 0755)) < 0)
		exit(1);
	ft_printf("Writing output to %s\n", object_file);
	write(fd, payload.payload, payload.size);
	close(fd);
	free(object_file);
	free(payload.payload);
}

static void			close_files(int *fd, int size)
{
	int				i;

	i = -1;
	while (++i < size)
	{
		if (fd[i] > 0)
			close(fd[i]);
	}
}

static void			compile_files(int *fd, int ac, char **av)
{
	int				i;
	t_payload		payload;

	i = -1;
	while (++i < ac)
	{
		if ((fd[i] = open(av[i], O_RDONLY)) < 0)
		{
			open_error(av[i]);
			continue ;
		}
		payload = asm_compile(fd[i], av[i]);
		if (!payload.payload)
			compile_error(av[i]);
		else
			write_binary(payload, av[i]);
	}
}

static void			set_program_info(int *ac, char ***av)
{
	proginfo_init(*ac, *av, NULL, ASM_OPT_CHARSET);
	if (PI_ISOPT(proginfo()->opt, ASM_VERY_VERBOSE_OPT))
		PI_SETOPT(proginfo()->opt, ASM_VERBOSE_OPT);
	*ac = proginfo()->oarg_c;
	*av = proginfo()->oarg_v;
}

int					main(int ac, char **av)
{
	int				*fd;

	set_program_info(&ac, &av);
	if (!(fd = ft_memalloc(sizeof(int) * ac)))
		return (-1);
	compile_files(fd, ac, av);
	close_files(fd, ac);
	return (0);
}
