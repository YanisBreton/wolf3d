/*
** my_strcpy.c for my_strcpy in /home/lecler_i//afs/Jour_06
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 09:03:39 2012 thomas leclercq
** Last update Tue Oct  9 10:28:58 2012 thomas leclercq
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
