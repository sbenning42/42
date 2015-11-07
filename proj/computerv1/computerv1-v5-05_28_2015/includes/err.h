/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:31:53 by sbenning          #+#    #+#             */
/*   Updated: 2015/05/28 23:44:17 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

# include "libft.h"

# define CONTINUE 42
# define END 0
# define NO_ERR 1
# define ERR_ML -1
# define ERR_LEX -2
# define ERR_PAR -3
# define ERR_ARG -4
# define MYNAME "ComputerV1: "
# define ERR_MSG "An error occured."
# define ARG_MSG "No enough argument!"
# define NO_MSG ""
# define ML_MSG "Malloc error occured."
# define LEX_MSG "Syntax error occured."
# define PAR_MSG "Parse error occured"
# define ERR 0

int			err_handle(int err_id);

#endif
