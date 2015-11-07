#ifndef FT_PUT_H
# define FT_PUT_H

# include "ft_header.h"
# include "ft_str.h"

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putendl_err(char const *str);
void	ft_putstr_err(char const *str);
void	ft_putchar_err(char c);
void	ft_putnbr_err(int nbr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
