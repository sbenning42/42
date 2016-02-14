/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:55:46 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/14 18:45:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <dirent.h> //opendir, readdir, closedir
# include <sys/wait.h> //wait, wait3, wait4, waitpid
# include <signal.h> // signal, kill

# include "libft.h"

# define FT_SH_CMD_BUFFER_SIZE 2048

# define CSET_O "dc"
# define SIZE_O 2

# define O_DEBUG 0x1
# define O_COLOR 0x2
# define O_PRIVATE_ERROR 0x4

# define MSG_SYSCALL "An error occured on system call..."

# define FMT_CU1 "{green|gr}%s{eoc}: {gr}Invalid option{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}Usage{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}]\n"
# define FMT_CREAD "{red}%s{eoc}: {yellow}read{eoc}: %s\n"
# define FMT_CREAD "{red}%s{eoc}: {yellow}malloc{eoc}: %s\n"

# define FMT_U1 "%s: Invalid option -- %c\n"
# define FMT_U2 "Usage: %s [-%s]\n"
# define FMT_READ "%s: read: %s\n"
# define FMT_READ "%s: malloc: %s\n"

# define OPT shenv()->o
# define AV shenv()->av
# define ENV shenv()->env
# define IS(X, Y) ((Y & X) == X ? 1 : 0)

/*
***	****************************************************************************
*/

extern char		**environ;

typedef enum	e_bool
{
	False,
	True
}				t_bool;

typedef struct	s_shenv
{
	char		**env;
	char		*av;
	int			o;
	t_dic		*binary;
	t_dic		*builtin;
}				t_shenv;

/*
***	****************************************************************************
*/

/*
***				***	SHENV.C	***
*/

t_shenv			*shenv\
					(void);
void			shenv_create\
					(int arg_c, char **arg_v);
void			shenv_destroy\
					(void);

/*
***	****************************************************************************
*/

/*
***				***	DIC.C	***
*/

t_dic			*ft_dicnew\
					(char *id, void *content, size_t content_size);
void			ft_dicadd\
					(t_dic **adic, t_dic *e, int (*s)(void *, void *, size_t));
void			ft_dicdel\
					(t_dic **adic, void (*del)(void *, size_t));
/*
***	****************************************************************************
*/

/*
***				***	BINARY.C	***
*/

void			dic_binary\
					(void);

/*
***	****************************************************************************
*/

/*
***				***	ERROR.C	***
*/

void			error\
					(void);
void			read_error\
					(void);
void			binary_error\
					(void);

/*
***	****************************************************************************
*/

/*
***				***	PUT.C	***
*/

void			put_env\
					(void);
void			put_av\
					(void);
void			put_opt\
					(void);
void			put_cmd_buffer\
					(char *cmd, int ret);

/*
***	****************************************************************************
*/

/*
***				***	GETOPT.C	***
*/

int				get_opt\
					(const char *cset, int ac, char **av, char *err);

/*
***	****************************************************************************
*/

/*
***				***	USAGE.C	***
*/

void			usage\
					(char invalid);

/*
***	****************************************************************************
*/

/*
***				***	FT_SH.C	***
*/

int				minishell\
					(void);

/*
***	****************************************************************************
*/

/*
***				***	HANDLE.C	***
*/

int				handle_cmd\
					(char *cmd, int size);

/*
***	****************************************************************************
*/

#endif

/*
***	****************************************************************************
*/

/*
***				***	.C	***
*/

