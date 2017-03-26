/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 13:34:24 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 17:50:11 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# define FALSE			0
# define TRUE			1

# include				"libft.h"

typedef struct s_parser	t_parser;
typedef int				(*t_match)(t_parser *, char **, void *);
typedef int				(*t_callback)(t_parser *, char **, char *, void *);

struct					s_parser
{
	int					id;
	char				*key;
	t_parser			*left;
	t_match				match;
	t_parser			*right;
	t_callback			match_callback;
	t_callback			unmatch_callback;
	int					skip_white;
};

int						ft_parse(t_parser *self, char **scan, void *data);

int						match_and(t_parser *self, char **scan, void *data);
int						match_or(t_parser *self, char **scan, void *data);
int						match_xor(t_parser *self, char **scan, void *data);
int						match_c(t_parser *self, char **scan, void *data, char c);

#endif
