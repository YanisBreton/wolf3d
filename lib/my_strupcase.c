/*
** my_strupcase.c for my_strupcase in /home/lecler_i//afs/Jour_06/ex_07
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 14:12:32 2012 thomas leclercq
** Last update Mon Oct  8 14:52:56 2012 thomas leclercq
*/

char	*my_strupcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] = str[i] - ('a' - 'A');
	}
      i = i + 1;
    }
  return (str);
}
