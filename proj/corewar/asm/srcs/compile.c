/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 10:42:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 14:34:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			(*g_func[])(t_lexem *, char) = {\
	default_state,\
	word_state,\
	label_state,\
	command_state,\
	comment_state,\
	literal_state,\
	args_state,\
	reg_arg_state,\
	dir_arg_state,\
	ind_arg_state,\
	lab_arg_state,\
	flush_state\
};

void		reset_lexer(t_lexem *lexem)
{
	ft_bzero(lexem, sizeof(t_lexem));
	lexem->token.line = 1;
	lexem->token.column = 1;
}

int			maj_lexer_state(t_lexem *lexem, char c)
{
	return (g_func[lexem->token.type](lexem, c));
}

int			lexer(int fd, t_lexem *lexem)
{
	char	buffer[ASM_BUFFER_SIZE + 1];
	int		ret;
	int		i;

	reset_lexer(lexem);
	while ((ret = read(fd, buffer, ASM_BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		i = -1;
		while (buffer[++i])
		{
			if (maj_lexer_state(lexem, buffer[i]))
				return (-1);
			if (buffer[i] == NL_CHAR)
			{
				lexem->token.line += 1;
				lexem->token.column = 0;
			}
			else
				lexem->token.column += 1;
		}
	}
	return (0);
}

void		del_token(void *content, size_t content_size)
{
	t_token	*token;

	token = (t_token *)content;
	free(token->value);
	return ;
	(void)content_size;
}

void		compile(int fd)
{
	t_lexem	lexem;

	ft_bzero(&lexem, sizeof(t_lexem));
	if (lexer(fd, &lexem))
	{
		ft_fprintf(2, "Lexer error\n");
		return ;
	}
	dump_lexem(lexem.lst);
	if (check_logical_integrity(&lexem))
	{
		ft_fprintf(2, "Check error\n");
		return ;
	}
	ft_lstdel(&lexem.lst, del_token);
}
