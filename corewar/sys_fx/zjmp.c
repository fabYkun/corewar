/*
** zjmp.c for zjmp in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 17:28:39 2014 fabien borel
** Last update Sun Apr 13 17:33:46 2014 fabien borel
*/

#include	"../my.h"

int		vm_zjmp(t_motherbrain *mother, t_current *current)
{
  int		idx;

  current->cycle = 20;
  if (current->carry == 1)
    {
      idx = get_octets(mother->memory, current->cursor + 1, 2) % IDX_MOD +
        current->pc;
      current->cursor = round_mem(idx);
    }
  return (0);
}
