/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:47:07 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 14:16:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*g_char_type[] = {\
	"DEFAULT",\
	"INSTRUCTION",\
	"LABEL",\
	"COMMAND",\
	"COMMENT",\
	"LITERAL",\
	"ARGS",\
	"REGISTRE",\
	"DIRECT",\
	"INDIRECT",\
	"DIRECT_LABEL",\
	"FLUSH",\
	"SEPARATOR"\
};

void		puttype(int type)
{
	char	*ctype = g_char_type[type];

	if (PI_ISOPT(proginfo()->opt, O_COLOR))
	{
		if (type == ST_WORD)
			ft_printf("{gr|cyan}");
		else if (type == ST_LABEL)
			ft_printf("{gr|green}");
		else if (type == ST_REG_ARG || type == ST_IND_ARG || type == ST_DIR_ARG || type == ST_LABEL_ARG)
			ft_printf("{green}");
		else if (type == ST_SEPARATOR)
			ft_printf("{pink}");
		else if (type == ST_CMD)
			ft_printf("{gr|yellow}");
		else if (type == ST_LITERAL)
			ft_printf("{gr|blue}");
	}
	ft_printf("%s", ctype);
}

void	dump_lexem(t_list *tmp)
{
	t_token	*data;
	int		li = -1;
	while (tmp)
	{
		data = (t_token *)tmp->content;
		ft_printf("(%2d, %2d)%s%{", data->line, data->column, ((data->type != ST_WORD && data->type != ST_LABEL && data->type != ST_CMD) ? "\t\t" : "\t"));
		puttype(data->type);
		if (PI_ISOPT(proginfo()->opt, O_COLOR))
			ft_printf("{eoc}");
		ft_printf("}%s[%s]\n", ((data->type == ST_WORD || data->type == ST_CMD) ? "\t\t" : (data->type == ST_LABEL ? "\t\t\t" : "\t")), data->value);
		li = data->line;
		tmp = tmp->next;
	}
}
