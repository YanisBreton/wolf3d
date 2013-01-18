/*
** x_functions.c for x_functions in /home/lecler_i//c/projets/wolf3d
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Fri Dec 14 23:13:46 2012 thomas leclercq
** Last update Sun Dec 16 19:45:44 2012 root
*/

#include <stdio.h>
#include <stdlib.h>

void	*xmalloc(int size)
{
  void		*ret_ptr;

  ret_ptr = malloc(size);
  if (!ret_ptr)
    {
      write(2, "Error : malloc() failed to allocate memory\n", 43);
      exit(EXIT_FAILURE);
    }
  return (ret_ptr);
}

int	xopen(const char *pathname, int flags)
{
  int		fd;

  fd = open(pathname, flags);
  if (fd == -1)
    {
      write(2, "Error : open() Failed to open file.\n", 37);
    }
}
/* void	*xrealloc(void *ptr, int size) */
/* { */
/*   void		*ret_ptr; */
  
/*   if (!ptr) */
/*     return (xmalloc(size)); */
/*   if (!size) */
/*     return (ptr); */
/* } */

