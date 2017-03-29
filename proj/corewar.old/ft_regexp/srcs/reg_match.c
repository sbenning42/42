/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_match.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 15:57:04 by sbenning          #+#    #+#             */
/*   Updated: 2017/03/26 17:00:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regexp.h"


typedef struct s_reg_match		t_reg_match;

struct s_reg_match
{
	int		type;
	char	*start;
	char	*end;
	int		quantity;
	t_reg_match	*next;
};

int				get_return(int quantity, int found)
{
	if (!found)
		return (((quantity == 14 || quantity == 15) ? 1 : 0));
	return (1);
}

int				reg_match_litteral(char **scan, t_reg_match *matcha)
{
	int			ret;
	size_t		len;
	int			found;

	ret = 0;
	found = 0;
	len = ft_strlen(matcha->start);
	while (ret == 0)
	{
		if (!(ret = ft_strncmp(*scan, matcha->start, len)))
		{
			found = 1;
			*scan += len;
			if (matcha->quantity == 1 || matcha->quantity == 14)
				return (1);
		}
	}
	return (get_return(matcha->quantity, found));
}

int				reg_match_range(char **scan, t_reg_match *matcha)
{
	int			found;

	found = 0;
	while (42)
	{
		if (**scan >= *(matcha->start) && **scan <= *(matcha->end))
		{
			found = 1;
			*scan += 1;
			if (matcha->quantity == 1 || matcha->quantity == 14)
				return (1);
		}
		else
			break ;
	}
	return (get_return(matcha->quantity, found));

}

t_reg_match	*reg_new_matcha(int type, char *start, char *end, int quantity)
{
	t_reg_match	*matcha;

	matcha = ft_memalloc(sizeof(t_reg_match));
	matcha->type = type;
	matcha->start = start;
	matcha->end = end;
	matcha->quantity = quantity;
	return (matcha);
}

void			reg_add_matcha(t_reg_match **lst, t_reg_match *matcha)
{
	t_reg_match	*drive;

	if (!*lst)
	{
		*lst = matcha;
		return ;
	}
	drive = *lst;
	while (drive->next)
		drive = drive->next;
	drive->next = matcha;
}

int				reg_match(t_regex_lexem *lst, char *scan)
{
	t_reg_match	*mlst;
	t_reg_match	*matcha;
	int			n;

	mlst = NULL;
	while (lst)
	{
		if (lst->id == 21)
		{
			if (lst->next && lst->next->id >= 14 && lst->next->id <= 16)
				n = lst->next->id;
			else
				n = 1;
			matcha = reg_new_matcha(0, lst->value, NULL, n);
			reg_add_matcha(&mlst, matcha);
		}
		else if (lst->id == 20 && lst->next->id == 20)
		{
			if (lst->next->next && lst->next->next->id >= 14 && lst->next->next->id <= 16)
				n = lst->next->next->id;
			else
				n = 1;
			matcha = reg_new_matcha(1, lst->value, lst->next->value, n);
			reg_add_matcha(&mlst, matcha);
		}
		lst = lst->next;
	}
	while (*scan && mlst)
	{
		if (mlst->type == 0)
		{
			if (!reg_match_litteral(&scan, mlst))
				return (0);
		}
		else
		{
			if (!reg_match_range(&scan, mlst))
				return (0);
		}
		mlst = mlst->next;
	}
	return ((*scan ? 0 : 1));
}
