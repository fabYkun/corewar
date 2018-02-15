/*
** my_fatal.c for my_fatal in /home/rustam_t/rendu/corewar
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Wed Mar 19 08:58:17 2014 Timur Rustamov
** Last update Sun Apr 13 21:43:20 2014 Nicolas Pinatel
*/

#include	<stdlib.h>
#include	"doth.h"

void		my_fatal(char *str, char *str2)
{
  if (str2 != NULL)
    my_putstr(str2);
  my_putstr(str);
  exit(EXIT_FAILURE);
}
