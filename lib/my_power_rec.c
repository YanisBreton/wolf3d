/*
** my_power_rec.c for my_power_rec in /home/lecler_i//afs/Jour_05
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Fri Oct  5 13:19:36 2012 thomas leclercq
** Last update Mon Oct  8 17:37:31 2012 thomas leclercq
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    {
      return (1);
    }
  power = power - 1;
  return (nb * my_power_rec(nb, power));
}
