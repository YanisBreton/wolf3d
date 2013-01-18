/*
** my_put_nbr.c for my_put_nbr in /home/lecler_i//afs/Jour_03
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Wed Oct  3 12:04:30 2012 thomas leclercq
** Last update Sat Nov 17 17:55:45 2012 thomas leclercq
*/

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
    }
  my_putchar('0' + nb);
}
