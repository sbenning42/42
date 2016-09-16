/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 09:06:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/16 09:49:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# define ENV_O_EMPTY 0x1
# define IS_O(X, Y) (X & Y)

# include "libft.h"

int			env_error(char *msg);
int			ft_env(int ac, char **av);

char		**env_getentries(int ac, char **av, int *size);
void		env_destroy(char ***env);

int			ft_getopt(int ac, char **av, char *charset);

#endif
