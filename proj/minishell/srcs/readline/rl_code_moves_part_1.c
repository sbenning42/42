/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_code_moves_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:36:01 by sbenning          #+#    #+#             */
/*   Updated: 2016/09/12 13:38:24 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_code_home(t_rl *rl)
{
	char	*str;
	size_t	len;

	if (!(len = rl->dyn.ante))
		return (0);
	if (!(str = ft_strnew(len)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpopante(&rl->dyn, str, len);
	dyn_strpushpost(&rl->dyn, str, len);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_backward(len);
	return (0);
}

int			rl_code_end(t_rl *rl)
{
	char	*str;
	size_t	len;

	if (!(len = rl->dyn.post))
		return (0);
	if (!(str = ft_strnew(len)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpoppost(&rl->dyn, str, len);
	dyn_strpushante(&rl->dyn, str, len);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_go_forward(len);
	return (0);
}

int			rl_code_pageup(t_rl *rl)
{
	char	*str;
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.ante <= co)
		return (rl_code_home(rl));
	if (!(str = ft_strnew(co)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpopante(&rl->dyn, str, co);
	dyn_strpushpost(&rl->dyn, str, co);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_up();
	return (0);
}

int			rl_code_pagedown(t_rl *rl)
{
	char	*str;
	size_t	co;

	co = cur_get_scrco() + 1;
	if (rl->dyn.post <= co)
		return (rl_code_end(rl));
	if (!(str = ft_strnew(co)))
		cur_exit(EXIT_FAILURE, "Memory allocation");
	dyn_strpoppost(&rl->dyn, str, co);
	dyn_strpushante(&rl->dyn, str, co);
	free(str);
	if (ISIN(rl->settings, RL_ECHO))
		cur_xdo(1);
	return (0);
}
