/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 19:45:37 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/15 18:58:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

int						ft_dlstlen(t_dlist *l)
{
	int					i;

	i = 0;
	while (l)
	{
		l = l->n;
		i++;
	}
	return (i);
}

static void				io_dump_input_memory(void)
{
	t_dlist				*cp;
	t_dlist				*tmp;
	int					i = 0;

	ft_printf("\n%[Gr|Red]s:\n\n", "DEBUG");
	cp = *io_save_input(NULL);
	tmp = cp;
	while (cp && cp->p)
		cp = cp->p;
	ft_printf("Init Block: %p\n", cp->content);
	while ((cp = cp->n))
	{
		ft_printf("Input %d: %p\tsize: %d ", i++, cp->content, ft_dlstlen(*(t_dlist **)cp->content));
		if (cp == tmp)
			ft_printf("// Here you are");
		ft_printf("\n");
	}
	ft_printf("\n%[Gr|Red]s:\n", "END");
}

void					io_clear_input(t_dlist *l, int size)
{
	int					i;
	int					j;

	i = 0;
	while (size--)
	{
		i++;
		ft_printf("\b");
	}
	j = 0;
	while (j++ < i)
		ft_printf(" ");
	while (i--)
		ft_printf("\b");
}

void					io_dlstnprint(t_dlist *l)
{
	while (l)
	{
		ft_printf("%c", *(char *)l->content);
		l = l->n;
	}
}

void					io_dlstprint(t_dlist *l)
{
	int					i;

	i = 0;
	while (l)
	{
		ft_printf("%c", *(char *)l->content);
		l = l->n;
		i++;
	}
	while (--i)
		ft_printf("\b");
}

void					io_dlstdprint(t_dlist *l)
{
	int					i;

	i = 0;
	while (l)
	{
		ft_printf("%c", *(char *)l->content);
		l = l->n;
		i++;
	}
	ft_printf(" \b");
	while (i--)
		ft_printf("\b");
}

t_dlist					**io_save_input(t_dlist *l)
{
	static t_dlist		*saved;
	t_dlist				*input;

	if (l)
	{
		input = ft_dlstnew((void *)&l, sizeof(t_dlist *));
		if (!input)
			return (NULL);
		ft_dlstaddip(&saved, input, ft_dlstlen(saved) - 1);
		saved = input->n;
	}
	return (&saved);
}

void					io_del_input(void *content, size_t size)
{
	if (!size)
		return ;
	free(content);
}

static int				io_init(t_dlist **linput, t_dlist **curs)
{
	t_dlist				*init;
	t_dlist				*init1;
	char				c;

	c = 0;
	init = ft_dlstnew((void *)&c, sizeof(char));
	if (!init)
		return (-1);
	ft_dlstaddn(linput, init);
	*curs = init;
	if (!*io_save_input(NULL))
	{
		init = ft_dlstnew(NULL, 0);
		init1 = ft_dlstnew(NULL, 0);
		if (!init || !init1)
		{
			free(init);
			free(init1);
			ft_dlstdel(linput, NULL);
			return (-1);
		}
		ft_dlstaddn(io_save_input(NULL), init);
		ft_dlstaddn(io_save_input(NULL), init1);
	}
	return (0);
}

static int				io_flush_linput(t_dlist **linput, char **input)
{
	t_dlist				*cp;
	int					i;

	i = 0;
	*input = ft_strnew(sizeof(char) * ft_dlstlen(*linput));
	if (!*input)
	{
		ft_dlstdel(linput, io_del_input);
		return (0);
	}
	cp = *linput;
	while (cp)
	{
		if (*(char *)cp->content != 0)
			(*input)[i++] = *((char *)cp->content);
		cp = cp->n;
	}
	(*input)[i] = 0;
	io_save_input(*linput);
	return (1);
}

static int				io_def_handle(t_dlist **linput, t_dlist **curs, int *diff, char *key)
{
	t_dlist				*ninput;
	
	if (!ft_isprint(*key))
		return (0);
	ninput = ft_dlstnew((void *)key, sizeof(char));
	if (!ninput)
		return (-1);
	ft_dlstaddin(linput, ninput, *diff);
	*curs = ninput;
	if (*curs != *linput)
		*diff += 1;
	io_dlstprint(*curs);
	return (0);
}

static int				io_smart_read(char *input)
{
	int					ret;

	ft_bzero((void *)input, IO_BS + 1);
	ret = read(0, input, IO_BS);
	if (ret == -1)
		return (-1);
	else if (ret < 1)
		return (0);
	input[ret] = 0;
	return (ret);
}

int						io_smart_input(char *prompt, char **input, t_dic_entry *dic)
{
	t_dlist				*linput;
	t_dlist				*curs;
	t_io_handle_f		handle_key;
	char				key[IO_BS + 1];
	int					diff;
	int					ret;
	int					finish;

	finish = 0;
	linput = NULL;
	if ((diff = io_init(&linput, &curs)) == -1)
		return (-1);
	ft_printf("%s", prompt);
	while (!finish)
	{
		if ((ret = io_smart_read(key)) < 0)
			return (ft_dlstdel(&linput, io_del_input), -1) ;
		if (!(handle_key = (t_io_handle_f)ft_dicget(dic, key)))
			handle_key = io_def_handle;
		else
			handle_key = *(t_io_handle_f *)handle_key;
		if ((finish = handle_key(&linput, &curs, &diff, key)) == -1)
			return (ft_dlstdel(&linput, io_del_input), -1) ;
	}
	return (io_flush_linput(&linput, input) ? 0 : 1);
}
