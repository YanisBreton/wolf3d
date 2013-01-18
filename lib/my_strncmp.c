/*
** my_strcmp.c for strcmp in /home/lecler_i//afs/local/lib/my
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Fri Nov 16 11:28:51 2012 thomas leclercq
** Last update Thu Jan 17 22:26:37 2013 thomas leclercq
*/

int	my_strncmp(char *s1, char *s2, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
