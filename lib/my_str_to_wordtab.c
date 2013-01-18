/*
** main.c for strtowordtab in /home/lecler_i//c/projets/fdf/str_to_wordtab
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Sat Dec  8 21:42:28 2012 thomas leclercq
** Last update Fri Dec 14 13:48:20 2012 thomas leclercq
*/

#include <stdlib.h>

int	my_cnt_words(char *str)
{
  int	i;
  int	nb_words;

  if (!str)
    return (0);
  i = 0;
  nb_words = 0;
  while (str[i] != '\0')
    {
      while (str[i] == ' ')
	i++;
      if (str[i] == '\0')
	return (nb_words);
      while (str[i] != ' ' && str[i] != '\0')
	i++;
      nb_words++;
    }
  return (nb_words);
}

int	my_countchar(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    i = i + 1;
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  int	nb_words;
  char	**tab;
  int	size;
  int	i;
  int	j;

  if (!(nb_words = my_cnt_words(str)))
    return (NULL);
  tab = malloc(sizeof(*tab) * (nb_words + 1));
  i = 0;
  j = 0;  
  while (str[i] != '\0')
    {
      while (str[i] == ' ')
	i++;
      if (str[i] == '\0')
	{
	  tab[j] = NULL;
	  return (tab);
	}
      size = my_countchar(&str[i]);
      tab[j] = malloc(sizeof(**tab) * (size + 1));
      tab[j][0] = '\0';
      my_strncat(tab[j], &str[i], size);
      i += size;
      j++;
    }
  tab[j] = NULL;
  return (tab);
}
