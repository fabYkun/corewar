/*
** my_strlen.c for my_strlen in /home/rustam_t/rendu/Piscine-C-Jour_04
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Thu Oct  3 11:29:29 2013 Timur Rustamov
** Last update Sun Apr 13 17:52:22 2014 Timur Rustamov
*/

int	my_strlen(char *str)
{
  int	i;

  i = 1;
  while (*str != '\0')
    {
      i = i + 1;
      str = str + 1;
    }
  i = i - 1;
  return (i);
}
