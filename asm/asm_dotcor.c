/*
** asm_dotcor.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Wed Apr  2 14:54:43 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:44:58 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

char		*hook_name_cor(char *name)
{
  int		len;
  int		i;
  int		j;
  char		*ptr;

  i = my_strlen(name) - 1;
  while (i != 0 && name[i - 1] != '/')
    i--;
  len = 0;
  while (name[i + len] != '.' && name[i + len] != '\0')
    len++;
  if ((ptr = malloc(sizeof(char) * (len + 5))) == NULL)
    return (NULL);
  j = 0;
  while (j < len)
    ptr[j++] = name[i++];
  ptr[j] = '\0';
  my_strcat(ptr, ".cor");
  return (ptr);
}

int		create_file(char *name)
{
  char		*name_cor;
  int		fd;

  if ((name_cor = hook_name_cor(name)) == NULL)
    my_fatal("Error on hook_name_cor", NULL);
  if ((fd = open(name_cor, O_CREAT | O_WRONLY | O_TRUNC, 0664)) == -1)
    my_fatal("Cannot create/open file!", NULL);
  free(name_cor);
  return (fd);
}
