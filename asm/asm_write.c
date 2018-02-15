/*
** asm_write.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:47:53 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:44:25 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

int		my_is_num(char c)
{
  if ((c >= '0' && c <= '9') || c == '-')
    return (0);
  else
    return (-1);
}

int		arg_nb_check(char **tab, int i)
{
  int		j;

  j = 0;
  while (tab[j] != NULL)
    {
      if (my_strlen(tab[j]) > 0)
	j += 1;
    }
  if (j != i)
    return (-1);
  return (0);
}

int	        my_encode(char *argtab)
{
  int		i;
  char		str[9];

  str[0] = '\0';
  i = -1;
  while (++i < 4)
    {
      if (argtab[i] == T_REG)
	my_strcat(str, "01");
      else if (argtab[i] == T_DIR || argtab[i] == T_DLAB)
	my_strcat(str, "10");
      else if (argtab[i] == T_IND || argtab[i] == T_ILAB)
	my_strcat(str, "11");
      else
	my_strcat(str, "00");
    }
  return (my_transpalette(str));
}

int		my_get_argtype(char *tab)
{
  if (my_strlen(tab) > 2 && tab[0] == DIRECT_CHAR && tab[1] == LABEL_CHAR)
    return (T_DLAB);
  else if (my_strlen(tab) > 2 && tab[0] == LABEL_CHAR)
    return (T_ILAB);
  else if (tab[0] == DIRECT_CHAR && my_is_num(tab[1]) == 0)
    return (T_DIR);
  else if (my_is_num(tab[0]) == 0)
    return (T_IND);
  else if (tab[0] == 'r' && my_is_num(tab[1]) == 0)
    return (T_REG);
  else
    return (-1);
}

int		my_argtype(char **tab, char code, char *arg)
{
  int		i;

  i = 0;
  while (tab[++i] != NULL)
    {
      if ((arg[i - 1] = my_get_argtype(tab[i])) == -1)
	return (GARBA_ERR);
      if ((arg[i - 1] == T_DIR) && !(arg[i - 1] & op_tab[code - 1].type[i - 1]))
	arg[i - 1] = my_get_argtype(&tab[i][1]);
      if (!(arg[i - 1] == T_DLAB && T_DIR & op_tab[code - 1].type[i - 1]) &&
	  !(arg[i - 1] == T_ILAB && T_IND & op_tab[code - 1].type[i - 1]))
	  if (!(arg[i - 1] & op_tab[code - 1].type[i - 1]))
	    return (ARGTY_ERR);
    }
  while (i++ < 4)
    arg[i] = 0;
  return (0);
}
