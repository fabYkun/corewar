/*
** my_strcpy.c for my_strncpy in /home/rustam_t/rendu/Piscine-C-Jour_06
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Tue Oct  8 17:50:23 2013 Timur Rustamov
** Last update Fri Apr 11 10:34:53 2014 Timur Rustamov
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      dest[i + 1] = '\0';
      i = i + 1;
    }
  return (dest);
}
