/*
** my_strcmp.c for my_strcmp in /home/rustam_t/rendu/Piscine-C-Jour_06
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Mon Oct  7 11:34:21 2013 Timur Rustamov
** Last update Wed Nov  6 16:13:16 2013 Timur Rustamov
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}
