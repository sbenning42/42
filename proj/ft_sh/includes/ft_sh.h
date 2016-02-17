/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:55:46 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 14:47:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <dirent.h>
# include <sys/wait.h>

# include "libft.h"

/*
***	# define SYSCALL_FAILURE_TEST
*/

# define READ_TEST
# define OPENDIR_TEST
# define FORK_TEST
# define EXECVE_TEST

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

# define FT_SH_CMD_BUFFER_SIZE 2048
# define FT_SH_BINARY_PATH_SIZE 2048
# define FT_SH_CWD_PATH_SIZE 2048
# define FT_SH_BUILTIN_SIZE 5
# define FT_SH_ERROR_MSG_SIZE 7

# define CSET_O "cd"
# define SIZE_O 2

# define O_COLOR 0x1
# define O_DEBUG 0x2
# define O_PRIVATE_ERROR 0x8000

# define O_CD_

# define FMT_COL_ERROR "{green}%s{eoc}: {yellow}%s{eoc}: %s\n"
# define FMT_COL_MSG_ERROR "{green}%s{eoc}: {yellow}%s{eoc}: {red}%s{eoc}: %s\n"
# define FMT_STD_ERROR "%s: %s: %s\n"
# define FMT_STD_MSG_ERROR "%s: %s: %s: %s\n"

# define MSG_SYSCALL "Error occured on system call"
# define MSG_NOFOUND "Command not found"

# define FMT_CPROMPT "{green|gr|}ft_sh$>{eoc}"
# define FMT_CU1 "{green|gr}%s{eoc}: {gr}Invalid option{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}Usage{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}]\n"

# define FMT_CBINARY "{yellow}Entry{eoc}: [{gr}%s{eoc}] -> [{ss}%s{eoc}]\n"
# define FMT_CNOFOUND "{green}%s{eoc}: {cyan}%s{eoc}: {red}%s{eoc}\n"
# define FMT_CCMD "{yellow}%s{eoc}:\n%{\n\n\t{cyan}cmd{eoc}: [{gr}%s{eoc}%s{ss}%s{eoc}]\n"
# define FMT_CARGV "\t{cyan}Arg_v{eoc}[{yellow}%d{eoc}] -> [{gr}%s{eoc}]\n"

# define FMT_PROMPT "ft_sh$>"
# define FMT_U1 "%s: Invalid option -- %c\n"
# define FMT_U2 "Usage: %s [-%s]\n"
# define FMT_BINARY "Entry: [%s] -> [%s]\n"
# define FMT_NOFOUND "%s: %s: %s\n"
# define FMT_CMD "%s:\n%{\n\n\tcmd: [%s%s%s]\n"
# define FMT_ARGV "\tArg_v[%d] -> [%s]\n"

# define OPT shenv()->o
# define AV shenv()->av
# define ENV shenv()->env
# define BINARY shenv()->binary
# define BUILTIN shenv()->builtin

/*
***	****************************************************************************
*/

# ifdef SYSCALL_FAILURE_TEST

/*
***	****************************************************************************
*/

#  ifdef READ_TEST

#   define read(X, Y, Z) -1

#  endif

/*
***	****************************************************************************
*/

#  ifdef OPENDIR_TEST

#   define opendir(X) NULL

#  endif

/*
***	****************************************************************************
*/

#  ifdef FORK_TEST

#   define fork() -1

#  endif

/*
***	****************************************************************************
*/

#  ifdef EXECVE_TEST

#   define execve(X, Y, Z) (X == X)

#  endif

/*
***	****************************************************************************
*/

# endif

/*
***	****************************************************************************
*/

extern char			**environ;

typedef int			(*t_built_f)(char **arg_v);

typedef enum		e_error_msg_id
{
	Malloc,
	Read,
	Opendir,
	Fork,
	Execve,
	Chdir,
	Getcwd
}					t_error_msg_id;

typedef struct		s_dic
{
	char			*id;
	void			*content;
	size_t			content_size;
	struct s_dic	*p;
	struct s_dic	*l;
	struct s_dic	*r;
}					t_dic;

