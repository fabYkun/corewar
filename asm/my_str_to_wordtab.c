/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/rustam_t/rendu/Minishell1
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Thu Dec 12 16:14:48 2013 Timur Rustamov
** Last update Sun Apr 13 23:19:03 2014 Nicolas Pinatel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"doth.h"

int		is_sep(char c, char *sep)
{
  int		i;
  i = -1;
  while (sep[++i] != '\0')
    if (c == sep[i])
      return (0);
  return (-1);
}

int		my_leng(char *str, char *sep)
{
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (is_sep(str[i], sep) == 0 && is_sep(str[i + 1], sep) == -1)
	nb++;
      i += 1;
    }
  return (nb);
}

char		**my_str_to_wordtab(char *str, char *sep)
{
  int		i;
  int		k;
  char		**tab;

  i = -1;
  k = 0;
  while (is_sep(str[++i], sep) == 0);
  if ((tab = malloc(sizeof(char *) * (my_leng(&str[i], sep) + 1))) == NULL)
    my_fatal("Memory allocation error!\n", "Critical internal error :");
  tab[k] = &str[i];
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (is_sep(str[i], sep) == 0)
	{
	  while (is_sep(str[i], sep) == 0)
	    str[i++] = '\0';
	  tab[++k] = &str[i];
	}
      i += 1;
    }
  str[i] = '\0';
  tab[++k] = NULL;
  return (tab);
}
