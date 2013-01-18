
int	is_printable(char car)
{
  if (car >= 32 && car <= 126)
    {
      return (1);
    }
  return (0);
}

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;;
  if (str[i] == 0)
    {
      return (1);
    }
  while (str[i] != 0)
    { 
      if (!is_low(str[i]))
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
