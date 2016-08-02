/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_do.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:58:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 12:59:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void			ft_dicdoinf(\
				t_dic *dic, void (*f)(t_dic *))
{
	if (dic && dic->l)
		ft_dicdoinf(dic->l, f);
	if (f)
		f(dic);
	if (dic && dic->r)
		ft_dicdoinf(dic->r, f);
}

void			ft_dicdopref(\
				t_dic *dic, void (*f)(t_dic *))
{
	if (f)
		f(dic);
	if (dic && dic->l)
		ft_dicdoinf(dic->l, f);
	if (dic && dic->r)
		ft_dicdoinf(dic->r, f);
}

void			ft_dicdosuf(\
				t_dic *dic, void (*f)(t_dic *))
{
	if (dic && dic->l)
		ft_dicdoinf(dic->l, f);
	if (dic && dic->r)
		ft_dicdoinf(dic->r, f);
	if (f)
		f(dic);
}

void			*ft_dicentry(\
				t_dic *dic, char *id)
{
	int			ret;

	if (!dic)
		return (NULL);
	if (!(ret = ft_strcmp(dic->id, id)))
		return (dic->content);
	else if (ret > 0)
		return (ft_dicentry(dic->l, id));
	else
		return (ft_dicentry(dic->r, id));
}
