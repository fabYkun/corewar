/*
** my_getnbr.c for my_getnbr in /home/borel_d/rendu/PSU_2013_minishell1
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Mon Jan  6 21:56:59 2014 fabien borel
** Last update Tue Apr  8 14:13:50 2014 fabien borel
*/

int		my_getnbr(char *str)
{
  long int	nbr;
  char		neg;
  int		i;

  nbr = 0;
  neg = 0;
  i = -1;
  while (str[++i] == '+' || str[i] == '-')
    if (str[i] == '-')
      ++neg;
  while (str[i] > 47 && str[i] < 58)
    {
      nbr = nbr * 10 + (str[i++] - 48);
      if (nbr > 2147483647 && (neg % 2 == 0 || nbr > 2147483648))
	return (0);
    }
  if (neg % 2 == 1)
    return (nbr * -1);
  return (nbr);
}
