/*
** aff.c for COREWAR in /home/garibo_j/rendu/corewar/vm/borel/vm
**
** Made by garibo_j
** Login   <garibo_j@epitech.net>
**
** Started on  Sun Apr 13 15:20:26 2014 garibo_j
** Last update Sun Apr 13 22:08:10 2014 fabien borel
*/

#include	"../my.h"

int		vm_aff(t_motherbrain *mother, t_current *current)
{
  unsigned char	reg;

  current->cycle = 2;
  reg = mother->memory[round_mem(current->cursor + 2)];
  if (reg > 0 && reg < 17)
    my_putchar(current->registre[(reg - 1)] % 256);
  return (0);
}
