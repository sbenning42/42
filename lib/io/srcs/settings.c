/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 15:29:00 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/15 14:29:27 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

t_dic_entry		*io_defsettings(void)
{
	t_dic_entry	*settings;
	t_dic_entry	*setting;
	void		*content;
	int			key[2];

	key[1] = 0;
	settings = NULL;
	key[0] = 3;
	content = io_ctrlc_handle;
	setting = ft_dicnew((char *)key, &content, sizeof(t_io_handle_f));
	if (!setting)
		return (NULL);
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 4;
	content = io_ctrld_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);

	
	
	key[0] = 26;
	content = io_ctrlz_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	
	
	
	
	
	key[0] = 9;
	content = io_tab_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 127;
	content = io_retarr_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 10;
	content = io_nl_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 4283163;
	content = io_up_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 4414235;
	content = io_right_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 4348699;
	content = io_down_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 4479771;
	content = io_left_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	key[0] = 2117294875;
	content = io_suppr_handle;
	setting = ft_dicnew((char *)key, (void *)&content, sizeof(t_io_handle_f));
	if (!setting)
	{
		ft_dicdel(&settings, NULL);
		return (NULL);
	}
	ft_dicadd(&settings, setting, dic_sort);
	return (settings);
}
