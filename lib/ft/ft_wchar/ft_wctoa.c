/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:46:30 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/22 19:37:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

static void				mask1(unsigned int wi, char **s)
{
	unsigned int		mask;
	char				*cp;

	mask = MASK1;
	cp = *s;
	*cp = (char)((mask >> 8) | (((wi >> 6) << 27) >> 27));
	*(cp + 1) = (char)(((mask << 24) >> 24) | ((wi << 26) >> 26));
	*s += 2;
}

static void				mask2(unsigned int wi, char **s)
{
	unsigned int		mask;
	char				*cp;

	mask = MASK2;
	cp = *s;
	*cp = (char)((mask >> 16) | (((wi >> 12) << 28) >> 28));
	*(cp + 1) = (char)(((mask << 16) >> 24) | (((wi >> 6) << 26) >> 26));
	*(cp + 2) = (char)(((mask << 24) >> 24) | ((wi << 26) >> 26));
	*s += 3;
}

static void				mask3(unsigned int wi, char **s)
{
	unsigned int		mask;
	char				*cp;

	mask = MASK3;
	cp = *s;
	*cp = (char)((mask >> 24) | (((wi >> 18) << 29) >> 29));
	*(cp + 1) = (char)(((mask << 8) >> 24) | (((wi >> 12) << 26) >> 26));
	*(cp + 2) = (char)(((mask << 16) >> 24) | (((wi >> 6) << 26) >> 26));
	*(cp + 3) = (char)(((mask << 24) >> 24) | ((wi << 26) >> 26));
	*s += 4;
}

void					ft_wctoa(wchar_t *ws, char *s)
{
	while (*ws != L'\0')
	{
		if (*ws <= 0x7F)
			*s++ = (char)*ws;
		else if (*ws <= 0x7FF)
			mask1((unsigned int)*ws, &s);
		else if (*ws <= 0xFFFF)
			mask2((unsigned int)*ws, &s);
		else if (*ws <= 0x1FFFFF)
			mask3((unsigned int)*ws, &s);
		ws++;
	}
	*s = 0;
}
