/*
** lldi.c for lldi in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 18:37:13 2014 fabien borel
** Last update Sun Apr 13 18:38:00 2014 fabien borel
*/

#include	"../my.h"

int		vm_lldi(t_motherbrain *mother, t_current *current)
{
  int		cursor;
  int		val1;
  int		val2;
  char		shift1;
  char		shift2;

  current->carry = 0;
  current->cycle = 25;
  cursor = round_mem(current->cursor + 1);
  shift1 = arg_type(mother->memory[cursor], 1);
  shift2 = arg_type(mother->memory[cursor++], 2);
  val1 = give_param_ind_size(mother->memory, &cursor, current, shift1);
  val2 = give_param_ind_size(mother->memory, &cursor, current, shift2);
  val1 = get_octets(mother->memory, (val1 + val2) + current->pc, 4);
  if (mother->memory[cursor] > 0 && mother->memory[cursor] < 17)
    {
      current->registre[mother->memory[cursor] - 1] = val1;
      current->carry = 1;
    }
  return (0);
}
