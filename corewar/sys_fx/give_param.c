/*
** give_param.c for give_param in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 17:25:27 2014 fabien borel
** Last update Sun Apr 13 18:07:27 2014 fabien borel
*/

#include	"../my.h"

int		give_param(char *memory, int *cursor,
			   t_current *current, char type)
{
  int		value;

  value = 0;
  if (type == R_REG)
    {
      if (memory[*cursor] > 0 && memory[*cursor] < 17)
	value = current->registre[memory[*cursor] - 1];
      *cursor += S_REG;
    }
  else if (type == R_IND)
    {
      value = get_octets(memory, *cursor, 2) % IDX_MOD + current->pc;
      value = get_octets(memory, value, 4);
      *cursor += S_IND;
    }
  else if (type == R_DIR)
    {
      value = get_octets(memory, *cursor, 4);
      *cursor += S_DIR;
    }
  return (value);
}

/*
** pareil ici sauf que ce sont des index
*/

int		give_param_ind_size(char *memory, int *cursor,
				    t_current *current, char type)
{
  int		value;

  value = 0;
  if (type == R_REG)
    {
      if (memory[*cursor] > 0 && memory[*cursor] < 17)
	value = current->registre[memory[*cursor] - 1];
      *cursor += 2;
    }
  else if (type == R_IND)
    {
      value = get_octets(memory, *cursor, 2) % IDX_MOD + current->pc;
      value = get_octets(memory, value, 2);
      *cursor += 2;
    }
  else if (type == R_DIR)
    {
      value = get_octets(memory, *cursor, 2);
      *cursor += 2;
    }
  return (value);
}
