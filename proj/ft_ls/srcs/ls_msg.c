/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:18:17 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 09:59:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ls_err(char *av, char *id, int err, char *msg)
{
	ft_printf("%s: %s: %s\n", av, id, (err ? strerror(err) : msg));
	return (0);
}

int	ft_put_usage(char *av, char e)
{
	ft_fprintf(2, FMT_U1, ft_name(av), "illegal option", e);
	ft_fprintf(2, FMT_U2, "usage", ft_name(av), CSET_O, "file ...");
	return (0);
}
