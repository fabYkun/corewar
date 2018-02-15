/*
** header.c for COREWAR+ in /home/garibo_j/rendu/corewar
**
** Made by garibo_j
** Login   <garibo_j@epitech.net>
**
** Started on  Mon Mar 31 09:54:32 2014 garibo_j
** Last update Sat Apr 12 10:46:45 2014 fabien borel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"op.h"
#include	"error.h"
#include	"prototypes.h"

int		get_header(t_header *header, int fd)
{
  if (read(fd, header, sizeof(*header)) == -1)
    return (NB_READ);
  if ((header->magic = reverse_int(header->magic)) != COREWAR_EXEC_MAGIC)
    return (NB_MAGIC);
  if ((header->prog_size = reverse_int(header->prog_size)) > MAX_SIZE)
    return (NB_SIZE);
  return (0);
}

/*
** decode_args
** (code == 1)	: REGISTRE
** (code == 2)	: DIRECT
** else		: INDIRECT
*/

int		decode_args(char code)
{
  int		i;
  int		size;
  int		type;

  size = 0;
  i = -1;
  while (++i < 4)
    if ((type = code >> (i * 2)) == 1)
      ++size;
    else if (type == 2)
      size += DIR_SIZE;
    else
      size += (type == 0) ? (0) : (IND_SIZE);
  return (size);
}

void		read_mem(char *mem, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      my_putmem(mem[i]);
      if (++i % 16 == 0 && i)
	my_putchar('\n');
    }
}
