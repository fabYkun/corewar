/*
** fill_blanks.c for fill_blanks in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 13:47:52 2014 fabien borel
** Last update Sat Apr 12 13:51:59 2014 fabien borel
*/

#include	"my.h"

void		fill_prgm(t_current *prgm)
{
  int		i;

  i = -1;
  while (++i < REG_NUMBER)
    prgm->registre[i] = 0;
  prgm->cursor = 0;
  prgm->cycle = 0;
  prgm->player = 0;
  prgm->carry = 0;
  prgm->pc = 0;
}

void		fill_memory(char *memory, int size)
{
  int		i;

  i = -1;
  while (++i < size)
    memory[i] = 0;
}
