/*
** my_putmem.c for my_putmem in /home/borel_d/rendu/CPE_2014_corewar/JOSECACA/functions
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Tue Apr  8 14:06:02 2014 fabien borel
** Last update Tue Apr  8 14:09:31 2014 fabien borel
*/

#include	<unistd.h>

char		my_putmem(char c)
{
  if (c > 33)
    return (write(1, &c, 1));
  return (write(1, ".", 1));
}
