/*
** error_handler.c for error_handler in /home/borel_d/Documents/Lab-JV/Aeroblast
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Thu Mar 27 11:26:50 2014 fabien borel
** Last update Sun Apr 13 11:27:08 2014 fabien borel
*/

#include	"error.h"
#include	"prototypes.h"

int		find_err_index(int value)
{
  char		op[8];
  int		i;

  i = -1;
  op[0] = NB_MALLOC;
  op[1] = NB_READ;
  op[2] = NB_OPEN;
  op[3] = NB_PROTO;
  op[4] = NB_MAGIC;
  op[5] = NB_SIZE;
  op[6] = NB_ERR_MAXPRGM;
  op[7] = NB_MEM_EMPTY;
  while (++i < 8)
    if (op[i] == value)
      return (i);
  return (-42);
}

char		error_gestion(int error)
{
  char		*errors[8];
  int		err_nb;

  err_nb = -42;
  errors[0] = ERR_MALLOC;
  errors[1] = ERR_READ;
  errors[2] = ERR_OPEN;
  errors[3] = ERR_PROTO;
  errors[4] = ERR_MAGIC;
  errors[5] = ERR_SIZE;
  errors[6] = ERR_MAXPRGM;
  errors[7] = ERR_MEM_EMPTY;
  if ((err_nb = find_err_index(error)) != -42)
    {
      my_puterror(NAME);
      my_puterror(": ");
      my_puterror(errors[err_nb]);
      my_putchar('\n');
      return (1);
    }
  return (0);
}
