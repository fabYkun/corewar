/*
** my_strcat.c for my_strcat in /home/Zaboon/rendu/Piscine-C-Jour_07
** 
** Made by Pinatel
** Login   <Zaboon@epitech.net>
** 
** Started on  Tue Oct  8 09:53:57 2013 Pinatel
** Last update Sun Apr 13 21:42:46 2014 Nicolas Pinatel
*/

#include	"doth.h"

char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
