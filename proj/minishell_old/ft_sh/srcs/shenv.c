/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:42:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 18:59:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
***	At this step, we have to make a first check of the ENV sensible key
***	HOME/PATH/PWD/OLDPWD
***	but don't go as if they are here forever, user still can destroy it
***	in this case, we could reset these values as they uses to be in the begining
*/

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
	ep = environ;
	len = environsize(ep);
	if (!(ENV = ft_memalloc(sizeof(char *) * (len + 1))))
		error(Malloc, NULL, EXIT_FAILURE);
	ENV[len] = NULL;
	i = 0;
	while (*ep)
	{
		if (!(ENV[i++] = ft_strdup(*ep)))
			error(Malloc, NULL, EXIT_FAILURE);
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
	if (ENV)
	{
		while (ENV[i])
			ft_memdel((void **)(ENV + i));
		ft_memdel((void **)&ENV);
	}
	if (BINARY)
		ft_dicdel(&BINARY, NULL);
	AV = NULL;
}
