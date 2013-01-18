/*
** my_strncat.c for my_strncat in /home/lecler_i//afs/local/Jour_07/ex_02
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Tue Oct  9 13:10:39 2012 thomas leclercq
** Last update Wed Dec 12 22:47:33 2012 thomas leclercq
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	lenght;

  lenght = my_strlen(dest);
  i = 0;
  while (nb > 0)
    {
      dest[lenght + i] = src[i];
      i = i + 1;
      nb = nb - 1;
    }
  dest[lenght + i] = 0;
  return (dest);
}
