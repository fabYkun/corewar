/*
** my_putstr.c for my_putstr in /home/rustam_t/rendu/Piscine-C-Jour_04
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Thu Oct  3 10:51:49 2013 Timur Rustamov
** Last update Sun Apr 13 21:47:36 2014 Nicolas Pinatel
*/

#include	"doth.h"

int		my_putstr(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
  return (i);
}
