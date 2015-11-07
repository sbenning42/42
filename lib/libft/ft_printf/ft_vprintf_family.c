#include "ft_printf.h"

int	ft_vfprintf(int fd, const char *format, va_list ap)
{
	int	len;

	len = ft_vlprintf(format, ap);
	flush_fd(fd);
	return (len);
}

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	int	len;

	len = ft_vlprintf(format, ap);
	flush_str(str);
	return (len);
}


int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int	len;

	len = ft_vlprintf(format, ap);
	flush_nstr(str, size);
	return (len);
}
