/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:17:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/28 21:53:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

#include "libft.h"
#include "ft_readline.h"
#include "ft_lexer.h"
#include "ft_parser.h"

# define SH_OPTION "hvtp"

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
	int			log;
}				t_sh;

int		ft_getopt(int ac, char **av, char *charset);

#endif
