/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:41:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/05 17:30:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H

# include "libft.h"
# include <term.h>

typedef struct		s_term
{
	struct termios	global;
	struct termios	local;
}					t_term;

void				ft_atexit(int evalue, char *id, char *msg);

void				tm_cap(char *id);

int					tm_init(char *term);
int					tm_quit(void);

#endif
