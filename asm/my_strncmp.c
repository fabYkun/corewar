/*
** my_strcmp.c for my_strcmp in /home/rustam_t/rendu/Piscine-C-Jour_06
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Mon Oct  7 11:34:21 2013 Timur Rustamov
** Last update Thu Apr 10 12:22:54 2014 Timur Rustamov
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	l;

  i = 0;
  while (n > 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
      l = l + 1;
      n = n - 1;
      if (s1[i] == '\0' || s2[i] == '\0')
	return (0);
    }
  return (0);
}

