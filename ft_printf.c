
//va_list --> is a type in C uses to access a variable number id arguments passes
//to variadic function 

//variadic function is a function that can taked a variable number of arguments
//va_start -->used to insialize the va_list
//va_args -->retrieves the next argument from the variable arguments list
//va_end

//this function is handling the formats 
//ig (%c, %s, %d, %zu, etc..)

int ft_printf_arg(va_list args, const char format)
{
    if(format == 'c')
        return(ft_puchar(va_arg(args,int)));
    else if(format == 's')
        return(ft_putstr(va_arg(args, char *)));
    else if(format == 'p')
        return(ft_putpointer(va_arg(args, unsigned long long)));
    else if(format == 'd' || format == 'i')
        return (ft_putnumb(va_arg(args, int)));
    else if(format == 'u')
        return(ft_putunsigned(va_arg(args, unsigned int)));
    else if(format == 'x' || format == 'X')//x for the hexadecimal
        return(ft_puthexad(va_arg(args, unsigned int),format));//format to represint wheather the hexadecimal num will be lower or upper case 
    else if(format == '%')
        return(ft_putchar('%'));
    return 0;                

}


int ft_printf(const char *format, ...)
{
    va_list    args;
    size_t i = 0;
    int len;

    va_start(args,format);

    if(!format)//error handling in case there is no formate has been bathed
    {
        return (-1);
    }
    
    while(format[i]){
        if(format == '%')//if we found the % (formate specifier) we move one step i + 1 to the char after and pass it to the ft_printf_args
        {
            len += ft_printf_arg(args, format[i + 1]);
            i++;
        }
        else
        {
            len += ft_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return(len);//returning the len means that the totale lenght of the string has been prossesed 
}

