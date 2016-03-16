/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 17:40:54 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/15 12:52:16 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYN_H
# define FT_DYN_H

# include "ft_str.h"

typedef struct		s_dynstr
{
	char			*str;
	size_t			real;
	size_t			used;
	size_t			expand_offset;
}					t_dynstr;

/*
***					***	FT_DYN.C	***
***
***	int				static_dyn_expand(t_dynstr *dynstr, size_t optoffset);
***
*/

int					dyn_strnew(t_dynstr *dynstr, size_t offset);
int					dyn_strdel(t_dynstr *dynstr);
int					dyn_strpushstr(t_dynstr *dynstr, char *str, size_t len);
int					dyn_strpopstr(t_dynstr *dynstr, size_t len);
void				dyn_strclr(t_dynstr *dynstr);

/*
***					***	FT_DYNSTD.C	***
*/

char				*dyn_strcpy(t_dynstr *dynstr, char *dest);
char				*dyn_strdup(t_dynstr *dynstr);
char				*dyn_strncpy(t_dynstr *dynstr, size_t len, char *dest);
char				*dyn_strndup(t_dynstr *dynstr, size_t len);
char				*dyn_strsub(t_dynstr *dynstr, size_t from, size_t len);

#endif
