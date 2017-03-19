/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:15:34 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/19 11:55:49 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define CS_O "v"
# define O_VERB 0x1

# define LEM_NOERR 0
# define LEM_SMALLPOP_ERR -1
# define LEM_NOPOP_ERR -2
# define LEM_MALLOC_ERR -3
# define LEM_ROOM_FMT_ERR -4
# define LEM_DUPLICATE_ROOM_ERR -5
# define LEM_HALL_FMT_ERR -6
# define LEM_CYCLE_HALL_ERR -7
# define LEM_UNKNOW_ROOM_ERR -8
# define LEM_DUPLICATE_HALL_ERR -9
# define LEM_LINE_FMT_ERR -10

# define FMT_EOPEN "%s: Cannot open file `%s`\n"

# define LEM_COMMENT_CHAR '#'
# define LEM_ROOM_CHAR ' '
# define LEM_HALL_CHAR '-'

# define LEM_ROOM_SIZE 3
# define LEM_HALL_SIZE 2

# define LEM_POP_STATE -1
# define LEM_DEFAULT_STATE 0
# define LEM_START_STATE 1
# define LEM_END_STATE 2

# define LEM_START_CMD "start"
# define LEM_END_CMD "end"

# define IS_O(X, Y) (X & Y)
# define SET_O(X, Y) (X |= Y)
# define UNS_O(X, Y) (X &= ~Y)

# define ACCESS_META(G, I) G->node[I].meta
# define ACCESS_ROOM_META(G, I) ((t_room *)ACCESS_META(G, I))
# define ACCESS_PATH_META(G, I) ((t_path *)ACCESS_META(G, I))

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
typedef struct s_lem 	t_lem;
typedef struct s_err 	t_err;
typedef struct s_lemcmd	t_lemcmd;
typedef struct s_btrack	t_btrack;

struct					s_node
{
	int					id;
	int					*neig;
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
	int					pop;
	int					id_s;
	int					id_e;
};

struct					s_sol
{
	int					*stable;
	int					*queue;
	size_t				size;
	int					timer;
	int					best;
};

struct					s_room
{
	char				*name;
	int					x;
	int					y;
};

struct					s_path
{
	int					*step;
	size_t				size;
};

struct					s_lem
{
	int					id_path;
	int					timer;
	int					stage;
};

struct					s_lemcmd
{
	char				*cmd;
	int					state;
};

struct					s_btrack
{
	int					id;
	t_list				*path;
};

struct					s_err
{
	int					code;
	char				*msg;
};

extern t_lemcmd			g_cmd[];
extern t_err			g_err[];

void					lemin(int fd);

void					delete_tab(char ***tab);

int						get_id_by_name(t_graph *rooms, char *name);
int						is_in_neig(t_graph *rooms, int id1, int id2);

int						parsing\
						(int fd, t_graph *rooms, t_cons *rules);

int						parse_tag(char *line, int *state);
int						parse_pop(char *line, int *state, t_cons *rules);

int						parse_room\
						(char *line, int *state, t_graph *rooms, t_cons *rules);

int						resolve\
						(t_graph *rooms, t_graph *paths,\
						t_cons *rules, t_list **solutions);

int						play\
						(t_graph *rooms, t_graph *paths,\
						t_cons *rules, t_list **solutions);

#endif
