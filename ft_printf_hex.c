#include "../ft_printf.h"

//function to retune the length hexadecimal numbers
int ft_hexlen(unsigned int n)
{
    int len;

    len = 0;
    while(n != 0)
    {
        n = n / 16;
        len ++;
    }
    return (len);
}

//this function convert an unsigned int to
//hexadecimal string and print it it 

void ft_printhex(unsigned int n, const char format)
{
    if(n >= 16)
    {
        ft_printhex(n / 16, format);
        ft_printhex(n % 16, format);
    }

    else
    {
        if(n <= 9)//if n <= that means the the number full in the rang of the single hexadecimal
            ft_putchar((n + '0'));

        else
        {
            if(format == 'x')
                ft_putchar((n - 10 + 'a'));//is used to calculate the ASCII value of the lowercase/uppercase digit
            if(format == 'X')
                ft_putchar((n - 10 + 'A'));    
        }
    }
}



int	ft_puthexadecimal(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhex(num, type);
	return (ft_hexlen(num));
}