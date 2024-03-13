#include "../ft_printf.h"

//function to print a single char 
int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}


//function to print a string
//if the string is null print null and return 6 if not print thw str and return it's len if succesfull
int ft_putstr(char *str)
{
    int l;
    if(!str)
    {
        write(1, ("NULL"), 6);
        return (6)
    }

    l = ft_strlen(str);
    write(1, str, l);
    return (len);
    
}


//function to print a number after converting the num to sring

int ft_putnumb(int num)
{
    int len;
    char *str;

    str = ft_itoa(num);
    len = ft_putstr(str);
    free(str);
    return(len);
}