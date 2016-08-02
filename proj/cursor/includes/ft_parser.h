/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 08:16:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 08:25:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "libdic.h"
# include "ft_lexer.h"
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>

# define EX_WAIT 0x1
# define EX_NOPIPE 0x2
# define EX_INPIPE 0x4
# define EX_OUTPIPE 0x8
# define EX_OUTREDIR 0x10

typedef struct		s_cmd
{
	char			bin[2048];
	char			**arg;
	char			**env;
	int				fd[3][2];
	int				bitset;
}					t_cmd;

typedef struct		s_tree
{
	int				id;

	struct s_tree	*p;
	struct s_tree	*l;
	struct s_tree	*r;
	t_lxem			*content;
	t_cmd			cmd;
}					t_tree;

typedef int			(*t_exec)(t_tree *root, t_dic_entry *bin);

int					ft_parser(t_tree **root, t_lxem *list);
void				parse_del(t_tree **root);

void				cmd_destroy(char ***at);
char				**cmd_arg(t_lxem *list);
char				**cmd_env(void);

void				exec_destroy(char ***at);
char				**exec_arg(t_lxem *list);
char				**exec_env(void);

int					exec_root(t_tree *root, t_dic_entry *bin);

int					exec_word(t_tree *root, t_dic_entry *bin);
int					exec_strict_sep(t_tree *root, t_dic_entry *bin);
int					exec_and_sep(t_tree *root, t_dic_entry *bin);
int					exec_or_sep(t_tree *root, t_dic_entry *bin);
int					exec_pipe(t_tree *root, t_dic_entry *bin);
int					exec_bg(t_tree *root, t_dic_entry *bin);
int					exec_stdin_redir(t_tree *root, t_dic_entry *bin);
int					exec_stdout_redir(t_tree *root, t_dic_entry *bin);
int					exec_stdin_append_redir(t_tree *root, t_dic_entry *bin);
int					exec_stdout_append_redir(t_tree *root, t_dic_entry *bin);
int					exec_stderr_redir(t_tree *root, t_dic_entry *bin);
int					exec_stderr_append_redir(t_tree *root, t_dic_entry *bin);

#endif
