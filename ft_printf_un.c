#include "../ft_printf.h"

int ft_len_num(unsigned int n)
{
    int len;

    len = 0;

    while(n != 0)
    {
        len++;
        n /=10;
    }
    return(len);
}

char	*ft_utoa(unsigned int n)//need to be read
{
	char	*num;
	int		len;

	len = ft_length_num(n);
	num = (char *)malloc((len + 1) * sizeof(char *));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int ft_putunsigned(unsigned int n)
{
    int len;
    char *num;

    len = 0;
    if(n == 0)
    {
        len += write(1, "0", 1);
    }

    else{
        num = ft_utoa(n);
        len += ft_putstr(num);
        free(num);
    }
    return (len);
}