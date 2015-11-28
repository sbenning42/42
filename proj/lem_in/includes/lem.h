#ifndef LEM_H
# define LEM_H

# include "libft.h"
# include "get_next_line.h"

typedef enum	e_lem_state
{
	None,
	Wait_lem,
	Wait_start,
	Wait_end,
	Wait_data,
	Lem_error
}		t_lem_state;

typedef struct	s_lem_room
{
	char	*name;
	int	id;
	char	*x;
	char	*y;
}		t_lem_room;

typedef struct	s_lem_map
{
	int	lem;
	t_list	*room;
	int	size;
	int	*madj;
	int	*madj_path;
	int	id_s;
	int	id_e;
	t_list	*pathtab;
	size_t	size_tab;
//	t_list	*stable;
//	size_t	size_stable;
}		t_lem_map;
/*
typedef struct	s_stable
{
	t_list	*id;
	t_list	*pound;
	size_t	size;
	int	tpound;
}		t_stable;
*/
//int		sigma_len(t_list *l1, t_list *l2);
int		fill_madj_path(t_lem_map *map);
//int		select_faster(t_lem_map *map);
//int		select_path(t_lem_map *map);
//int		select_stable(t_lem_map *map);
void	print_path(t_list *path);
void		lem_get_room(char **data, t_lem_map *map, t_lem_state *state);
void		lem_get_pipe(char **data, t_lem_map *map, t_lem_state *state);
void	lem_del_path(t_list *path);
void		lem_del(t_lem_map *map);
void		lem_del_data(char **data);
int		lem_check_data(char **data);
int		found_path(t_lem_map *map, int src, t_list *path);
int		lem_exec(t_lem_map *map);
void		lem(int fd);

#endif
