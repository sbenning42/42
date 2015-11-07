#include "input.h"

void		input_init_sig(t_sig *sig_ref)
{
	ft_bzero((void *)sig_ref, sizeof(t_sig) * NB_SIG);
	sig_ref[0].type = SIG_RET_ARR;
	sig_ref[0].val[0] = 127;
	sig_ref[1].type = SIG_NL;
	sig_ref[1].val[0] = 10;
	sig_ref[2].type = SIG_UP;
	sig_ref[2].val[0] = 27;
	sig_ref[2].val[1] = 91;
	sig_ref[2].val[2] = 65;
	sig_ref[3].type = SIG_DOWN;
	sig_ref[3].val[0] = 27;
	sig_ref[3].val[1] = 91;
	sig_ref[3].val[2] = 66;
	sig_ref[4].type = SIG_LEFT;
	sig_ref[4].val[0] = 27;
	sig_ref[4].val[1] = 91;
	sig_ref[4].val[2] = 68;
	sig_ref[5].type = SIG_RIGHT;
	sig_ref[5].val[0] = 27;
	sig_ref[5].val[1] = 91;
	sig_ref[5].val[2] = 67;
	}

int		input_handle(t_input *input, t_sig *sig_ref/*, t_handle *handle*/)
{
	unsigned int	i;
	int		ret;
	char		*tmp;

	i = 0;
	ret = read(0, input->buff, K_SIZE);
	if (ret < 0)
		return (0);
	while (i < NB_SIG)
	{
		if (!ft_strcmp(sig_ref[i].val, input->buff))
		{
			input->sig = sig_ref[i].type;
			ft_strclr(input->buff);
			return (1);//handle[i](input));
		}
		++i;
	}
	tmp = input->cmd;
	input->cmd = ft_strjoin(tmp, input->buff);
	if (input->cmd == NULL)
		return (0);
	ft_strdel(&tmp);
	input->sig = NO_SIG;
	return (1);
}
