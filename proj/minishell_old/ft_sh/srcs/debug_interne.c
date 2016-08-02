/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_interne.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:40:55 by sbenning          #+#    #+#             */
/*   Updated: 2016/02/17 17:42:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		start_debug(\
			char *what)
{
	char	*fmt;

	FDDEBUG = 2;
	if (IS(O_COLOR, OPT) && IS(O_DEBUG, OPT))
		fmt = FMT_COL_S_DEBUG;
	else
		fmt = FMT_STD_S_DEBUG;
	if (IS(O_FILEDEBUG, OPT))
	{
		FDDEBUG = open(DEBUG_FILE_NAME, (O_CREAT | O_WRONLY | O_APPEND));
		chmod(DEBUG_FILE_NAME, S_IRWXU | S_IRWXG | S_IRWXO);
		if (FDDEBUG < 0)
		{
			error(Open, DEBUG_FILE_NAME, EXIT_SUCCESS);
			FDDEBUG = 2;
			return ;
		}
	}
	ft_fprintf(FDDEBUG, fmt, AV, "Debug", what);
}

void		end_debug(\
			char *what)
{
	char	*fmt;

	if (IS(O_COLOR, OPT) && IS(O_DEBUG, OPT))
		fmt = FMT_COL_E_DEBUG;
	else
		fmt = FMT_STD_E_DEBUG;
	ft_fprintf(FDDEBUG, fmt, what);
	if (FDDEBUG != 2)
		close(FDDEBUG);
}
