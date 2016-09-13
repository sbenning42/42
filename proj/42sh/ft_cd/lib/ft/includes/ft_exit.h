/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:25:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/19 17:59:35 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

# include "ft_header.h"
# include "ft_global.h"
# include "ft_printf.h"

void		ft_error(char *msg);
void		ft_exit(int rval, char *msg);

#endif
