/*
** washmachine.c for washmachine in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 19:05:47 2014 fabien borel
** Last update Sun Apr 13 23:01:23 2014 fabien borel
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	"prototypes.h"
#include	"error.h"
#include	"my.h"

int		initialize_prgm(t_dcchain *prgms, int cursor, char player)
{
  t_prgm	*old;
  t_current	*new;

  old = (t_prgm *) prgms->ptr;
  free(old->core);
  free(old);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (1);
  fill_prgm(new);
  new->cursor = cursor;
  new->player = player;
  new->registre[0] = player;
  prgms->ptr = new;
  return (0);
}

int		charge_memory(t_motherbrain *mother, char *memory,
			      int size_memory, unsigned char nb_prgms)
{
  t_prgm	*prgm;
  int		space_between_us;
  int		cursor;
  int		i;

  fill_memory(memory, size_memory);
  space_between_us = (size_memory - nb_prgms * MAX_SIZE) / 4;
  while (nb_prgms-- > 0 && mother->prgms != NULL)
    {
      prgm = (t_prgm *) mother->prgms->ptr;
      cursor = nb_prgms * MAX_SIZE - space_between_us / 2;
      cursor += (nb_prgms + 1) * space_between_us;
      cursor += MAX_SIZE / 2 - prgm->header.prog_size / 2;
      i = -1;
      while (++i < prgm->header.prog_size)
	memory[cursor + i] = prgm->core[i];
      if (initialize_prgm(mother->prgms, cursor, nb_prgms + 1) != 0)
	return (NB_MALLOC);
      if (mother->prgms->prev != NULL)
	mother->prgms = mother->prgms->prev;
    }
  return (0);
}

int		rm_from_list(t_dcchain **root, t_dcchain **to_rm)
{
  t_dcchain	*tmp;

  if ((tmp = (*to_rm)) == NULL)
    return (0);
  if (tmp->prev != NULL)
    tmp->prev->next = tmp->next;
  if (tmp->next != NULL)
    tmp->next->prev = tmp->prev;
  if (tmp->next == NULL && tmp->prev == NULL)
    {
      *to_rm = NULL;
      *root = NULL;
      return (-1);
    }
  if (tmp->prev != NULL)
    *to_rm = tmp->prev;
  else
    *to_rm = tmp->next;
  free(tmp);
  return (0);
}

void		my_memset(char *live)
{
  int		i;

  i = -1;
  while (++i < 4)
    live[i] = 0;
}

int		washmachine(t_motherbrain *mother)
{
  char		*memory;
  SDL_Event	event;
  int		i[2];
  int		error;

  if ((memory = malloc(sizeof(char) * MEM_SIZE)) == NULL ||
      (mother->field = malloc(sizeof(char) * MEM_SIZE)) == NULL ||
      charge_memory(mother, memory, MEM_SIZE, mother->nb_players) < 0)
    return (NB_MALLOC);
  mother->memory = memory;
  i[0] = 1;
  while (mother->prgms->prev != NULL)
    mother->prgms = mother->prgms->prev;
  while ((i[1] = is_alive(mother, &mother->prgms, &(i[0]))) == 0)
    {
      SDL_PollEvent(&event);
      if ((error = launch_cycle(mother, mother->prgms)) < 0)
	return (error);
      my_getimg(mother);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (0);
    }
  return (finish_it(mother, memory, i[1]));
}
