/*
** my_fatal.c for my_fatal in /home/rustam_t/rendu/corewar
**
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
**
** Started on  Wed Mar 19 08:58:17 2014 Timur Rustamov
** Last update Sun Apr 13 23:05:26 2014 fabien borel
*/

#include	<stdlib.h>
#include	"doth.h"

/*
*** a simple exit function
*** str2 is displayed before str if exists
*** using exemple : str = " : cannot create file", str2 = "file.cor\n"
*/

void		my_fatal(char *str, char *str2)
{
  if (str2 != NULL)
    my_putstr(str2);
  my_putstr(str);
  exit(EXIT_FAILURE);
}
