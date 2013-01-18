/*
** my_strcmp.c for strcmp in /home/lecler_i//afs/local/lib/my
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Fri Nov 16 11:28:51 2012 thomas leclercq
** Last update Fri Dec 14 16:04:09 2012 thomas leclercq
*/

int	my_strcmp(char *s1, char *s2, int len)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      if (i == len)
	return (0);
      i++;
    }
  return (s1[i] - s2[i]);
}
