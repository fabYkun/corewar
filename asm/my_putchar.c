/*
** my_putchar.c for my_putchar in /home/rustam_t/rendu/Piscine-C-Jour_03
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Mon Oct 21 09:33:19 2013 Timur Rustamov
** Last update Sun Apr 13 21:47:44 2014 Nicolas Pinatel
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
