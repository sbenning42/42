/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:35:56 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 10:48:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include "ft_header.h"

# define MASK1 49280
# define MASK2 14712960
# define MASK3 4034953344

size_t		ft_wclen(wchar_t *s);
void		ft_wctoa(wchar_t *ws, char *s);

#endif
