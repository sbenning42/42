/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:01:19 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/13 20:08:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_verbose(char *av, char *id, char *msg)
{
	ft_fprintf(2, VERBFMT, av, id, msg);
	return (0);
}

int	ft_err(char *av, char *id, char *msg)
{
	ft_fprintf(2, ERRFMT, av, id, (errno ? strerror(errno) : msg));
	errno = 0;
	return (0);
}

int				fdf_synerror(t_env *env, t_lex_tk *t, int y)
{
	char		buf[FDF_SNPRINTF_BS];

	ft_bzero((void *)buf, FDF_SNPRINTF_BS);
	ft_snprintf(buf, FDF_SNPRINTF_BS, SYNERRFMT, y, MSG_SYN, t->size, t->value);
	ft_fprintf(2, ERRFMT, env->av, env->id, buf);
	return (0);
}
