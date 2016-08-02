/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:49:49 by sbenning          #+#    #+#             */
/*   Updated: 2016/05/30 17:20:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# define O_P 0x1
# define O_L 0x2

# define O_IS(X, Y) ((X & Y) == Y)

# include "libft.h"

int			get_opt(const char *cset, int ac, char **av, char *err);

#endif
