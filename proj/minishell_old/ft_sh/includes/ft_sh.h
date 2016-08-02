/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 23:55:46 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/19 12:28:03 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"

/*
***	# define SYSCALL_FAILURE_TEST
*/

# define READ_TEST
# define OPENDIR_TEST
# define FORK_TEST
# define EXECVE_TEST

# define IS(X, Y) ((Y & X) == X ? 1 : 0)

# define DEBUG_FILE_NAME "debug.ft_sh"

# define FT_SH_CMD_BUFFER_SIZE 2048
# define FT_SH_BINARY_PATH_SIZE 2048
# define FT_SH_CWD_PATH_SIZE 2048
# define FT_SH_BUILTIN_SIZE 5
# define FT_SH_ERROR_MSG_SIZE 19

# define CSET_O "cdD"
# define SIZE_O 3
# define CSET_CD_O "LP"
# define SIZE_CD_O 2
# define O_PRIVATE_ERROR 0x8000

# define O_COLOR 0x1
# define O_DEBUG 0x2
# define O_FILEDEBUG 0x4

# define O_CD_NOFOLLOW 0x1
# define O_CD_FOLLOW 0x2

# define FMT_COL_ERROR "{green}%s{eoc}: {yellow}%s{eoc}: %s\n"
# define FMT_COL_MSG_ERROR "{green}%s{eoc}: {yellow}%s{eoc}: {red}%s{eoc}: %s\n"
# define FMT_STD_ERROR "%s: %s: %s\n"
# define FMT_STD_MSG_ERROR "%s: %s: %s: %s\n"

# define FMT_COL_S_DEBUG "{green}%s{eoc}: {cyan}%s{eoc}: {yellow}%s{eoc}=%{\n"
# define FMT_COL_E_DEBUG "}={yellow}%s{eoc}\n"
# define FMT_STD_S_DEBUG "%s: %s: %s=%{\n"
# define FMT_STD_E_DEBUG "}=%s\n"
# define FMT_BINARY_DEBUG "\t[%s] -> [%s]\n"
# define FMT_BUILTIN_DEBUG "\t[%s] -> [%p]\n"

# define FMT_CU1 "{green|gr}%s{eoc}: {gr}Invalid option{eoc} -- {red}%c{eoc}\n"
# define FMT_CU2 "{pink}Usage{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}]\n"
# define FMT_U1 "%s: Invalid option -- %c\n"
# define FMT_U2 "Usage: %s [-%s]\n"

# define FMT_CCDU1 "{green|gr}%s{eoc}: {gr}Invalid option{eoc} -- {red}%c{eoc}\n"
# define FMT_CCDU2 "{pink}Usage{eoc}: {gr}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"
# define FMT_CDU1 "%s: Invalid option -- %c\n"
# define FMT_CDU2 "Usage: %s [-%s] [%s]\n"

# define FMT_CUNSETU1 "{green|gr}%s: {gr}No enougth argument{eoc}\n"
# define FMT_CUNSETU2 "{pink}Usage{eoc}: {gr}%s{eoc} [{pink}%s{eoc}]\n"
# define FMT_UNSETU1 "%s: No enougth argument\n"
# define FMT_UNSETU2 "Usage: %s [%s]\n"

# define FMT_STD_PROMPT "ft_sh$>"
# define FMT_COL_PROMPT "{green|gr|}ft_sh$>{eoc}"

# define FMT_CNOFOUND "{green}%s{eoc}: %s: {red}%s{eoc}\n"
# define FMT_NOFOUND "%s: %s: %s\n"

# define FMT_ARGV "\tArg_v[%d] -> [%s]\n"

# define FMT_STD_NOHOME "Fix HOME to get the no arg cd feature"
# define FMT_COL_NOHOME "{red}Fix HOME to get the no arg cd feature{eoc}"

# define MSG_SYSCALL "An error occured"
# define MSG_NOFOUND "Command not found"

# define FDDEBUG shenv()->fd
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
	Open,
	Fork,
	Execve,
	Chdir,
	Getcwd,
	Minim_path_corruption,
	Path_corruption,
	Pwd_corruption,
	Oldpwd_corruption,
	Home_corruption,
	Cdnofound,
	Cdnoright,
	Cdstat,
	Cdnodir,
	Cdtoomany,
	Unknow
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
	int				fd;
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

char				cd_error(\
					t_error_msg_id id, char *msg, int status);
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
int					go_over_opt(\
					int ac, char **av);

/*
***	****************************************************************************
*/

/*
***					***	USAGE.C	***
*/

void				usage\
						(char invalid);
int					cd_usage(\
					char invalid);
int		unset_usage(\
		void);

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

/*
***	****************************************************************************
*/

/*
***					***	CLEAN.C	***
*/

void		supprtwopoint(\
			char *s, int *j);
void		supprpoint(\
			char *s, int *j);
void		cleanslash(\
			char *cp);

/*
***	****************************************************************************
*/

/*
***					***	CD_PATH.C	***
*/

char		*constructpwd(\
			char *nrel, char *old);
void		gothrowrel(\
			char *dest, char *go, char *pwd);
void		gothrowabs(\
			char *dest, char *go);

/*
***	****************************************************************************
*/

/*
***					***	CD_ENV.C	***
*/

int			cdenv(\
			char *nwd_path, char put);
int			fcdenv(\
			char *nwd_path, char put);
/*
***	****************************************************************************
*/

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
void		debug_env(\
			void);
void		debug_binary(\
			void);
void		debug_builtin(\
			void);
void		debug_cmd(\
			t_cmd cmd);
void		start_debug(\
			char *what);
void		end_debug(\
			char *what);
char		*corrupt_path(\
			char *oldpath);
void		corrupt_pwd(\
			void);
void		corrupt_oldpwd(\
			void);
void		corrupt_home(\
			void);
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

