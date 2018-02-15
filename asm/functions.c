/*
** functions.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/ASM
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Mon Mar 31 09:58:29 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:44:06 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"doth.h"
#include	"op.h"

char		*my_gnl(char *str, int *i)
{
  static char	*nextline = NULL;
  static int	count = 1;
  int		j;

  if (nextline == NULL)
    nextline = str;
  if (i != NULL)
    *i = count;
  j = 1;
  while (*nextline != '\n')
    {
      if (*nextline == '\0')
	return (NULL);
      nextline +=1;
      j += 1;
    }
  nextline += 1;
  count += 1;
  return (epur_str(nextline - j));
}

char		*my_strndup(char *src, int leng)
{
  int		i;
  char		*dest;

  i = -1;
  if (leng <= 0 || (dest = malloc(sizeof(char) * (leng + 1))) == NULL)
    return (NULL);
  while (++i < leng)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

int		my_transpalette(char *str)
{
  int		j;
  int		nb;

  j = 8;
  nb = 0;
  while (*str != '\0' && j-- >= 0)
    {
      if (*str - 48 == 1)
	nb += my_power_rec(2, j);
      str++;
    }
  return (nb);
}

char		*my_unquote(char *str, int flag)
{
  int		i;

  i = -1;
  while (str[++i] != '\"');
  if (i > ((flag == 0) ? (PROG_NAME_LENGTH) : (COMMENT_LENGTH)))
    return (NULL);
  return (my_strndup(str, i));
}

int		is_empty(char *ptr)
{
  while (*ptr != '\n' && *ptr != '\0')
    {
      if (*ptr != ' ' && *ptr != '\t')
	return (0);
      ptr += 1;
    }
  return (-1);
}
