/*
** my_strdup.c for my_strdup in /home/borel_d/rendu/PSU_2013_minishell2
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Mon Mar  3 17:38:14 2014 fabien borel
** Last update Mon Mar  3 18:38:42 2014 fabien borel
*/

#include	<stdlib.h>

char		*my_strdup(char *src)
{
  char		*new;
  int		i;

  i = -1;
  while (src[++i] != 0);
  if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while (src[++i] != 0)
    new[i] = src[i];
  new[i] = 0;
  return (new);
}
