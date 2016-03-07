/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:08:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/07 12:12:21 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lxem			*ft_lexer(char *line)
{
	t_lxem		*final_lst;
	t_lxem		*lst;

	if (!(lst = lx_wordsplit_dev(line)))
		return (NULL);
	final_lst = lst;
	return (final_lst);
}
