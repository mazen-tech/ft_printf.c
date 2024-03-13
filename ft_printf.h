#ifndef FT_PRINTF_H
# define FT_PRINT_H

#include <unistd.h>
#include <stdarg.h>
#include "libft.c/libft.h"

int		ft_printf(const char *format, ...);
int     ft_putchar(char c);
int     ft_putstr(char *str);
int     ft_putnumb(int num);
int		ft_putpointer(unsigned long long ptr);
int		ft_putunsigned(unsigned int n);
int		ft_puthexadecimal(unsigned int num, const char type);



#endif
