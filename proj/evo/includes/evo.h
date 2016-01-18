/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evo.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:30:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/01/18 14:33:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVO_H
# define EVO_H

# include <mlx.h>
# include "libft.h"

# define HEIGHT 640
# define WIDTH 640

# define QUITKEY 53
# define POPSIZE 5

# define LVPOP 1
# define LVUPPVMIN 1
# define LVUPPVMAX 2
# define LVUPDEATHMIN 1
# define LVUPDEATHMAX 2
# define LVUPEVOMIN 1
# define LVUPEVOMAX 2

# define PVPOPMIN 4
# define PVPOPMAX 5

# define DEATHPOPMIN 5
# define DEATHPOPMAX 10

# define DUPLPOPMIN 50
# define DUPLPOPMAX 75

# define EVOPOPMIN 10
# define EVOPOPMAX 20

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	char			*av;
	t_list			*pop;
}					t_env;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_unit
{
	t_pos			pos;
	int				lv;
	int				pv;
	int				death;
	int				dupl;
	int				evo;
}					t_unit;

void			init_random(void);
int				random_rank(int a, int b);
t_list			*random_pop(size_t size);
t_pos			random_pos(t_pos pos);
void			evo_err(char *id, char *msg, int rtnval);
void			evo_success(char *id, char *msg);
int				evo_loop(void *p);
int				evo_key(int key, void *p);
int				evo_expose(void *p);

#endif
