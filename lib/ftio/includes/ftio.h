/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftio.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 21:13:30 by sbenning          #+#    #+#             */
/*   Updated: 2015/11/20 01:21:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTIO_H
# define FTIO_H

# include <termios.h>
# include <errno.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft.h"

# define FTIO_BS 5
# define FTIO_NCCS 4

# define FTIO_CC_VCRNL 10
# define FTIO_CC_VERASE 127
# define FTIO_CC_VSUPPR 2117294875
# define FTIO_CC_VTAB 27
# define FTIO_CC_VUP 4283163
# define FTIO_CC_VDOWN 4348699
# define FTIO_CC_VLEFT 4479771
# define FTIO_CC_VRIGHT 4414235

typedef int			(*t_ftio_perform)(char *, char *, size_t);

typedef struct		s_ftio_data
{
	char			*screen;
	int				c_x;
	int				c_y;
	int				max_x;
	int				max_y;
}					t_ftio_data;

typedef struct		s_ftio_key
{
	long int		key;
	t_ftio_perform	key_rule;
}					t_ftio_key;

typedef struct		s_ftio_env
{
	struct termios	term;
	struct termios	cp;
	int				fd;
	t_ftio_key		lc_cc[FTIO_NCCS];
	t_ftio_key		*uc_cc;
}					t_ftio_env;

t_ftio_env			*ftio_env(void);

void				ftio_error_handle(void);
void				ftio_signal_handle(void);
//void				ftio_perform(long int input);
//int					ftio_init_data();
//int					ftio_save_data();
//void				ftio_load_data();
//void				ftio_clear_data();
int					ftio_read(char *buf, size_t size);
void				ftio_init(int fd);
void				ftio_reset(int fd);

#endif
