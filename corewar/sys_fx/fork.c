/*
** fork.c for fork in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 18:38:15 2014 fabien borel
** Last update Sun Apr 13 22:06:16 2014 fabien borel
*/

#include	<stdlib.h>
#include	"../error.h"
#include	"../my.h"

int		new_current(t_dcchain *list, t_current *current,
			    int curseur, int to_wait)
{
  int		i;
  t_current	*new;
  t_dcchain	*node;

  if ((new = malloc(sizeof(*new))) == NULL ||
      (node = malloc(sizeof(*node))) == NULL)
    return (NB_MALLOC);
  i = -1;
  while (++i < REG_NUMBER)
    new->registre[i] = current->registre[i];
  new->cursor = round_mem(curseur);
  new->cycle = to_wait;
  new->player = current->player;
  new->carry = current->carry;
  new->live = 0;
  new->pc = 0;
  node->ptr = new;
  node->prev = list;
  node->next = list->next;
  if (list->next != NULL)
    list->next->prev = node;
  list->next = node;
  return (0);
}

int		vm_fork(t_motherbrain *mother, t_current *current)
{
  int		value;

  current->cycle = 800;
  value = get_octets(mother->memory, current->cursor + 1, 4) % IDX_MOD +
    current->pc;
  return (new_current(mother->prgms, current, value, 800));
}

int		vm_lfork(t_motherbrain *mother, t_current *current)
{
  int		value;

  current->carry = 0;
  current->cycle = 1000;
  value = get_octets(mother->memory, current->cursor + 1, 4) +
    current->pc;
  if ((value = new_current(mother->prgms, current, value, 1000)) == 0)
    current->carry = 1;
  return (value);
}
