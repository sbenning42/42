/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:17:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/29 20:29:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft.h"
# include "ft_readline.h"
# include "ft_lexer.h"
# include "ft_parser.h"
# include <time.h>

# define SH_DEFAULT_PROMPT ""
# define SH_DEFAULT_SETTINGS (RL_ECHO | RL_HISTORY | RL_42_STYLE | RL_42_NOPWD | RL_42_NODATE)
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

int				ft_getopt(int ac, char **av, char *charset);

typedef int			(*t_exec)(t_sh *sh, t_tree *root);

void				exec_destroy(char ***at);
char				**exec_arg(t_lxem *list);
char				**exec_env(void);

int					exec_root(t_sh *sh, t_tree *root);

int					exec_word(t_sh *sh, t_tree *root);
int					exec_strict_sep(t_sh *sh, t_tree *root);
int					exec_and_sep(t_sh *sh, t_tree *root);
int					exec_or_sep(t_sh *sh, t_tree *root);
int					exec_pipe(t_sh *sh, t_tree *root);
int					exec_bg(t_sh *sh, t_tree *root);
int					exec_stdin_redir(t_sh *sh, t_tree *root);
int					exec_stdout_redir(t_sh *sh, t_tree *root);
int					exec_stdin_append_redir(t_sh *sh, t_tree *root);
int					exec_stdout_append_redir(t_sh *sh, t_tree *root);
int					exec_stderr_redir(t_sh *sh, t_tree *root);
int					exec_stderr_append_redir(t_sh *sh, t_tree *root);

int					built_exit(t_sh *sh, t_tree *root);
int					built_prompt(t_sh *sh, t_tree *root);

#endif
