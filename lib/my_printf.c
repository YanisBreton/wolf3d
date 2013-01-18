/*
** my_printf.c for my_printf in /home/lecler_i//afs/local/my_printf
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Nov 12 12:07:11 2012 thomas leclercq
** Last update Thu Dec 13 09:51:11 2012 thomas leclercq
*/

#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

char	*my_strdup(char *str);
int	my_printf(const char *format, ...);

char	check(const char *str, int p)
{
 int	i;
 char	*flags;
 char	c;

 if (str[p] != '%')
   return (0);
 flags = my_strdup("diouxXbpsmc%S");
 i = 0;
 while (i <= 13)
   {
     if (str[p + 1] == flags[i])
       {       
	 c = flags[i];
	 free(flags);
	 return (c);
       }
     i = i + 1;
   }
 free(flags);
 return (0);
}

int	capital_s(char *str)
{
  int	i;
  int	l;

  l = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  l = l + 1;
	  my_putchar('\\');
	  if (str[i] < 8)
	    l = l + my_putchar('0');
	  if (str[i] < 64)
	    l = l + my_putchar('0');
	  l = my_putnbr_base(str[i], "01234567");
	}
      else
	{
	  l = l + 1;
	  my_putchar(str[i]);
	}
      i = i + 1;
    }
  return (l);
 }

int	print(char c, va_list list)
{
  if (c == 'd' || c == 'i')
    return (my_putnbr_base(va_arg(list, int), "0123456789"));
  if (c == 'o')
    return (my_putnbr_base(va_arg(list, int), "01234567"));
  if (c == 'u')
    return (my_putnbr_base(va_arg(list, int), "0123456789"));
  if (c == 'x')
    return (my_putnbr_base(va_arg(list, int), "0123456789abcdef"));
  if (c == 'X')
    return (my_putnbr_base(va_arg(list, int), "0123456789ABCDEF"));
  if (c == 'b')
    return (my_putnbr_base(va_arg(list, int), "01"));
  if (c == 'p')
    return (my_printf("0x%x", va_arg(list, void *)));
  if (c == 's')
    return (my_putstr(va_arg(list, char *)));
  if (c == 'm')
    return (my_putstr(strerror(errno)));
  if (c == 'c')
    return (my_putchar(va_arg(list, int)));
  if (c == '%')
    return (my_putchar('%'));
  if (c == 'S')
    return (capital_s(va_arg(list, char *)));
}

int	my_printf(const char *format, ...)
{
  va_list	list;
  int		i;
  int		len;

  len = 0;
  i = 0;
  va_start(list, format);
  while (format[i] != '\0')
    {
      if (check(format, i))
	{
	  len = 1 + len + print(format[i + 1], list);
	  i = i + 1;
	}
      else
	{
	  len = len + 1;
	  my_putchar(format[i]);
	}
      i = i + 1;
    }
  return (len);
}
