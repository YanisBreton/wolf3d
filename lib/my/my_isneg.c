/*
** my_isneg.c for my_isneg in /home/lecler_i//afs/Jour_03
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Wed Oct  3 10:21:56 2012 thomas leclercq
** Last update Tue Oct  9 10:16:46 2012 thomas leclercq
*/

int	my_isneg(int nb)
{
  if (nb >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
