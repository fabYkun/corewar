/*
** my_put_nbr.c for my_put_nbr in /home/rustam_t/rendu/Piscine-C-Jour_03
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Wed Oct  2 17:15:33 2013 Timur Rustamov
** Last update Sun Apr 13 21:42:56 2014 Nicolas Pinatel
*/

#include	"doth.h"

int		my_put_nbr(long long int lon)
{
  if (lon < 0)
    {
      my_putchar('-');
      lon = lon * -1;
    }
  if (lon >= 10)
    {
      my_put_nbr(lon / 10);
      my_put_nbr(lon % 10);
    }
  else
    my_putchar(lon + 48);
  return (0);
}
