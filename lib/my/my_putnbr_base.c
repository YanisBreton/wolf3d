/*
** my_put_nbr.c for my_put_nbr in /home/lecler_i//afs/Jour_03
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Wed Oct  3 12:04:30 2012 thomas leclercq
** Last update Sun Jan 13 20:56:24 2013 lecler_i
*/

void	my_putnbr_base(int nb, char *base)
{
  int	base_len;

  base_len = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > base_len - 1)
    {
      my_putnbr_base(nb / base_len, base);
    }
  my_putchar(base[nb % base_len]);
}
