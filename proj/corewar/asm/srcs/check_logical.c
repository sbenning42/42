/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_logical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:30:32 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/23 14:47:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			(*g_check[])(t_list *) = {\
	default_check,\
	word_check,\
	label_check,\
	command_check,\
	comment_check,\
	literal_check,\
	args_check,\
	reg_arg_check,\
	dir_arg_check,\
	ind_arg_check,\
	lab_arg_check,\
	flush_check\
};

int			default_check(t_list *lst)
{
	ft_fprintf(2, "You have NOTHING to do here!!!!...\n");
	return (-1);
	(void)lst;
}

int			comment_check(t_list *lst)
{
	ft_fprintf(2, "You have NOTHING to do here!!!!...\n");
	return (-1);
	(void)lst;
}

int			args_check(t_list *lst)
{
	ft_fprintf(2, "You have NOTHING to do here!!!!...\n");
	return (-1);
	(void)lst;
}

int			flush_check(t_list *lst)
{
	ft_fprintf(2, "You have NOTHING to do here!!!!...\n");
	return (-1);
	(void)lst;
}

int			literal_check(t_list *lst)
{
	return (0);
	(void)lst;
}

int			label_check(t_list *lst)
{
	return (0);
	(void)lst;
}

int			command_check(t_list *lst)
{
	t_token	*token;

	if (!lst->next)
		return (-1);
	token = (t_token *)lst->next->content;
	if (token->type != ST_LITERAL)
		return (-1);
	return (0);
}



int			check_logical_integrity(t_lexem *lexem)
{
	t_list	*tmp;
	t_token	*token;

	tmp = lexem->lst;
	while (tmp)
	{
		token = (t_token *)tmp->content;
		if (g_check[token->type](tmp))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
