/*
** get_next_line.c for GNL in /home/lecler_i//c/projets/get_next_line
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Sat Nov 24 12:39:02 2012 thomas leclercq
** Last update Fri Dec 14 19:26:10 2012 thomas leclercq
*/

#include "get_next_line.h"
#include <stdlib.h>

int	gnl_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*gnl_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  while (i < gnl_strlen(src))
    {
      if (nb > gnl_strlen(src))
        {
          dest[i] = 0;
        }
      i = i + 1;
    }
  return (dest);
}

char	*generate_line(char *line, int pos_br, char *buffer, int *start)
{
  char		*new_line;
  int		old_len;

  old_len = (line ? gnl_strlen(line) : 0);
  new_line = malloc((old_len + pos_br + 1));
  if (!new_line)
    {
      write(2, "Malloc Fail !\n", 15);
      return (NULL);
    }
  gnl_strncpy(new_line, (line ? line : ""), old_len);
  gnl_strncpy(new_line + old_len, buffer + *start, pos_br);
  new_line[old_len + pos_br] = 0;
  if (line)
    free(line);
  *start = *start + pos_br + 1;
  return (new_line);
}

char	*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static int	ret;
  static int	start;
  int		pos_br;
  char		*line;

  line = 0;
  pos_br = 0;
  while ("<3 les AER")
    {
      if (start >= ret)
        {
          start = 0;
	  pos_br = 0;
	  if (!(ret = read(fd, buffer, READ_SIZE)))
	    return (line);
	  if (ret == -1)
	    return (NULL);
	}
      if (buffer[start + pos_br] == '\n')
	return (generate_line(line, pos_br, buffer, &start));
      if (start + pos_br == ret)
	line = generate_line(line, pos_br + 1, buffer, &start);
      pos_br = pos_br + 1;
    }
}
