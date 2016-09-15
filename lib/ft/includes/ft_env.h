/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 13:04:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/15 17:14:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include "ft_global.h"
# include "ft_str.h"

char		*ft_getenv(char *key);
int			ft_setenv(char *key, char *value);
int			ft_unsetenv(char *key);

#endif
