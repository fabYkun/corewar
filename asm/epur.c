/*
** epur.c for corewar in /home/zaboon/rendu/CPE_2014_corewar/asm
** 
** Made by Nicolas Pinatel
** Login   <zaboon@epitech.net>
** 
** Started on  Sun Apr 13 21:38:40 2014 Nicolas Pinatel
** Last update Sun Apr 13 21:39:33 2014 Nicolas Pinatel
*/

#include	"doth.h"

char            *epur_str(char *str)
{
  int           i;
  int           j;

  j = 0;
  while (str[++j] != '\0' && str[j] != '\n');
  if (j == 0)
    return (str);
  i = 1;
  while (str[j - i] == ' ' || str[j - i] == '\t')
    str[j - i++] = str[j];
  return (str);
}
