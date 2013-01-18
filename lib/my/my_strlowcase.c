/*
** my_strlowcase.c for my_strlowcase in /home/lecler_i//afs/Jour_06/ex_08
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 14:12:32 2012 thomas leclercq
** Last update Mon Oct  8 14:59:39 2012 thomas leclercq
*/

char	*my_strlowcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  str[i] = str[i] + ('a' - 'A');
	}
      i = i + 1;
    }
  return (str);
}
