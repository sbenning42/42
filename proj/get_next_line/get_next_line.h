/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 02:19:39 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/20 03:27:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define NOFILE 255
# define BUFFER_SIZE 512

# define NLCHAR '\n'

int		get_next_line(int ac, char **line);

#endif
