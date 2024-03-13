#include <../ft_printf.h>

//this function count the hexdecimal digits in a pointer representation
static int  ft_counter(unsigned long long ptr)
{
    int count;

    count = 0;

    while (ptr != 0)
    {
        count++;
        ptr /= 16;
    }
    return (count);
}


int ft_printpointer(unsigned long long ptr)
{
    if(ptr >= 16)
    {
        ft_printpointer(ptr / 16);
        ft_printpointer(ptr % 16);
    }
    else
    {
        if(ptr <= 9)
            ft_putchar(ptr + '0');
        else    
            ft_putchar(ptr - 10 + 'a');    
    }
    return (ft_counter(ptr));
}

int ft_putpointer(unsigned long long ptr)
{
    int len;

    len = 0;

     if(ptr == 0)//if the ptr = NULL print null and return it's len which = 0
     {
        len += write (1, "(nil)", 5);
        return (len);
     }
     len = write(1, '0x', 2);
     len += ft_printpointer(ptr);
     return (len);
}