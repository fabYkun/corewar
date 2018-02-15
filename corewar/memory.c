/*
** memory.c for memory in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sat Apr 12 19:08:14 2014 fabien borel
** Last update Sun Apr 13 15:06:34 2014 Timur Rustamov
*/

#include	"my.h"

unsigned int	round_mem(int cursor)
{
  while (cursor >= MEM_SIZE)
    cursor = (MEM_SIZE - cursor) * -1;
  while (cursor < 0)
    cursor = (MEM_SIZE + cursor);
  return (cursor);
}

void		to_registre(int value, unsigned char registre,
			    t_current *current)
{
  if (registre < 16)
    current->registre[registre] = value;
}

/*
** Nous dit si l'argument nb est de type
** registre (1), direct (2) ou indirect (3)
*/

char		arg_type(unsigned char octet, char posi)
{
  unsigned char	result;

  result = octet >> (8 - posi * 2);
  return (result & (unsigned char) 3);
}

int		get_octets(char *memory, int cursor, char howmany)
{
  int		result;
  char		go_on;

  result = 0;
  go_on = -1;
  if (howmany == 2 && (unsigned char) memory[round_mem(cursor)] >> 7 == 1)
    result = 0x00FFFF00;
  while (--howmany > 0 && howmany < 4)
    {
      result += (unsigned char) memory[round_mem(cursor + ++go_on)];
      result = result << 8;
    }
  result += (unsigned char) memory[round_mem(cursor + ++go_on)];
  return (result);
}

void		set_octets(char *memory, int cursor, int what, char howmany)
{
  if (howmany == 4)
    {
      memory[round_mem(cursor + 3)] = (char) (what & 0x000000FF);
      memory[round_mem(cursor + 2)] = (char) ((what & 0x0000FF00) >> 8) ;
      memory[round_mem(cursor + 1)] = (char) ((what & 0x00FF0000) >> 16);
      memory[round_mem(cursor)] = (char) ((what & 0xFF000000) >> 24);
    }
  else if (howmany == 2)
    {
      memory[round_mem(cursor + 1)] = (char) (what & 0x000000FF);
      memory[round_mem(cursor)] = (char) ((what & 0x0000FF00) >> 8);
    }
}
