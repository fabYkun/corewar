/*
** end_condition.c for end_condition in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 23:00:01 2014 fabien borel
** Last update Sun Apr 13 23:00:54 2014 fabien borel
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	"prototypes.h"
#include	"error.h"
#include	"my.h"

int		my_evallive(char *live)
{
  int		i;
  int		nb;
  int		winner;

  i = -1;
  nb = 0;
  while (++i < 4)
    {
      if (live[i] != 0)
	{
	  nb += 1;
	  winner = i + 1;
	}
    }
  if (nb == 1)
    return (winner);
  return (0);
}

int		heart_beating(t_motherbrain *mother, t_dcchain **ptr,
			      char *live)
{
  t_current	*cur;
  int		res;

  if ((cur = (t_current *)(*ptr)->ptr)->live == 0)
    {
      if (rm_from_list(&(mother->prgms), ptr) == -1)
	return (5);
    }
  else
    {
      cur->live = 0;
      live[cur->player - 1] = 1;
    }
  return (0);
}

int		is_alive(t_motherbrain *mother, t_dcchain **ptr, int *i)
{
  t_dcchain	*tmp;
  char		live[4];
  int		result;

  if (mother->cycle_to_die > 0)
    mother->cycle_to_die -= 1;
  else
    {
      tmp = (*ptr);
      my_memset(&live[0]);
      while (tmp != NULL)
	{
	  (*ptr) = tmp;
	  if ((result = heart_beating(mother, ptr, &live[0])) != 0)
	    return (result);
	  tmp = tmp->next;
	}
      while ((*ptr)->prev != NULL)
	*ptr = (*ptr)->prev;
      mother->cycle_to_die = CYCLE_TO_DIE - CYCLE_DELTA * (*i += 1);
      return (my_evallive(live));
    }
  return (0);
}

int		my_winner(int winner, t_motherbrain *mother)
{
  if (winner == 5)
    {
      my_putstr("EQUALITY !\n");
      return (-1);
    }
  else
    {
      my_putstr("Winner is : ");
      my_putstr(mother->players[winner - 1]->name);
      my_putchar('\n');
    }
  return (0);
}

int		finish_it(t_motherbrain *mother, char *memory, int i)
{
  if (my_winner(i, mother) == -1)
    return (0);
  vanish_list(mother->prgms);
  free(mother->field);
  free(memory);
  free_players(mother->players);
  return (0);
}
