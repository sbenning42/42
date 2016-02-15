/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:42:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/15 17:45:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_shenv				*shenv(\
					void)
{
	static t_shenv	s;

	return (&s);
}

static int			environsize(\
					char **ep)
{
	int				i;

	i = 0;
	while (ep[i++])
		;
	return (i);
}

void				shenv_create(\
					int arg_c, char **arg_v)
{
	int				i;
	int				len;
	char			e;
	char			*f;
	char			**ep;

	f = ft_strrchr(arg_v[0], '/');
	AV = (f ? f + 1 : arg_v[0]);
	e = 0;
	if (IS(O_PRIVATE_ERROR, (OPT = get_opt(CSET_O, arg_c, arg_v, &e))))
		usage(e);
	ENV = environ;
	ep = environ;
	len = environsize(ep);
	if (!(ENV = ft_memalloc(sizeof(char *) * (len + 1))))
		error(); //Have to put an error msg!!!
	ENV[len] = NULL;
	i = 0;
	while (*ep)
	{
		if (!(ENV[i++] = ft_strdup(*ep)))
			error(); //IDEM
		ep++;
	}
	dic_binary();
	dic_builtin();
}

void				shenv_destroy(\
					void)
{
	int				i;

	i = 0;
	if (BINARY)
		ft_dicdel(&BINARY, NULL);
	if (ENV)
	{
		while (ENV[i])
			ft_memdel((void **)(ENV + i));
		ft_memdel((void **)&ENV);
	}
	AV = NULL;
}
