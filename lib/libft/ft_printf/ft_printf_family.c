#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int	len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vfprintf(1, format, ap);
	va_end(ap);
	return (len);
}

int		ft_fprintf(int fd, const char *format, ...)
{
	int	len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vfprintf(fd, format, ap);
	va_end(ap);
	return (len);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	int	len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (len);
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int	len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (len);
}
