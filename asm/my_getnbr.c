/*
** my_getnbr.c for my_getnbr in /home/rustam_t/rendu
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Sun Oct 13 00:39:20 2013 Timur Rustamov
** Last update Thu Dec  5 17:20:52 2013 Timur Rustamov
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	nb_minus;

  i = 0;
  nb = 0;
  nb_minus = 0;
  while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	nb_minus = nb_minus + 1;
      i++;
    }
  while ((str[i] != '\0' || str[i] != ' ') && (str[i] >= '0' && str[i] <= '9'))
    {
      nb = nb * 10;
      nb = nb + (str[i] - 48);
      i = i + 1;
    }
  if (nb_minus % 2 == 1)
    nb = nb * -1;
  return (nb);
}
