 /*
** my_strstr.c for my_strstr in /home/lecler_i//afs/Jour_06/ex_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct  8 11:20:42 2012 thomas leclercq
** Last update Tue Oct  9 10:34:02 2012 thomas leclercq
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	bool;
  
  i = 0;
  while (str[i] != 0)
    {
      j = 0;
      if (str[i] == to_find[0])
	{
	  bool = 0;
	  while (str[i + j] == to_find[j] && to_find[j] != 0 && j < my_strlen(to_find))
	    {
	      bool = 1;
	      j = j + 1;
	    }
	  if (str[i + j] != to_find[j])
	    {
	      bool = 0;
	    }
	  if (bool)
	    {
	      return (&str[i]);
	    }
	}
      i = i + 1;
    }
  return (0);
}
