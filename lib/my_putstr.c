/*
** my_putstr.c for my_putstr in /home/lecler_i//afs/Jour_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Oct  4 09:29:17 2012 thomas leclercq
** Last update Mon Oct 15 13:05:42 2012 thomas leclercq
*/

void	my_putstr(char *str)
{
  int	i;

  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
