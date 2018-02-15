/*
** doth.h for doth.h in /home/rustam_t/rendu/corewar
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Wed Mar 19 09:04:27 2014 Timur Rustamov
** Last update Sun Apr 13 23:24:20 2014 Nicolas Pinatel
*/

#ifndef DOTH_H
#define DOTH_H

# define EOL(x) (x == '\n' || x == '\0') ? (0) : (-1)
# define SPACE(x) (x == '\t' || x == ' ') ? (0) : (-1)

// error types
# define SYNTA_ERR (-1)
# define VALUE_ERR (-2)
# define GARBA_ERR (-3)
# define LABEL_ERR (-4)
# define ARGNB_ERR (-5)
# define ARGTY_ERR (-6)
# define REGIS_ERR (-7)
# define MULAB_ERR (-8)
# define MULTI_NAM (-9)
# define LABEL_CHA (-10)

# define NO_ENCODE(x) (x == 0x01 || x == 0x09 || x == 0x0c)
# define APP_INDEX(x) ((x >= 0x09 && x <= 0x0c) || (x >= 0x0e && x <= 0x0f))

typedef struct	s_pl
{
  char		*ptr;
  int		offset;
  int		line;
  char		type;
  struct s_pl	*next;
} t_pl;

typedef struct	s_lb
{
  char		*lbname;
  t_pl		*empl;
  int		value;
  int		line;
  struct s_lb	*next;
} t_lb;

typedef struct s_ass
{
  int		btnb;
  char		*rd;
  t_lb		*lb;
  char		*field;
  char		*pname;
  int		line;
  char		*pcom;
} t_ass;

int		my_cmd(char **tab, t_ass *prog, int code);
int		my_getcmd(char **tab, t_ass *prog);
int		my_label_pl(t_ass *prog);
t_ass		*parse_cmd(t_ass *prog);
t_ass		*parse_init(int fd, char *filename);
int		is_sep(char c, char *sep);
int		my_leng(char *str, char *sep);
void		my_fatal(char *str, char *str2);
void		my_err(int line, int errnum);
struct header_s	*my_headwrite(t_ass *prog);
void		my_writeinfile(t_ass *prog, int fd, char **av);
int		main(int ac, char **av);
int		my_get_pname(char *ptr, t_ass *prog);
char		*epur_str(char *str);
char		*my_strndup(char *src, int leng);
int		my_transpalette(char *str);
char		*my_unquote(char *str, int flag);
int		is_empty(char *ptr);
int		my_mod_index(char **tab, char *argtab);
int		ind_write(int value, char *ptr);
int		reg_write(int value, char *ptr);
int		direct_write(int value, char *ptr);
int		my_is_num(char c);
int		arg_nb_check(char **tab, int i);
int	        my_encode(char *argtab);
int		my_get_argtype(char *tab);
int		my_argtype(char **tab, char code, char *arg);
int		my_lookup(char l, char *j);
int		my_valid_label(char *label, int len);
int		my_get_lb(char **tab, t_ass *prog);
t_lb		*my_searchlb(t_lb *list, char *name);
void		put_new_lb_in_list(t_lb **list, t_ass *prog, char *name, int value);
int		my_put_lb_pl(t_pl **list, char *ptr, char argtab, t_ass *prog);
int		label_write(char *tab, char argtab, char *ptr, t_ass *prog);
int		my_writeall(char **tab, char *argtab, t_ass *prog, int j);
char		*hook_name_cor(char *name);
int		create_file(char *name);
char		*my_unquote(char *, int);
char		*my_strndup(char *, int);
t_lb		*my_searchlb(t_lb *, char *);
int		my_get_lb(char **, t_ass *);
char		*my_gnl(char *, int *);
char		**my_str_to_wordtab(char *, char *);
int		my_strcmp(char *, char *);
void		my_puterrnbr(int);
int		my_get_pname(char *, t_ass *);
char		*my_strdup(char *);
t_ass		*parse_init(int, char *);
int		my_strlen(char *);
int		my_getnbr(char *);
char		*my_strcat(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_putstr(char *);
void		my_putchar(char);
int		my_power_rec(int, int);
int		my_put_nbr(long long int);
int		my_strcpy(char *, char *);

#endif /* DOTH_H */