typedef struct		s_built
{
	char			*id;
	t_built_f		built;
}					t_built;

typedef struct		s_cmd
{
	int				not_found;
	int				builtin;
	t_built_f		built;
	char			pathbin[FT_SH_BINARY_PATH_SIZE + 1];
	char			**arg_v;
}					t_cmd;

typedef struct		s_shenv
{
	char			**env;
	char			*av;
	int				o;
	t_dic			*binary;
	t_built			builtin[FT_SH_BUILTIN_SIZE];
}					t_shenv;

/*
***	****************************************************************************
*/

/*
***					***	SHENV.C	***
*/

t_shenv				*shenv\
						(void);
void				shenv_create\
						(int arg_c, char **arg_v);
void				shenv_destroy\
						(void);

/*
***	****************************************************************************
*/

/*
***					***	DIC.C	***
*/

int					alpha_sort\
						(char *id1, char *id2);
t_dic				*ft_dicnew\
						(char *id, void *content, size_t content_size);
void				ft_dicadd\
						(t_dic **adic, t_dic *e\
						 , int (*s)(char *, char *));
void				ft_dicdoinf\
						(t_dic *dic, void (*f)(t_dic *));
void				ft_dicdopref\
						(t_dic *dic, void (*f)(t_dic *));
void				ft_dicdosuf\
						(t_dic *dic, void (*f)(t_dic *));
void				*ft_dicentry\
						(t_dic *dic, char *id);
void				ft_dicdel\
						(t_dic **adic, void (*del)(void *, size_t));
/*
***	****************************************************************************
*/

/*
***					***	BINARY.C	***
*/

void				dic_binary\
						(void);

/*
***	****************************************************************************
*/

/*
***					***	GET.C	***
*/

char				*get_shenv\
						(char *id);
/*
***	****************************************************************************
*/

/*
***					***	ERROR.C	***
*/

void				error\
						(t_error_msg_id id, char *msg, int status);
void				exit_error\
						(void);
void				binary_error\
						(void);
void				malloc_error\
						(void);
void				opendir_error\
						(char *path);
void				exec_error\
						(char *path);
void				fork_error\
						(void);

/*
***	****************************************************************************
*/

/*
***					***	PUT.C	***
*/

void				put_shenv\
						(void);
void				put_env\
						(void);
void				put_av\
						(void);
void				put_opt\
						(void);
void				put_cmd_buffer\
						(char *cmd, int ret);
void				put_cmd\
						(t_cmd cmd);

/*
***	****************************************************************************
*/

/*
***					***	GETOPT.C	***
*/

int					get_opt\
						(const char *cset, int ac, char **av, char *err);

/*
***	****************************************************************************
*/

/*
***					***	USAGE.C	***
*/

void				usage\
						(char invalid);

/*
***	****************************************************************************
*/

/*
***					***	FT_SH.C	***
*/

int					minishell\
						(void);

/*
***	****************************************************************************
*/

/*
***					***	HANDLE.C	***
*/

int					handle_cmd\
						(char *cmd_buffer);

/*
***	****************************************************************************
*/

/*
***					***	PARSE.C	***
*/

t_cmd				parse_cmd\
						(char *cmd_buffer);
/*
***	****************************************************************************
*/

/*
***					***	EXEC.C	***
*/

void				exec_binary\
						(t_cmd cmd);

void				dic_builtin(\
					void);
int					builtin_cd(\
					char **arg_v);
int					builtin_env(\
					char **arg_v);
int					builtin_setenv(\
					char **arg_v);
int					builtin_unsetenv(\
					char **arg_v);
int					builtin_exit(\
					char **arg_v);
void				getcwd_error(\
					void);
void				chdir_error(\
					char *path);
char				*intern_getenv(\
					char *key);
int					intern_setenv(\
					char *key, char *value);
/*
***	****************************************************************************
*/

#endif

/*
***	****************************************************************************
*/

/*
***					***	.C	***
*/

