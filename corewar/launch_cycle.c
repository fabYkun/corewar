/*
** launch_cycle.c for launch_cycle in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 19:10:30 2014 fabien borel
** Last update Sun Apr 13 21:06:26 2014 fabien borel
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	"prototypes.h"
#include	"error.h"
#include	"my.h"

unsigned char	param_len(unsigned char ocodage)
{
  char		len[4];
  char		decalage;
  unsigned char	result;
  unsigned char type;

  len[0] = 0;
  len[1] = 1;
  len[2] = 4;
  len[3] = 2;
  decalage = -1;
  result = 0;
  while (++decalage < 4)
    {
      type = arg_type(ocodage, decalage);
      if (type > 0 && type < 4)
	result += len[type];
    }
  return (result);
}

unsigned char	instruction_len(char *memory, int cursor, char type)
{
  if (type == 1 || type == 4 || type == 5)
    return (5);
  else if (type == 9 || type == 12 || type == 15 || type == 16)
    return (3);
  else if (type == 10 || type == 11)
    return (7);
  return (2 + param_len(memory[round_mem(cursor + 1)]));
}

int		find_pc(char *memory, t_current *current, char type)
{
  unsigned char	stock;
  int		i;

  i = instruction_len(memory, current->cursor, type) - 1;
  while (++i < MEM_SIZE)
    {
      stock = memory[round_mem(current->cursor + i)];
      if (stock > 0 && stock < 16)
	{
	  current->pc = round_mem(current->cursor + i);
	  return (0);
	}
    }
  return (NB_MEM_EMPTY);
}

/*
** Pas oublier de virer tous les processus d'un joueur/parent mort
** Je m'étais fait chier mais ça sert à rien :
** (error = find_pc(mother->memory, current, todo)) < 0
*/

int		do_instruction(t_motherbrain *mother, t_current *current,
			       unsigned char todo)
{
  int		error;
  unsigned int	cursor;
  int		len;

  cursor = current->cursor;
  len = instruction_len(mother->memory, cursor, todo);
  current->pc = current->cursor;
  if ((error = do_command(mother, current)) < 0)
    return (error);
  if (current->cursor == cursor)
    current->cursor = round_mem(cursor + len);
  return (0);
}

int		launch_cycle(t_motherbrain *mother, t_dcchain *prgms)
{
  t_current	*current;
  int		msg;

  ++mother->cycles;
  while (prgms != NULL)
    {
      current = (t_current *)prgms->ptr;
      if (--current->cycle <= 0)
	{
	  msg = (unsigned char)mother->memory[round_mem(current->cursor)];
	  if (msg > 0 && msg < 16)
	    {
	      if ((msg = do_instruction(mother, current, msg)) < 0)
		return (msg);
	    }
	  else
	    current->cursor = round_mem(current->cursor + 1);
	}
      prgms = prgms->next;
    }
  return (0);
}
