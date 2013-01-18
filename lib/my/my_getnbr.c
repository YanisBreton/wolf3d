/*
** my_getnbr.c for my_getnbr in /home/lecler_i//afs/Jour_04
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Oct  4 12:19:03 2012 thomas leclercq
** Last update Thu Dec  6 13:22:34 2012 thomas leclercq
*/

/* long    puissance(int e) */
/* { */
/*   long multiple; */

/*   multiple = 1; */
/*   while (e > 0) */
/*     { */
/*       multiple = multiple * 10; */
/*       e = e - 1; */
/*     } */
/*   return (multiple); */
/* } */

/* int	my_getnbr(char *str) */
/* { */
/*   int	num; */
/*   int	multi; */
/*   int	bool; */
/*   int	isneg; */
/*   int	mega_bool; */
  
/*   if (my_strlen(str) > 10) */
/*     return (0); */
/*   multi = puissance(my_strlen(str)); */
/*   num = 0; */
/*   isneg = 1; */
/*   mega_bool = 1; */
/*   while (*str != '\0' && mega_bool) */
/*     { */
/*       bool = 1; */
/*       if (*str - '0' < 0 || *str - '0'  > 9) */
/* 	{	   */
/* 	  if (*str == '-' && num == 0) */
/* 	    isneg = isneg * -1; */
/* 	  else if (*str == '+' && num == 0) */
/* 	    isneg = isneg * 1; */
/* 	  else */
/* 	    mega_bool = 0; */
/* 	  bool = 0; */
/* 	} */
/*       (bool) ? num = num + (*str - '0') * multi : 0; */
/*       multi = multi / 10; */
/*       str = str + 1; */
/*     } */
/*   num = num * isneg; */
/*   (!mega_bool) ? num = num / (multi * 100) : 0; */
/*   return (num / 10); */
/* } */


int		is_neg(char *str)
{
  int		i;
  int		counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        counter++;
      i++;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

int		is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int		i;
  int		nbr;

  nbr = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);  
}
