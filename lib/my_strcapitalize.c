/*
** my_strlowcase.c for my_strlowcase in /home/lecler_i//afs/Jour_06/ex_08
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 14:12:32 2012 thomas leclercq
** Last update Mon Oct  8 16:10:38 2012 thomas leclercq
*/

char	*my_strcapitalize(char *str)
{
  int i;
  int	bool;
  
  bool = 0;
  i = 0;
  while (str[i] != 0)
    {      
      if (str[i] >= 'a' && str[i] <= 'z' && bool == 0)
	{
	  bool = 1;
	  str[i] = str[i] - ('a' - 'A');
	}
      if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
	{
	  bool = 0;
	}
      i = i + 1;
    }
  return (str);
}
