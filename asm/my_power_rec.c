/*
** my_power_it.c for my_power_it in /home/rustam_t/rendu/Piscine-C-Jour_05
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Fri Oct  4 16:51:56 2013 Timur Rustamov
** Last update Thu Apr 10 12:25:59 2014 Timur Rustamov
*/

int	my_power_rec(int nb, int power)
{
  if (power > 1)
    {
      nb = nb * my_power_rec(nb, power - 1);
      return (nb);
    }
  if (power == 0)
    return (1);
  return (-1);
}
