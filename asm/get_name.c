/*
** get_name.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 10:11:27 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:47:17 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

int		my_get_pname(char *ptr, t_ass *prog)
{
  int		flag;
  char		*lt;

  if (my_strncmp(ptr, NAME_CMD_STRING,
		 my_strlen(NAME_CMD_STRING)) == 0)
    flag = 0;
  else if (my_strncmp(ptr, COMMENT_CMD_STRING,
		      my_strlen(COMMENT_CMD_STRING)) == 0)
    flag = 1;
  else
    return (0);
  ptr += my_strlen((flag == 0) ?  (lt = NAME_CMD_STRING) :
		   (lt = COMMENT_CMD_STRING)) + 1;
  while (*ptr == ' ' || *ptr == '\t')
    ptr += 1;
  if (((flag == 0) ? (prog->pname) : (prog->pcom)) != NULL)
    return (MULTI_NAM);
  if (flag == 0)
    prog->pname = my_unquote(ptr + 1, flag);
  else
    prog->pcom = my_unquote(ptr + 1, flag);
  return (1);
}
