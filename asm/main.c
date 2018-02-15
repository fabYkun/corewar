/*
** main.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:54:56 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:43:48 2014 Nicolas Pinatel
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"doth.h"
#include		"op.h"

struct header_s		*my_headwrite(t_ass *prog)
{
  struct header_s	*header;
  char			*ptr;
  int			i;
  int			len;

  if ((header = malloc(sizeof(struct header_s))) == NULL)
    return (NULL);
  if (prog->pname == NULL || prog->pcom == NULL)
    my_fatal("Name/comment undecleared!\n", NULL);
  ptr = (char *)&header->magic;
  direct_write(COREWAR_EXEC_MAGIC, ptr);
  ptr = (char *)&header->prog_size;
  direct_write(prog->btnb, ptr);
  len = my_strlen(prog->pname);
  i = -1;
  while (++i < PROG_NAME_LENGTH + 1)
    header->prog_name[i] = (i < len) ? (prog->pname[i]) : (0);
  len = my_strlen(prog->pcom);
  i = -1;
  while (++i < COMMENT_LENGTH + 1)
    header->comment[i] = (i < len) ? (prog->pcom[i]) : (0);
  return (header);
}

void			my_writeinfile(t_ass *prog, int fd, char **av)
{
  struct header_s	*header;

  if ((header = my_headwrite(prog)) == NULL)
    my_fatal("Writing into .cor failed!", av[1]);
  if (write(fd, header, sizeof(struct header_s)) == -1 ||
      write(fd, prog->field, prog->btnb) == -1 ||
      close(fd) == -1)
    my_fatal("Something wrong happened!", NULL);
  my_putstr("Name : ");
  my_putstr(header->prog_name);
  my_putchar('\n');
  my_putstr("Comment : ");
  my_putstr(header->comment);
  my_putchar('\n');
  my_putstr("Done!\n");
  return;
}

int			main(int ac, char **av)
{
  int			fd;
  int			new_file;
  t_ass			*rec;

  if (ac > 2)
    my_fatal("Multiple files are not supported yet\n", NULL);
  else if (ac == 2)
    {
      if ((new_file = create_file(av[1])) == -1)
	my_fatal(": cannot create .cor\n", av[1]);
      if ((fd = open(av[1], O_RDONLY)) == -1)
	my_fatal(": cannot open file!\n", av[1]);
      if ((rec = parse_init(fd, av[1])) == NULL)
	return (-1);
      my_writeinfile(rec, new_file, av);
    }
  else
    my_putstr("./asm [filename.s]\n");
  return (0);
}
