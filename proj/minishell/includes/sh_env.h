/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 09:06:05 by sbenning          #+#    #+#             */
/*   Updated: 2016/10/05 11:49:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# define ENV_O_EMPTY 0x1
# define IS_O(X, Y) (X & Y)

# include "libft.h"
# include "libdic.h"

void		env_merge(char **env, int i, char **entries);
int			fill_env(char **cp_env, char **env, char **entries, int o);
char		**get_cmd_env(int ac, char **av, char **env, int o);
int			env_begin_cmd(int ac, char **av);
void		env_exec_cmd(char *name, t_dic_entry *bin, char **av, char **env);
int			env_error(char *msg);
int			ft_env(int ac, char **av, t_dic_entry *dic);

char		**env_getentries(int ac, char **av, int *size);
void		env_destroy(char ***env);

int			ft_getopt(int ac, char **av, char *charset);

#endif
