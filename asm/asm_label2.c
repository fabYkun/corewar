/*
** asm_label2.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:41:04 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:45:27 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

int		my_lookup(char l, char *j)
{
  int		i;

  i = -1;
  while (j[++i] != '\0')
    if (j[i] == l)
      return (0);
  return (-1);
}

int		my_valid_label(char *label, int len)
{
  int		i;

  i = -1;
  while (++i < len)
    if (my_lookup(label[i], LABEL_CHARS) == -1)
      return (-1);
  return (0);
}

int		my_get_lb(char **tab, t_ass *prog)
{
  int		i;
  t_lb		*elem;
  char		*lbdup;

  i = my_strlen(tab[0]);
  if (tab[0][i - 2] != DIRECT_CHAR && tab[0][i - 1] == LABEL_CHAR)
    {
      if (my_valid_label(tab[0], i - 1) == -1)
	my_err(prog->line, LABEL_CHA);
      if ((elem = my_searchlb(prog->lb, (lbdup = my_strndup(tab[0], i - 1))))
	  == NULL)
	put_new_lb_in_list(&(prog->lb), prog, lbdup, prog->btnb);
      else
	{
	  if (elem->value != -1)
	    my_err(prog->line, MULAB_ERR);
	  else
	    elem->value = prog->btnb;
	}
      return (1);
    }
  return (0);
}
