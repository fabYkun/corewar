/*
** ld.c for ld in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 20:01:54 2014 fabien borel
** Last update Sun Apr 13 22:04:55 2014 fabien borel
*/

#include	"../my.h"

int		vm_ld(t_motherbrain *mother, t_current *current)
{
  char		type;
  char		shift;
  int		adresse;

  current->cycle = 5;
  current->carry = 0;
  type = arg_type(mother->memory[round_mem(current->cursor + 1)], 1);
  shift = S_DIR;
  if (type == R_IND)
    {
      shift = S_IND;
      adresse = get_octets(mother->memory, current->cursor + 2, 2) %
	IDX_MOD + current->pc;
    }
  else if (type == R_DIR)
    adresse = current->cursor + 2;
  else
    return (0);
  to_registre(get_octets(mother->memory, adresse, 4),
	      mother->memory[round_mem(current->cursor + 2 + shift)], current);
  current->carry = 1;
  return (0);
}
