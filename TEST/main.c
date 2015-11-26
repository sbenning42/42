/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:52:05 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/25 13:30:23 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/ioctl.h>

int		main(void)
{
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	char	buf[w.ws_col + 1];
	int		i = w.ws_row;

	ft_memset((void *)buf, ' ', w.ws_col);
	buf[w.ws_col] = 0;
	while (i)
	{
		ft_printf("{f-blue|ss|grey|gr}%s{eoc}", buf);
		ft_printf("{f-blank|ss|cyan|gr}%s{eoc}", buf);
		ft_printf("{f-red|ss|yellow|gr}%s{eoc}", buf);
		ft_printf("{f-green|ss|pink|gr}%s{eoc}", buf);
		ft_printf("{f-yellow|ss|red|gr}%s{eoc}", buf);
		ft_printf("{f-pink|ss|green|gr}%s{eoc}", buf);
		ft_printf("{f-cyan|ss|blank|gr}%s{eoc}", buf);
		ft_printf("{fgrey|ss|blue|gr}%s{eoc}", buf);
		i--;
	}
	return (0);
}
