/*
** my_strcat.c for my_strcat in /home/lecler_i//afs/local/Jour_07/ex_01
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Tue Oct  9 13:10:39 2012 thomas leclercq
** Last update Sat Dec 15 18:21:45 2012 thomas leclercq
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	lenght;


  if (!src)
    return (dest);
  lenght = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[lenght + i] = src[i];
      i = i + 1;
    }
  dest[lenght + i] = '\0';
  return (dest);
}
