/*
** prototypes.h for prototypes in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Tue Apr  8 14:57:13 2014 fabien borel
** Last update Sun Apr 13 16:02:34 2014 Timur Rustamov
*/

#ifndef PROTO_H_
# define PROTO_H_

char		my_putmem(char c);
char		my_putchar(char c);
char		my_putstr(char *str);
char		my_puterror(char *str);
void		my_put_nbr(int nb);
char		*my_strdup(char *str);
char		**str_to_wt_nm(char *str);
int		my_getnbr(char *str);
int		reverse_int(int value);
void		read_mem(char *mem, int size);
int		my_putnbr_base(long int, char *, char **);
void		my_fatal(char *, char *);

#endif /* !PROTO_H_ */
