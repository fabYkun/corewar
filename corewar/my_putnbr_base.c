/*
** my_putnbr_base.c for my_putnbr_base in /home/rustam_t/rendu/Piscine-C-Jour_06
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Mon Oct  7 16:51:32 2013 Timur Rustamov
** Last update Sun Apr 13 15:53:21 2014 Timur Rustamov
*/

int		my_putnbr_base(long int nbr, char *base, char **str)
{
  long int	i;

  i = 0;
  if (nbr < 0)
    {
      nbr = nbr * - 1;
      my_putchar('-');
    }
  while (base[i] != '\0')
    i = i + 1;
  if (nbr >= i)
    {
      my_putnbr_base(nbr / i, base, str);
      my_putnbr_base(nbr % i, base, str);
    }
  else
    {
      **str = base[nbr];
      *str = *str + 1;
      **str = '\0';
    }
  **str = '\0';
  return (nbr);
}
