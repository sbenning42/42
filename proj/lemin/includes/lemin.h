/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:15:34 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/21 12:04:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define CS_O "vscdn"
# define O_VERB 1
# define O_STEP 2
# define O_COUNT 4
# define O_DEBUG 8
# define O_NAME 16

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
# define LEM_LOGIC_ERR -11
# define LEM_LITIGE_ROOM_ERR -12
# define LEM_FORBIDDEN_ROOM_ERR -13
# define LEM_POSITION_ROOM_ERR -14

# define LEM_SMALLPOP_MSG "Lem-in Population must be at least `1`"
# define LEM_NOPOP_MSG "Can't find the Population size"
# define LEM_MALLOC_MSG "Memory allocation error occured"

# define LEM_ROOM_FMT_1 "The room's format must be: "
# define LEM_ROOM_FMT_2 "`Room_name X_poition Y_position`"
# define LEM_ROOM_FMT_MSG LEM_ROOM_FMT_1 LEM_ROOM_FMT_2

# define LEM_DUPLICATE_ROOM_MSG "Two rooms can't have the same name"
# define LEM_HALL_FMT_MSG "The hall's format must be: `Room_name_1-Room_name_2`"

# define LEM_CYCLE_HALL_1 "Can't have the same room's name on "
# define LEM_CYCLE_HALL_2 "both side of an hall"
# define LEM_CYCLE_HALL_MSG LEM_CYCLE_HALL_1 LEM_CYCLE_HALL_2

# define LEM_UNKNOW_ROOM_1 "This room's name doesn't exist on "
# define LEM_UNKNOW_ROOM_2 "the room's description"
# define LEM_UNKNOW_ROOM_MSG LEM_UNKNOW_ROOM_1 LEM_UNKNOW_ROOM_2

# define LEM_DUPLICATE_HALL_1 "Can't have the same "
# define LEM_DUPLICATE_HALL_2 "hall description more than once"
# define LEM_DUPLICATE_HALL_MSG LEM_DUPLICATE_HALL_1 LEM_DUPLICATE_HALL_2

# define LEM_LINE_1 "Unknow line format. A line must be: "
# define LEM_LINE_2 "a population size (N), a comment (#comment), "
# define LEM_LINE_3 "a command (##command), a room description (string "
# define LEM_LINE_4 "N N) or an hall description (string-string)"
# define LEM_LINE_FMT_MSG LEM_LINE_1 LEM_LINE_2 LEM_LINE_3 LEM_LINE_4

# define LEM_LOGIC_MSG "Missing command ##start or ##end, or there definition"
# define LEM_UNKNOW_CODE "Unknow error code... Doesn't expect that to happend"
# define LEM_LITIGE_ROOM_MSG "Can't have '-' in a room name"
# define LEM_FORBIDDEN_ROOM_MSG "Can't have 'L' on first char of a room's name"
# define LEM_POSITION_ROOM_MSG "X or Y position is to big/small for an int"

# define LEM_SYNERR_FMT "%s: Syntax error. Line %d: `%s` -> %s.\n"
# define LEM_LOGERR_FMT "%s: Logical error. Line %d: `%s` -> %s.\n"
# define FMT_EOPEN "%s: Cannot open file `%s`\n"

# define LEM_GRAPH_DUMP_1FMT "{gr|ss}Dumping graph "
# define LEM_GRAPH_DUMP_2FMT "`{eoc}{gr|ss|green}%s{eoc}{gr|ss}`{eoc}\n\n"
# define LEM_GRAPH_DUMP_FMT LEM_GRAPH_DUMP_1FMT LEM_GRAPH_DUMP_2FMT

# define LEM_SOLUTION_1 "{gr|ss}Solution "
# define LEM_SOLUTION_2 "{eoc}{gr|ss|green}%d{eoc}{gr|ss}:{eoc} "
# define LEM_SOLUTION_3 "{gr}[{eoc}"
# define LEM_SOLUTION_DUMP_FMT LEM_SOLUTION_1 LEM_SOLUTION_2 LEM_SOLUTION_3

# define LEM_SOLUTION_STABLE_FMT "{gr|red}%d{eoc}{gr}%c{eoc} "
# define LEM_SOLUTION_QUEUE_FMT "{gr|yellow}%d{eoc}{gr}%c{eoc} "
# define LEM_SOLUTION_SPEED_FMT  "{gr|ss}Speed:{eoc} {gr|green}%d{eoc}\n"

# define LEM_BEST_1 "\n{gr|ss|cyan}Best Solution is: "
# define LEM_BEST_2 "{eoc}{gr|ss|green}%d{eoc}{gr|ss|cyan}, "
# define LEM_BEST_3 "with speed of: {eoc}{gr|ss|green}%d{eoc}\n\n"
# define LEM_BEST_SOLUTION_FMT LEM_BEST_1 LEM_BEST_2 LEM_BEST_3

# define LEM_ROOM_DUMP_FMT "\t{gr|cyan}%s{eoc}: ({blue}%d{eoc}, {red}%d{eoc})\n"
# define LEM_PATH_DUMP_FMT "{gr|cyan}%d{eoc}{gr}%c{eoc} "

# define LEM_NOPATH_1 "%s: Logical error: No path found between"
# define LEM_NOPATH_2 " `%s` and `%s`.\n"
# define LEM_NOPATH_FMT LEM_NOPATH_1 LEM_NOPATH_2

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
typedef struct s_lem	t_lem;
typedef struct s_err	t_err;
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
	int					lucky;
};

struct					s_sol
{
	int					*stable;
	int					*queue;
	size_t				size;
	int					timer;
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

int						parsing\
						(int fd, t_graph *rooms, t_cons *rules);

int						parse_tag(char *line, int *state);
int						parse_pop(char *line, int *state, t_cons *rules);

int						parse_room\
						(char *line, int *state, t_graph *rooms, t_cons *rules);

int						parse_hall(char *line, int *state, t_graph *rooms);

int						resolve\
						(t_graph *rooms, t_graph *paths,\
						t_cons *rules, t_list **solutions);

int						is_in_neig(t_graph *paths, int id1, int id2);
size_t					lst_size(t_list *l);
void					fill_step(int *t, t_list *l);
int						push_step(t_btrack *backtrack);
int						pop_step(t_btrack *backtrack);

int						save_path(t_graph *path, t_btrack *backtrack);

void					fill_neig(t_graph *paths, int id);

void					get_paths_by_backtrack\
						(t_graph *rooms, t_graph *paths, t_cons *rules);

void					get_solutions_by_backtrack\
						(t_graph *paths, t_list **solutions);

t_lem					*get_lem(t_sol *sol, t_cons *rules, t_graph *paths);

int						play\
						(t_graph *rooms, t_graph *paths,\
						t_cons *rules, t_list **solutions);

void					dump_room(void *meta);
void					dump_path(void *meta);
void					dump_graph(t_graph *g, char *name, void (*f)(void *));
void					dump_solutions(t_list *l);

void					destroy_all\
						(t_graph *rooms, t_graph *paths, t_list **solutions);

#endif
