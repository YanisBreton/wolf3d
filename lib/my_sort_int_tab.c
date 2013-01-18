/*
** my_sort_int_tab.c for my_sort_int_tab in /home/lecler_i//afs/local/Jour_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Mon Oct 15 13:41:51 2012 thomas leclercq
** Last update Mon Oct 15 13:54:49 2012 thomas leclercq
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;

  i = 0;
  while (i < size)
    {
      j = i;
      while (j < size)
	{
	  if (tab[i] < tab[j])
	    {
	      my_swap(tab + i, tab + j);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}
