/*
** my_strlowcase.c for my_strlowcase in /home/lecler_i//afs/Jour_06/ex_08
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 14:12:32 2012 thomas leclercq
** Last update Mon Oct  8 16:34:24 2012 thomas leclercq
*/

int	is_num(char car)
{
  if (car >= '0' && car <= '9')
    {
      return (1);
    }
  return (0);
}

int	my_str_isnum(char *str)
{
  int	i;
  int	bool;

  i = 0;
  bool = 1;
  if (str[i] == 0)
    {
      return (1);
    }
  while (str[i] != 0 && bool)
    { 
      if (!is_num(str[i]))
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
