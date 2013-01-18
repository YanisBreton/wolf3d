/*
** my_strlcat.c for my_strlcat in /home/lecler_i//afs/local/Jour_07/ex_01
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Wed Oct 10 14:51:22 2012 thomas leclercq
** Last update Wed Oct 10 22:08:09 2012 thomas leclercq
*/

char	*my_strlcat(char *dest, char *src, int size)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (dest[a] != 0)
    {
      a = a + 1;
      size = size - 1;
    }
  while (size != 1 && src[b] != 0)
    {
      dest[a] = src[b];
      b = b + 1;
      a = a + 1;
      size = size - 1;
    }
  if (size == 1 && src[b] == 0)
    {
      dest[a] = 0;
    }
  return (dest);
}
