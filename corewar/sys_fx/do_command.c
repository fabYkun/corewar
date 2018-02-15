/*
** do_command.c for do_command in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 18:47:38 2014 fabien borel
** Last update Sun Apr 13 22:46:36 2014 fabien borel
*/

#include	"../my.h"

int		do_command(t_motherbrain *mother, t_current *current)
{
  int		(*command[16])(t_motherbrain *, t_current *);
  unsigned char	index;

  if ((index = mother->memory[current->cursor] - 1) > 15)
    return (0);
  command[0] = &vm_live;
  command[1] = &vm_ld;
  command[2] = &vm_st;
  command[3] = &vm_add;
  command[4] = &vm_sub;
  command[5] = &vm_and;
  command[6] = &vm_or;
  command[7] = &vm_xor;
  command[8] = &vm_zjmp;
  command[9] = &vm_ldi;
  command[10] = &vm_sti;
  command[11] = &vm_fork;
  command[12] = &vm_lld;
  command[13] = &vm_lldi;
  command[14] = &vm_lfork;
  command[15] = &vm_aff;
  return (command[index](mother, current));
}
