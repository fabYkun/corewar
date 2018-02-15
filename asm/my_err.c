/*
** my_err.c for corewar in /home/rustam_t/rendu/corewar
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Mon Mar 31 09:49:20 2014 Timur Rustamov
** Last update Sun Apr 13 21:47:21 2014 Nicolas Pinatel
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "doth.h"
#include "err.h"

static const char *g_err_tab[] = {
  "Syntax error!\n",
  "Value error!\n",
  "Garbage found!\n",
  "Label not found!\n",
  "Argument number error!\n",
  "Argument type error!\n",
  "Register number error!\n",
  "Label multiple definition!\n",
  "Name/comment multiple definition!\n",
  "Invalid label characters found!\n"
};

void		my_err(int line, int errnum)
{
  write(2, "Critical error line ", 20);
  my_put_nbr(line);
  write(2, ":\n", 2);
  write(2, g_err_tab[errnum * -1 - 1],
	my_strlen((char *)g_err_tab[errnum * -1 -1]));
  write(2, "Terminating!\n", 13);
  exit (-1);
}
