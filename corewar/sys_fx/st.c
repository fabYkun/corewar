/*
** st.c for st in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 13:21:45 2014 fabien borel
** Last update Sun Apr 13 20:21:29 2014 fabien borel
*/

#include	"../my.h"

int		vm_st(t_motherbrain *mother, t_current *current)
{
  int		reg;
  int		value;
  char		type;

  current->cycle = 8;
  if ((reg = mother->memory[round_mem(current->cursor + 2)]) < 1 || reg > 16)
    return (0);
  type = arg_type(mother->memory[round_mem(current->cursor + 1)], 2);
  if (type == R_REG)
    {
      value = mother->memory[round_mem(current->cursor + 3)];
      if (value < 1 || value > REG_NUMBER)
	return (0);
      current->registre[value - 1] = current->registre[reg - 1];
    }
  else if (type == R_IND)
    {
      value = get_octets(mother->memory, current->cursor + 3, 2);
      set_octets(mother->memory, value % IDX_MOD
		 + current->pc, current->registre[reg - 1], 4);
    }
  return (0);
}
