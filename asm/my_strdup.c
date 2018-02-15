/*
** my_strdup.c for my_strdup.c in /home/rustam_t/rendu/Piscine-C-Jour_08
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Wed Oct  9 10:40:40 2013 Timur Rustamov
** Last update Sun Apr 13 21:48:01 2014 Nicolas Pinatel
*/

#include	<stdlib.h>
#include	"doth.h"

char		*my_strdup(char *src)
{
  char		*dest;

  dest = malloc(sizeof(char) * my_strlen(src) + 1);
  my_strcpy(dest, src);
  return (dest);
}
