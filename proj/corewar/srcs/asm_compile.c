/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_compile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 09:03:12 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/30 17:56:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		clean_token(t_token **lst)
{
	t_token		*drive;
	t_token		*tmp_next;
	t_token		*tmp_previous;

	tmp_previous = NULL;
	drive = *lst;
	while (drive)
	{
		tmp_next = drive->next;
		if (drive->id == N_COMMENT)
		{
			free(drive->value);
			free(drive);
			if (tmp_previous)
				tmp_previous->next = tmp_next;
		}
		else
			tmp_previous = drive;
		drive = tmp_next;
	}
}

static int		asm_parse_line(t_parser *asm_parser, t_token **lst, char *line)
{
	t_token		*token_line_lst;

	if (!(token_line_lst = ft_parse(asm_parser, &line, NULL)))
	{
		del_token(lst);
		return (-1);
	}
	if (token_line_lst->id != T_EMPTY)
		add_token(lst, token_line_lst);
	else
		del_token(&token_line_lst);
	inc_li_position(1);
	return (0);
}

static int		asm_parse(int fd, char *file, t_token **token_lst)
{
	t_parser	*asm_parser;
	int			ret;
	char		*line;

	asm_parser = g_asm_grammar;
	reset_posotion();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (asm_parse_line(asm_parser, token_lst, line))
			return (-1);
		ft_memdel((void **)&line);
	}
	if (ret < 0)
	{
		read_error(file);
		return (-1);
	}
	clean_token(token_lst);
	return (0);
}

int				asm_compile(int fd, char *file)
{
	t_token		*lst;
	header_t	header;
	t_payload	payload;

	lst = NULL;
	if (asm_parse(fd, file, &lst))
		return (-1);
	if (asm_header(&header, &lst))
	{
		del_token(&lst);
		return (-1);
	}
	dump_header(header);
	dump_token(lst);
	ft_bzero((void *)&payload, sizeof(t_payload));
	if (asm_payload(&payload, &lst))
	{
		del_token(&lst);
		return (-1);
	}
	dump_payload(&payload);
	del_token(&lst);
	return (0);
}
