/*
** reverse_int.c for reverse_int in /home/borel_d/rendu/CPE_2014_corewar/vm/functions
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Tue Apr  8 14:29:31 2014 fabien borel
** Last update Tue Apr  8 14:40:51 2014 fabien borel
*/

int		reverse_int(int value)
{
  return ((value & 0x000000FF) << 24 |
	  (value & 0x0000FF00) << 8 |
	  (value & 0x00FF0000) >> 8 |
	  (value & 0xFF000000) >> 24);
}
