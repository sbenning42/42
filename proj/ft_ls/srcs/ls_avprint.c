/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_avprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:53:12 by sbenning          #+#    #+#             */
/*   Updated: 2015/12/15 17:03:37 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		avp_print(t_node *no)
{
	t_ls_entry	*e;

	e = (t_ls_entry *)p;
	ft_printf("%s\n", e->key);
	(void)size;
}

void		avp_cprint(t_node *no)
{
	(void)no;
}

void		avp_lprint(t_node *no)
{
	(void)no;
}

void		avp_clprint(t_node *no)
{
	(void)no;
}

