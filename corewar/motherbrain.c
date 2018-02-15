/*
** motherbrain.c for motherbrain in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Wed Apr  9 11:03:06 2014 fabien borel
** Last update Sun Apr 13 16:18:02 2014 Timur Rustamov
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"prototypes.h"
#include	"error.h"
#include	"my.h"

char		initialize_motherbrain(t_motherbrain *motherbrain,
				       unsigned char nb_players)
{
  motherbrain->cycles = 0;
  motherbrain->cycle_to_die = CYCLE_TO_DIE;
  motherbrain->prgms = NULL;
  if ((motherbrain->players = malloc(sizeof(t_player *) *
				     (4 + 1))) == NULL)
    return (NB_MALLOC);
  motherbrain->players[2] = NULL;
  motherbrain->players[3] = NULL;
  motherbrain->players[nb_players] = NULL;
  motherbrain->nb_players = nb_players;
  return (0);
}

int		charge_prgm(t_motherbrain *mother, char *pathname,
			    unsigned char nb_player)
{
  t_prgm	*prgm;
  int		descriptor;
  char		error;

  if ((prgm = malloc(sizeof(*prgm))) == NULL)
    return (NB_MALLOC);
  if ((descriptor = open(pathname, O_RDONLY)) < 0)
    return (NB_OPEN);
  if ((error = get_header(&prgm->header, descriptor)) < 0)
    return (error);
  if ((prgm->core = malloc(sizeof(char) * prgm->header.prog_size)) == NULL
      || (mother->players[nb_player] = new_player(prgm->header.name)) == NULL)
    return (NB_MALLOC);
  if (read(descriptor, prgm->core, prgm->header.prog_size) == -1)
    return (NB_READ);
  if (add_to_list(&mother->prgms, prgm) < 0)
    return (NB_MALLOC);
  return (0);
}

int		main(int argc, char **argv)
{
  t_motherbrain	mother;
  int		error;
  int		i;

  if (argc < 3)
    return (error_gestion(NB_PROTO));
  else if (argc > NB_MAXPRGM + 1)
    return (error_gestion(NB_ERR_MAXPRGM));
  i = 0;
  if ((error = initialize_motherbrain(&mother, argc - 1)) < 0)
    return (error_gestion(error));
  while (++i < argc)
    if ((error = charge_prgm(&mother, argv[i], i - 1)) < 0)
      return (error_gestion(error));
  return (error_gestion(washmachine(&mother)));
}
