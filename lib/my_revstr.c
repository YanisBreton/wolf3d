/*
** my_strlen.c for my_strlen in /home/lecler_i//afs/Jour_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Oct  4 10:43:23 2012 thomas leclercq
** Last update Tue Nov  6 16:22:17 2012 thomas leclercq
*/

char    *my_revstr(char *str)
{
  int   i;
  int   x;
  char  mem;

  i = 0;
  x = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  i = i - 1;
  while (i > x)
    {
      mem = str[x];
      str[x] = str[i];
      str[i] = mem;
      x = x + 1;
      i = i - 1;
    }
  return (str);
}
