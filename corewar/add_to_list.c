/*
** add_to_list.c for add_to_list in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Wed Apr  9 11:20:18 2014 fabien borel
** Last update Sat Apr 12 14:17:28 2014 fabien borel
*/

#include	<stdlib.h>
#include	"my.h"

char		add_to_list(t_dcchain **chain, void *ptr)
{
  t_dcchain	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  elem->ptr = ptr;
  elem->prev = *chain;
  elem->next = NULL;
  if (*chain != NULL)
    (*chain)->next = elem;
  *chain = elem;
  return (0);
}

void		vanish_list(t_dcchain *list)
{
  if (list == NULL)
    return ;
  while (list->prev != NULL)
    list = list->prev;
  while (list->next != NULL)
    {
      list = list->next;
      if (list->prev->ptr != NULL)
	free(list->prev->ptr);
      free(list->prev);
    }
  free(list);
}
