/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/22 16:21:28 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/23 12:44:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include "libft.h"

# define OPT_CSET "alrRt"
# define OPT_SIZE 5

# define EACCES_M "Permission is denied for one of the directories in the path prefix of pathname."
# define EBADF_M  "fd is bad."
# define EFAULT_M "Bad address."
# define ELOOP_M  "Too many symbolic links encountered while traversing the path."
# define ENAMETOOLONG_M "pathname is too long."
# define ENOENT_M "A component of pathname does not exist, or pathname is an empty string."
# define ENOMEM_M "Out of memory (i.e., kernel memory)."
# define ENOTDIR_M "A component of the path prefix of pathname is not a directory."
# define EOVERFLOW_M "pathname or fd refers to a file whose size, inode number, or number of blocks cannot be  represented  in,  respectively,  \
						the  types off_t,  ino_t,  or  blkcnt_t.   This  error  can  occur  when,  for  example,  an  application compiled on a \
						32-bit platform without-D_FILE_OFFSET_BITS=64 calls stat() on a file whose size exceeds (1<<31)-1 bytes. -D_FILE_OFFSET_BITS=64 \
						calls stat() on a file whose size exceeds (1<<31)-1 bytes."

# define A_FLAG 0
# define L_FLAG 1
# define R_FLAG 2
# define RR_FLAG 3
# define T_FLAG 4

void	ft_ls_del_avl(void *content, size_t size);
void	ft_ls_straigt_sort(t_list *lst);
void	ft_ls_time_sort(t_list *lst, int *opt);
void	ft_ls_reverse_sort(t_list *lst);
t_list	*ft_ls_sort_av(int *opt, int ac, char **av);
void	ft_ls_put_error_entry(char *name, int err);
int		get_opt(const char *cset, int *opt, int ac, char **av);

#endif
