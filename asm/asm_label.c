/*
** asm_label.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:18:15 2014 Nicolas Pinatel
** Last update Sun Apr 13 22:28:35 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

t_lb		*my_searchlb(t_lb *list, char *name)
{
  t_lb		*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->lbname, name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void		put_new_lb_in_list(t_lb **list, t_ass *prog, char *name,
				   int value)
{
  t_lb		*elem;

  if ((elem = malloc(sizeof(t_lb))) == NULL)
    my_fatal("Memory allocation error !\n", NULL);
  elem->lbname = name;
  elem->line = prog->line;
  elem->value = value;
  elem->empl = NULL;
  elem->next = *list;
  *list = elem;
}

int		my_put_lb_pl(t_pl **list, char *ptr, char argtab, t_ass *prog)
{
  t_pl		*elem;

  if ((elem = malloc(sizeof(t_pl))) == NULL)
    my_fatal("Memory allocation error !\n", NULL);
  elem->ptr = ptr;
  elem->type = argtab;
  elem->line = prog->line;
  elem->offset = prog->btnb;
  elem->next = *list;
  *list = elem;
  return (0);
}

int		label_write(char *tab, char argtab, char *ptr, t_ass *prog)
{
  int		res;
  t_lb		*elem;

  if (argtab == T_ILAB)
    tab += 1;
  res = (argtab == T_DLAB) ? (DIR_SIZE) : (IND_SIZE);
  if ((my_searchlb(prog->lb, tab)) == NULL)
    put_new_lb_in_list(&(prog->lb), prog, (char *)my_strdup(tab), -1);
  if ((elem = my_searchlb(prog->lb, tab)) == NULL ||
      my_put_lb_pl(&(elem->empl), ptr, argtab, prog) != 0)
    my_fatal("Something wrong happened !\n", NULL);
  return (res);
}

int		my_writeall(char **tab, char *argtab, t_ass *prog, int j)
{
  int		i;
  int		k;

  i = 0;
  k = 0;
  while (tab[++i] != NULL)
    {
      if (argtab[i - 1] == T_DIR)
	k = direct_write(my_getnbr(&(tab[i][1])),
			 &prog->field[prog->btnb + j]);
      else if (argtab[i - 1] == T_REG)
	k = reg_write(my_getnbr(&(tab[i][1])), &prog->field[prog->btnb + j]);
      else if (argtab[i - 1] == T_IND)
	k = ind_write(my_getnbr(tab[i]), &prog->field[prog->btnb + j]);
      else if (argtab[i - 1] == T_DLAB || argtab[i - 1] == T_ILAB)
	k = label_write(tab[i], argtab[i - 1], &prog->field[prog->btnb + j], prog);
      if (k <= 0)
	return (k);
      j += k;
    }
  return (j);
}
