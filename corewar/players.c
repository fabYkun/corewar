/*
** free_players.c for players in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 15:36:02 2014 fabien borel
** Last update Sat Apr 12 16:59:00 2014 fabien borel
*/

#include	"my.h"
#include	"prototypes.h"
#include	<stdlib.h>

t_player	*new_player(char *name)
{
  t_player	*player;

  if ((player = malloc(sizeof(*player))) == NULL)
    return (NULL);
  if ((player->name = my_strdup(name)) == NULL)
    return (NULL);
  player->nb_process = 1;
  player->last_live = 0;
  return (player);
}

void		free_players(t_player **players)
{
  int		i;

  i = -1;
  while (players[++i] != NULL)
    {
      free(players[i]->name);
      free(players[i]);
    }
  free(players);
}
