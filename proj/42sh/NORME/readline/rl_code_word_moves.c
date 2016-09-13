/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_p4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:39:14 by sbenning          #+#    #+#             */
/*   Updated: 2016/04/19 10:43:25 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_code_wright(t_rl *rl)
{
	int		i;
	char	*str;

	if (!rl->dyn.post)
		return (0);
	str = rl->dyn.strend - rl->dyn.post;
	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (!(str = ft_strnew(i)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpoppost(&rl->dyn, str, i);
	dyn_strpushante(&rl->dyn, str, i);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_forward(i);
	return (0);
}

int			rl_code_wleft(t_rl *rl)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rl->dyn.ante)
		return (0);
	i = rl->dyn.ante - 1;
	j = rl->dyn.ante;
	while (i > 0 && rl->dyn.str[i] == ' ')
		i--;
	while (i > 0 && rl->dyn.str[i - 1] != ' ')
		i--;
	if (!(str = ft_strnew(j - i)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpopante(&rl->dyn, str, j - i);
	dyn_strpushpost(&rl->dyn, str, j - i);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_backward(j - i);
	return (0);
}
