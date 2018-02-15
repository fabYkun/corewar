/*
** live.c for live in /home/borel_d/rendu/CPE_2014_corewar/vm/sys_fx
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 17:06:43 2014 fabien borel
** Last update Sun Apr 13 22:10:58 2014 fabien borel
*/

#include	"../my.h"
#include	"../prototypes.h"

int		vm_live(t_motherbrain *mother, t_current *current)
{
  int		heart;

  current->cycle = 10;
  heart = get_octets(mother->memory, current->cursor + 1, 4);
  if (heart > 0 && heart <= mother->nb_players)
    {
      my_putstr("Player ");
      my_put_nbr(current->player);
      my_putstr(" (");
      if (current->player > 0 && current->player < 5)
	my_putstr(mother->players[current->player - 1]->name);
      my_putstr(") has given sign of life !\n");
      mother->players[heart - 1]->last_live = mother->cycles;
      current->live = 1;
      --mother->cycle_to_die;
    }
  return (0);
}
