/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:15:34 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/09 15:05:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define CS_O "v"
# define O_VERB 0x1

# define FMT_EOPEN "%s: Cannot open file `%s`\n"

# define IS_O(X, Y) (X & Y)
# define SET_O(X, Y) (X |= Y)
# define UNS_O(X, Y) (X &= ~Y)

# include "libft.h"
# include "proginfo.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <limits.h>

typedef struct s_node	t_node;
typedef struct s_graph	t_graph;
typedef struct s_cons	t_cons;
typedef struct s_sol	t_sol;
typedef struct s_room	t_room;
typedef struct s_path	t_path;
typedef struct s_btrack	t_btrack;

struct					s_node
{
	int				id;
	int				*neig;
	size_t				neig_size;
	void				*meta;
};

struct					s_graph
{
	t_node				*node;
	size_t				size;
	size_t				mem_size;
};

struct					s_cons
{
	int				pop;
	int				id_s;
	int				id_e;
};

struct					s_sol
{
	int				*stable;
	int				*queue;
	size_t				size;
	int				timer;
	int				best;
};

struct					s_room
{
	char				*name;
	int				x;
	int				y;
};

struct					s_path
{
	int				*step;
	size_t				size;
};

struct					s_btrack
{
	int				id;
	t_list				*path;
};

void					lemin(int fd);

int					parsing(int fd, t_graph *rooms, t_cons *rules);
int					resolve(t_graph *rooms, t_graph *paths, t_cons *rules, t_list **solutions);
int					play(t_graph *rooms, t_graph *paths, t_cons *rules, t_list **solutions);

#endif
