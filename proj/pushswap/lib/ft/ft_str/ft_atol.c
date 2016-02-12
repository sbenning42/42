/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 12:35:39 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/12 12:37:56 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_atol(const char *str)
{
	size_t			i;
	long			res;
	unsigned int	neg;

	neg = 0;
	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || \
			str[i] == '\f' || str[i] == '\n' || str[i] == '\v')
		++i;
	if (str[i] == '-')
	{
		++i;
		++neg;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	if (neg)
		return (-res);
	return (res);
}
