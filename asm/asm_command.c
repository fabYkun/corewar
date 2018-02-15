/*
** asm_command.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:42:45 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:45:19 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

int		my_cmd(char **tab, t_ass *prog, int code)
{
  int		j;
  int		err;
  char		argtab[4];

  if ((err = my_argtype(tab, code, argtab)) < 0)
    return (err);
  j = 0;
  prog->field[prog->btnb + j++] = code;
  if (!(NO_ENCODE(code)))
    prog->field[prog->btnb + j++] = my_encode(argtab);
  if (APP_INDEX(code))
    my_mod_index(tab, argtab);
  return (my_writeall(tab, argtab, prog, j));
}

int		my_getcmd(char **tab, t_ass *prog)
{
  int		j;

  if (tab[0] == NULL)
    return (0);
  j = -1;
  while (++j < 16)
    {
      if (my_strcmp(tab[0], op_tab[j].mnemonique) == 0)
	{
	  if (arg_nb_check(tab, op_tab[j].nbr_args + 1) == 0)
	    return (my_cmd(tab, prog, op_tab[j].code));
	  else
	    return (ARGNB_ERR);
	}
    }
  return (SYNTA_ERR);
}

int		my_label_pl(t_ass *prog)
{
  t_lb		*temp;
  t_pl		*temp2;

  temp = prog->lb;
  while (temp != NULL)
    {
      if (temp->value == -1)
	{
	  write(2, temp->lbname, my_strlen(temp->lbname));
	  write(2, ": Label undecleared!\n", 21);
	  my_err(temp->line, LABEL_ERR);
	}
      temp2 = temp->empl;
      while (temp2 != NULL)
	{
	  if (temp2->type == T_DLAB)
	    direct_write(temp->value - temp2->offset, temp2->ptr);
	  else
	    ind_write(temp->value - temp2->offset, temp2->ptr);
	  temp2 = temp2->next;
	}
      temp = temp->next;
    }
  return (0);
}

t_ass		*parse_cmd(t_ass *prog)
{
  char		*ptr;
  int		i;
  int		res;
  char		**tab;

  i = 0;
  while ((ptr = my_gnl((i == 0) ? (prog->rd) : (NULL), &(prog->line))) != NULL)
    {
      i = 1;
      if (is_empty(ptr) == 0 && *ptr != COMMENT_CHAR)
	{
	  if ((res = my_get_pname(ptr, prog)) < 0)
	    my_err(prog->line, res);
	  tab = NULL;
	  if (res != 1)
	    {
	      if ((tab = my_str_to_wordtab(ptr, "	 ,")) == NULL)
		my_fatal("Something wrong happened!\n", NULL);
	      tab += my_get_lb(tab, prog);
	      if ((res = my_getcmd(tab, prog)) < 0)
		my_err(prog->line, res);
	      prog->btnb += res;
	    }
	}
    }
  return (prog);
}

t_ass		*parse_init(int fd, char *filename)
{
  t_ass		*prog;
  int		i;

  if ((prog = malloc(sizeof(t_ass))) == NULL ||
      (prog->rd = malloc(sizeof(char) * MEM_SIZE)) == NULL ||
      (prog->field = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    my_fatal("Memory allocation failed!\n", NULL);
  prog->btnb = 0;
  prog->lb = NULL;
  prog->pname = NULL;
  prog->pcom = NULL;
  if ((i = read(fd, prog->rd, MEM_SIZE)) == -1 || i >= MEM_SIZE)
    my_fatal((i < MEM_SIZE) ? (": read error!\n") :
	     (": file limit exceeded!\n"), filename);
  prog = parse_cmd(prog);
  if (prog->btnb == 0)
    my_fatal("Core program is missing!\n", NULL);
  if ((i = my_label_pl(prog)) < 0)
    my_err(prog->line, i);
  return (prog);
}
