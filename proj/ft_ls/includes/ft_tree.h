/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:16:45 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/16 09:52:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

# include "ft_header.h"
# include "ft_mem.h"

typedef struct		s_node
{
	void			*content;
	size_t			content_size;
	struct s_node	*f;
	struct s_node	*l;
	struct s_node	*r;
}					t_node;

void				tree_doinf(t_node *r, void (*d)(void *, size_t));
t_node				*tree_newnode(void *content, size_t size);
void				tree_add\
					(t_node **ar, t_node *no, int (*s)(void *, void *));
void				tree_del(t_node **ar, void (*d)(void *, size_t));

#endif
