/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:17:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/16 09:08:59 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H


/*
 * NOTA : "ls | wc > out" --> should have '>' as root instead of '|' to avoid
 * 			access to the "grand-children" of the node when applying redirector
 * 			and pipe to cmd's fd 
*/


# include "libft.h"
# include "ft_readline.h"
# include "ft_lexer.h"
# include "ft_parser.h"
# include "ft_cd.h"
# include "sh_env.h"
# include <time.h>

# define SH_DEFAULT_PROMPT ""
# define SH_O1 RL_ECHO
# define SH_O2 RL_HISTORY
# define SH_O3 RL_42_STYLE
# define SH_O4 RL_42_NOPWD
# define SH_O5 RL_42_NODATE
# define SH_DEFAULT_SETTINGS (SH_O1 | SH_O2 | SH_O3 | SH_O4 | SH_O5)
# define SH_OPTION "hvtp"

# define SH_PROMPT_O_COLOR 0x1
# define SH_PROMPT_O_PATH 0x2
# define SH_PROMPT_O_DATE 0x4
# define SH_PROMPT_O_SH 0x8

# define SH_O_HELP 0x1
# define SH_O_VERBOSE 0x2
# define SH_O_DTREE 0x4
# define SH_O_PROMPT 0x8

# define ISO(X, Y) ((X & Y) == Y)

# define SH_DUMP_LGFORMAT "{cyan|gr}%*s-{red|gr}%s{eoc}{cyan|gr}-[{eoc}\n"

typedef struct	s_sh
{
	int			ac;
	char		**av;
	int			o;
	t_hist		hist;
	t_dic_entry	*bin;
	char		*prompt;
	int			settings;
	char		*line;
}				t_sh;

void			sh_init(t_sh *sh, int ac, char **av);
void			sh_clear(t_sh *sh);

int				sh_readline(t_sh *sh);
int				sh_break(char **line);
int				sh_lexer(t_sh *sh, t_lxem **list);
int				sh_parser(t_sh *sh, t_tree **root, t_lxem **list);

void			dump_root(t_tree *root, int i, t_dic_entry *bin);
void			dump_root_log(t_tree *root, int i, t_dic_entry *bin, int fd);

int				ft_getopt(int ac, char **av, char *charset);

typedef int		(*t_exec)(t_sh *sh, t_tree *root);

void			exec_destroy(char ***at);
char			**exec_arg(t_lxem *list);
char			**exec_env(void);

int				exec_root(t_sh *sh, t_tree *root);

int				exec_word(t_sh *sh, t_tree *root);
int				exec_builtin(t_sh *sh, t_tree *root);
int				exec_strict_sep(t_sh *sh, t_tree *root);
int				exec_and_sep(t_sh *sh, t_tree *root);
int				exec_or_sep(t_sh *sh, t_tree *root);
int				exec_pipe(t_sh *sh, t_tree *root);
int				exec_bg(t_sh *sh, t_tree *root);
int				exec_stdin_redir(t_sh *sh, t_tree *root);
int				exec_stdout_redir(t_sh *sh, t_tree *root);
int				exec_stdin_append_redir(t_sh *sh, t_tree *root);
int				exec_stdout_append_redir(t_sh *sh, t_tree *root);
int				exec_stderr_redir(t_sh *sh, t_tree *root);
int				exec_stderr_append_redir(t_sh *sh, t_tree *root);

int				built_exit(t_sh *sh, t_tree *root);
int				built_prompt(t_sh *sh, t_tree *root);
int				built_cd(t_sh *sh, t_tree *root);
int				built_echo(t_sh *sh, t_tree *root);
int				built_env(t_sh *sh, t_tree *root);
int				built_setenv(t_sh *sh, t_tree *root);
int				built_unsetenv(t_sh *sh, t_tree *root);

#endif
