/*
** my_show_wordtab.c for my_showtab.c in /home/lecler_i//afs/local/Jour_08/ex_05
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Oct 11 19:16:01 2012 thomas leclercq
** Last update Fri Oct 12 10:48:13 2012 thomas leclercq
*/

int	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i][0] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
