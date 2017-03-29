/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:52:12 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/29 11:57:46 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_command(char *command_ref, t_token *lst)
{
	if (!(lst\
				&& lst->next\
				&& lst->id == N_ID_COMMAND\
				&& lst->next->id == N_LITERAL))
		return (-1);
	if (ft_strcmp(command_ref, lst->value))
		return (-1);
	return (0);
}

int			asm_header(header_t *h, t_token **lst)
{
	size_t	len;

	if (check_command(NAME_CMD_STRING, *lst))
		return (-1);
	pop_token(lst);
	len = ft_strlen((*lst)->value);
	ft_strncpy(h->prog_name, (*lst)->value + 1, PROG_NAME_LENGTH);
	h->prog_name[len - 2] = 0;
	pop_token(lst);
	if (check_command(COMMENT_CMD_STRING, *lst))
		return (-1);
	pop_token(lst);
	len = ft_strlen((*lst)->value);
	ft_strncpy(h->comment, (*lst)->value + 1, COMMENT_LENGTH);
	h->comment[len - 2] = 0;
	pop_token(lst);
	h->magic = 0;
	h->prog_size = 0;
	return (0);
	(void)h;
	(void)lst;
}
