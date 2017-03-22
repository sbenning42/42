/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machina_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:49:17 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/22 19:58:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					(*g_func[])(char) = {\
	default_state,\
	inid_state,\
	inargs_state,\
	incmd_state,\
	incom_state,\
	inlit_state,\
	indir_state\
};

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

int					default_state(char c)
{
	if (c == '\n')
		*s_line() += 1;
	else if (c == COMMENT_CHAR)
		*s_state() = ASM_ST_COM;
	else if (c == CMD_CHAR)
	{
		token_push(c);
		*s_state() = ASM_ST_CMD;
	}
	else if (ft_strchr(LABEL_CHARS, c))
	{
		token_push(c);
		*s_state() = ASM_ST_ID;
	}
	return (0);
}



void		reset_state_machina(void)
{
	*s_state() = ASM_ST_DEFAULT;
}

int			maj_state_machina(char c, int l, int c)
{
	return (g_func[*s_state()](c));
}
