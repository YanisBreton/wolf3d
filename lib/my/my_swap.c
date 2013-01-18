/*
** my_swap.c for my_swap in /home/lecler_i//afs/Jour_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Oct  4 08:58:05 2012 thomas leclercq
** Last update Mon Oct 15 13:05:10 2012 thomas leclercq
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *b;
  *b = *a;
  *a = c;
}
