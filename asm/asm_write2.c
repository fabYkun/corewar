/*
** asm_write2.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:52:17 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:45:47 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

int		my_mod_index(char **tab, char *argtab)
{
  int		i;

  i = 0;
  while (tab[++i] != NULL)
    {
      if (argtab[i - 1] == T_DIR)
	{
	  argtab[i - 1] = T_IND;
	  tab[i] = &(tab[i][1]);
	}
      if (argtab[i - 1] == T_DLAB)
	{
	  argtab[i - 1] = T_ILAB;
	  tab[i] = &(tab[i][1]);
	}
    }
  return (i);
}

int		ind_write(int value, char *ptr)
{
  short int	ind;
  unsigned char	*pt;

  if (value > 32767 || value < -32767)
    return (VALUE_ERR);
  ind = value;
  pt = (unsigned char *)&ind;
  ptr[0] = pt[1];
  ptr[1] = pt[0];
  return (2);
}

int		reg_write(int value, char *ptr)
{
  char		reg;

  if (value > 16 || value < 0)
    return (REGIS_ERR);
  reg = value;
  *ptr = reg;
  return (1);
}

int		direct_write(int value, char *ptr)
{
  ptr[0] = (value >> 24) & 0xFF;
  ptr[1] = (value >> 16) & 0xFF;
  ptr[2] = (value >> 8) & 0xFF;
  ptr[3] = value & 0xFF;
  return (4);
}
