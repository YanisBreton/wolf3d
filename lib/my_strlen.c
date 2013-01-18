/*
** my_strlen.c for my_strlen in /home/lecler_i//afs/Jour_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Oct  4 10:43:23 2012 thomas leclercq
** Last update Sat Dec 15 18:20:23 2012 thomas leclercq
*/

int	my_strlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
