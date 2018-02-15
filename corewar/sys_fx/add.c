/*
** add.c for add in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 14:07:46 2014 fabien borel
** Last update Sun Apr 13 19:20:04 2014 fabien borel
*/

#include	"../my.h"

int		vm_add(t_motherbrain *mother, t_current *current)
{
  int		reg1;
  int		reg2;
  int		reg3;

  current->cycle = 10;
  current->carry = 0;
  if ((reg1 = mother->memory[round_mem(current->cursor + 2)]) < 1 || reg1 > 16)
    return (0);
  if ((reg2 = mother->memory[round_mem(current->cursor + 3)]) < 1 || reg2 > 16)
    return (0);
  if ((reg3 = mother->memory[round_mem(current->cursor + 4)]) < 1 || reg3 > 16)
    return (0);
  current->registre[reg3 - 1] = current->registre[reg1 - 1] +
    current->registre[reg2 - 1];
  current->carry = 1;
  return (0);
}
