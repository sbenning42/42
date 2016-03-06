/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:48:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/03/06 22:30:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "libft.h"

# define LX_WORDSPLIT_NOPROTEC_CSET "|&;()<>!$`"
# define LX_PROTEC_CSET "\\'\""

# define LX_PLVNOPROTEC 0x0
# define LX_PLVESCAPE 0x1
# define LX_PLVQUOTE 0x2
# define LX_PLVDQUOTE 0x4

typedef enum		s_lxproteclv
{
	PLV_Noprotec,
	PLV_Escape,
	PLV_Quote,
	PLV_Dquote
}					t_lxproteclv;

typedef struct		s_lxem
{
	struct s_lexem	*previous;
	struct s_lexem	*next;
	t_lxtype		type;
	t_dynstr		value;
	size_t			len;
}					t_lxem;

void				lx_del(t_lxem **alst);
void				lx_addtoken(t_lxem **alst);

t_lxem				*lx_dev_wordsplit(char *s, char *cset);
t_lxem				*ft_lexer(char *line);

#endif
