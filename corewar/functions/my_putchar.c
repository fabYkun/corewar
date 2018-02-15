/*
** my_putchar.c for my_putchar in /home/borel_d/Documents/Lab-JV/Aeroblast/functions
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Thu Mar 27 16:15:17 2014 fabien borel
** Last update Tue Apr  8 14:14:25 2014 fabien borel
*/

#include	<unistd.h>

char		my_putchar(char c)
{
  return (write(1, &c, 1));
}
