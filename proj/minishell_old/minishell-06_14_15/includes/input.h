#ifndef INPUT_H
# define INPUT_H

# include "libft.h"
# include "types.h"
# include <termios.h>

int		input_handle(t_input *input, t_sig *sig_ref);
void		input_init_sig(t_sig *sig_ref);

#endif
