/*
** my_strncpy.c for my_strncpy in /home/lecler_i//afs/Jour_06
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 09:03:39 2012 thomas leclercq
** Last update Tue Oct  9 10:30:02 2012 thomas leclercq
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  while (i < my_strlen(src))
    {
      if (nb > my_strlen(src))
	{
	  dest[i] = 0;
	}
	i = i + 1;
    }
  return (dest);
}
