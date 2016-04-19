/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:24:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 17:00:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAP_H
# define FT_CAP_H

# define CAP_SPECIFYTERM "Specify a terminal type with `setenv TERM <yourtype>'."
# define CAP_UNDEFTERM "Terminal type '%s' is not defined."
# define CAP_NOACCESSTERM "Could not access the termcap data base."
#define CAP_ERROR "Error occured on termcap library handle"

# define CAP_NOARG 0, 0, 0
# define CAP_CM(X, Y) "cm", 0, X, Y
# define CAP_PARAM(X) 1, X, 0
# define CAP_XPARAM(X, Y) 1, X, Y

# include <term.h>
# include "libft.h"

void		ft_initcap(void);
void		ft_cap(char *cap, int flag, int x, int y);

#endif
