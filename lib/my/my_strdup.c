/*
** my_strdup.c for my_strdup in /home/lecler_i//afs/local/Jour_08/ex_01
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Wed Oct 10 09:32:08 2012 thomas leclercq
** Last update Wed Dec 12 23:05:38 2012 thomas leclercq
*/
#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  char	*ptr;

  ptr = malloc(my_strlen(src) + 1);
  i = 0;
  while (src[i])
    {
      ptr[i] = src[i];
      i = i + 1;
    }
  ptr[i] = 0;
  return (ptr);
}
