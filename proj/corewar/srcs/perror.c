/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:03:19 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/31 08:39:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		argument_count_error(char *id)
{
	ft_fprintf(2, argument_count_fmt(), id);
}

void		argument_error(char *id, int i, t_token *token)
{
	ft_fprintf(2, argument_fmt(),\
			i, token->key, id, token->position.line, token->position.column);
}

void		open_error(char *file)
{
	ft_fprintf(2, error_fmt(), proginfo()->name, file, strerror(errno));
	errno = 0;
}

void		read_error(char *file)
{
	ft_fprintf(2, error_fmt(), proginfo()->name, file, strerror(errno));
	errno = 0;
}

void		compile_error(char *file)
{
	ft_fprintf(2, error_fmt(), proginfo()->name, file, "Can't compile");
}
