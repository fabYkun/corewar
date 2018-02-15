/*
** my.h for my in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Wed Apr  9 11:08:25 2014 fabien borel
** Last update Sun Apr 13 23:15:22 2014 fabien borel
*/

#ifndef MY_H_
# define MY_H_

# include			"doth.h"
# include			"op.h"

struct				s_dcchain
{
  void				*ptr;
  struct s_dcchain		*prev;
  struct s_dcchain		*next;
};

typedef struct s_dcchain	t_dcchain;

struct				s_player
{
  char				*name;
  unsigned int			nb_process;
  unsigned int			last_live;
};

typedef struct s_player		t_player;

struct				s_motherbrain
{
  char				*memory;
  char				*field;
  unsigned int			cycles;
  int				cycle_to_die;
  t_dcchain			*prgms;
  t_player			**players;
  unsigned char			nb_players;
};

struct				s_prgm
{
  t_header			header;
  char				*core;
};

struct				s_current
{
  int				registre[REG_NUMBER];
  unsigned int			cursor;
  char				live;
  int				cycle;
  unsigned char			player;
  unsigned char			carry;
  unsigned int			pc;
};

/*
** player (de 1 à 4)
** positions contient tous les curseurs du joueur
** is_alive est à 1 si le joueur est encore en vie (0 si pas assez de live)
**
** NOTE: mais ça m'arrangerait si tu/vous faisiez une fonction qui prend
** en argument un joueur, une position et un is_alive et dedans vous settez
** juste la couleur pour cette position en fonction des 3paramètres
** comme ça j'ai pas besoin de parcourir mes chaines pour stocker les
** positions et vous vous avez pas besoin de parcourir le tableau, et puis ça
** revient pareil non ? Si vous le faites, la structure ci-dessous est inutile
*/

struct				s_com
{
  unsigned char			player;
  unsigned int			*positions;
  char				is_alive;
};

typedef	struct s_motherbrain	t_motherbrain;
typedef struct s_prgm		t_prgm;
typedef struct s_current	t_current;
typedef struct s_com		t_com;

t_textures			*my_get_textures();

char				add_to_list(t_dcchain **chain, void *ptr);
void				vanish_list(t_dcchain *list);
int				get_header(t_header *header, int fd);
int				error_gestion(int error);
int				washmachine(t_motherbrain *);

int				do_command(t_motherbrain *, t_current *);
int				vm_live(t_motherbrain *, t_current *);
int				vm_ld(t_motherbrain *, t_current *);
int				vm_st(t_motherbrain *, t_current *);
int				vm_add(t_motherbrain *, t_current *);
int				vm_sub(t_motherbrain *, t_current *);
int				vm_and(t_motherbrain *, t_current *);
int				vm_or(t_motherbrain *, t_current *);
int				vm_xor(t_motherbrain *, t_current *);
int				vm_zjmp(t_motherbrain *, t_current *);
int				vm_ldi(t_motherbrain *, t_current *);
int				vm_sti(t_motherbrain *, t_current *);
int				vm_fork(t_motherbrain *, t_current *);
int				vm_lld(t_motherbrain *, t_current *);
int				vm_lldi(t_motherbrain *, t_current *);
int				vm_lfork(t_motherbrain *, t_current *);
int				vm_aff(t_motherbrain *, t_current *);

void				fill_prgm(t_current *prgm);
void				fill_memory(char *memory, int size);
t_player			*new_player(char *name);
void				free_players(t_player **players);

unsigned int			round_mem(int cursor);
void				to_registre(int value, unsigned char r,
					    t_current *);
char				arg_type(unsigned char octet, char posi);
int				get_octets(char *memory, int cursor, char hm);
void				set_octets(char *memory, int cursor,
					   int what, char howmany);

unsigned char			instruction_len(char *memory, int c, char t);
int				do_instruction(t_motherbrain *, t_current *,
					       unsigned char todo);
int				launch_cycle(t_motherbrain *motherbrain,
					     t_dcchain *prgms);

#endif /* !MY_H_ */
