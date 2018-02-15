/*
** my_put_nbr.c for my_put_nbr in /home/borel_d/rendu/PSU_2013_minishell1
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Fri Dec 13 16:53:32 2013 fabien borel
** Last update Tue Apr  8 14:16:08 2014 fabien borel
*/

#include	<unistd.h>

void		my_put_nbr(int nb)
{
  int		inv;
  int		der;

  der = 0;
  inv = 0;
  if (nb < 0)
    {
      write(1, "-", 1);
      nb = nb * -1;
    }
  if (nb == 0)
    write(1, "0", 1);
  while (nb > 0)
    {
      inv = (inv * 10) + nb % 10;
      nb = nb / 10;
      der = der + 1;
    }
  while (der > 0)
    {
      der = der - 1;
      nb = inv % 10 + '0';
      write(1, &nb, 1);
      inv = inv / 10;
    }
}
