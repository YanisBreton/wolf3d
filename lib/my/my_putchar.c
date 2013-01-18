/*
** my_putchar.c for my_putchar in /home/lecler_i//afs/Jour_03
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Wed Oct  3 09:22:49 2012 thomas leclercq
** Last update Tue Oct  9 10:14:09 2012 thomas leclercq
*/

void	my_putchar(int c)
{
  write(1, &c, 1);
}
