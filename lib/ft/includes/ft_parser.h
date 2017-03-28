/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 08:22:30 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/28 16:36:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# define FT_PARSE_MAX_CHILD	5

# define FALSE 0
# define TRUE 1

# include "ft_header.h"

typedef struct s_position	t_position;
typedef struct s_token		t_token;
typedef struct s_parser		t_parser;
typedef int					(*t_cback)(t_parser *, t_token **lst);
typedef t_token				*(*t_match)(t_parser *, char **, void *);

struct					s_position
{
	int					line;
	int					column;
};

struct					s_token
{
	int					id;
	char				*value;
	size_t				size;
	t_position			position;
	t_token				*next;
};

struct					s_parser
{
	int					id;
	char				*key;
	int					whitespace;
	t_cback				callback;
	t_match				match;
	int					child[FT_PARSE_MAX_CHILD];
	size_t				size;
};

t_position				*single_position(void);
void					init_posotion(void);
void					reset_posotion(void);
void					inc_li_position(int offset);
void					inc_co_position(int offset);

t_token					*new_token(int id, char *value, size_t size, t_position pos);
void					add_token(t_token **lst, t_token *token);
void					del_token(t_token **lst);

t_token					*match_and(t_parser *self, char **scan, void *data);
t_token					*match_or(t_parser *self, char **scan, void *data);

t_token					*match_char(t_parser *self, char **scan, void *data, char c);
t_token					*match_id(t_parser *self, char **scan, void *data);
t_token					*match_num(t_parser *self, char **scan, void *data);

t_token					*ft_parse(t_parser *self, char **scan, void *data);

#endif
