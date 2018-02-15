/*
** my_putstr.c for my_putstr in /home/rustam_t/rendu/Piscine-C-Jour_04
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Thu Oct  3 10:51:49 2013 Timur Rustamov
** Last update Thu Oct  3 16:27:47 2013 Timur Rustamov
*/

int	my_putstr(char *str)
{
  while (*str != '\0')
    {   
      my_putchar(*str);
      str = str + 1;
    }
}
