#include "input.h"
#include <fcntl.h>

static int			term_set(struct termios *attributes)
{
	if (tcgetattr(0, attributes) < 0)
		return (0);
	attributes->c_lflag &= ~ICANON;
	attributes->c_lflag &= ~ECHO;
	attributes->c_cc[VMIN] = 1;
	attributes->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, attributes) < 0)
		return (0);
	return (1);
}

static int			term_reset(struct termios *attributes)
{
	if (tcgetattr(0, attributes) < 0)
		return (0);
	attributes->c_lflag |= ICANON;
	attributes->c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, attributes) < 0)
		return (0);
	return (1);
}

static void		ft_memdump(char *mem, unsigned int size, int fd)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd("\nMem:\t\t", fd);
	while (i < size)
	{
		ft_putstr_fd("[", fd);
		ft_putnbr_fd((int)mem[i], fd);
		++i;
		i == size ? ft_putstr_fd("]\n", fd) : ft_putstr_fd("]-", fd);
	}
}

int			main(int ac, char **av, char **ep)
{
	int		n = 15;
	t_input		input;
	t_sig		sig_ref[NB_SIG];
	struct termios	termcaps;

	if (!ac || !av || !ep)
		return (-2);
	if (!term_set(&termcaps))
		return (-1);
	input_init_sig(sig_ref);
	while (n-- > 0)
	{
		ft_strclr(input.buff);
		if (!input_handle(&input, sig_ref))
			return (-1);
		if (input.sig == NO_SIG)
			ft_putstr((input.cmd) + ft_strlen(input.cmd) - 1);
	}
	if (!term_reset(&termcaps))
		return (-1);
	ft_putstr("\n\n");
	return (0);
}
