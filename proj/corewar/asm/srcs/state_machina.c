/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machina.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:10:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/22 19:46:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					*s_state(void)
{
	static int		state;

	return (&state);
}

t_list				**s_token(void)
{
	static t_list	*token;

	return (&token);
}

t_list				**s_lexem(void)
{
	static t_list	*lexem;

	return (&lexem);
}

int					*s_line(void)
{
	static int		line;

	return (&line);
}

void				token_push(char c)
{
	t_list			*elem;

	elem = ft_lstnew(&c, 1);
	ft_lstadd_back(s_token(), elem);
}

void				token_save(void)
{
	t_list			*tmp;
	size_t			size;
	int				i;
	t_ins			ins;

	size = 0;
	tmp = *s_token();
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	ins.token = ft_memalloc(size + 1);
	i = -1;
	tmp = *s_token();
	while (tmp)
	{
		ins.token[++i] = *(char *)tmp->content;
		tmp = tmp->next;
	}
	ins.line = *s_line();
	ins.type = *s_state();
	tmp = ft_lstnew(&ins, sizeof(t_ins));
	ft_lstadd_back(s_lexem(), tmp);
	ft_lstdel(s_token(), NULL);
}

int					default_state(char c)
{
	if (c == COMMENT_CHAR)
	{
		*s_state() = ASM_ST_INCOM;
	}
	else if (c == CMD_CHAR)
	{
		token_push(c);
		*s_state() = ASM_ST_INCMD;
	}
	else if (ft_strchr(LABEL_CHARS, c))
	{
		token_push(c);
		*s_state() = ASM_ST_INID;
	}
	else if (c == '\n')
		*s_line() += 1;
	return (0);
}

int					inid_state(char c)
{
	if (ft_strchr(LABEL_CHARS, c))
	{
		token_push(c);
	}
	else
	{
		if (c == LABEL_CHAR)
		{
			token_push(c);
		}
		token_save();
		if (c == '\n')
			*s_state() = ASM_ST_DEFAULT;
		else
			*s_state() = ASM_ST_INARGS;
	}
	return (0);
}

int					inargs_state(char c)
{
	if ()
	return (0);
}

int					incmd_state(char c)
{
	if (ft_strchr(LABEL_CHARS, c))
	{
		token_push(c);
	}
	else
	{
		if ()
			token_push(c);
		token_save();
		*s_state() = ASM_ST_DEFAULT;
	}
	if (c == '\n')
		*s_line() += 1;
	return (0);
}

int					incom_state(char c)
{
	if (c == '\n')
	{
		*s_state() = ASM_ST_DEFAULT;
		*s_line() += 1;
	}
	return (0);
}

int					inlit_state(char c)
{
	if (c == LITERAL_CHAR)
	{
		token_push(c);
		token_save();
		*s_state() = ASM_ST_DEFAULT;
		return (0);
	}
	token_push(c);
	if (c == '\n')
		*s_line() += 1;
	return (0);
}

int					indir_state(char c)
{
	if (ft_strchr(ALL_CHARS, c))
	{
		token_push(c);
	}
	else
	{
		if (c == SEPARATOR_CHAR)
			token_push(c);
		token_save();
		*s_state() = ASM_ST_DEFAULT;
	}
	if (c == '\n')
		*s_line() += 1;
	return (0);
}

int					(*g_func[])(char) = {\
	default_state,\
	inid_state,\
	inargs_state,\
	incmd_state,\
	incom_state,\
	inlit_state,\
	indir_state\
};

void				reset_state_machina(void)
{
	*s_state() = ASM_ST_DEFAULT;
	*s_token() = NULL;
	*s_lexem() = NULL;
	*s_line() = 0;
}

int					maj_state_machina(char c)
{
	int				ret;

	ret = g_func[*s_state()](c);
	return (ret);
}
