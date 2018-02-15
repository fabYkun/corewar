/*
** main.c for corewar in /home/rustam_t/rendu/corewar/graphics
**
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
**
** Started on  Fri Apr 11 12:40:51 2014 Timur Rustamov
** Last update Sun Apr 13 23:12:53 2014 fabien borel
*/

#include		<time.h>
#include		<SDL/SDL.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		"doth.h"
#include		"my.h"
#include		"prototypes.h"

void			apply_texture(t_window *win, char *field)
{
  int			i;
  int			x;
  int			y;

  i = -1;
  while (++i < MEM_SIZE)
    {
      x = X_INI + (i % COLNB) * 8;
      y = Y_INI + (i / COLNB) * 7;
      apply_surface(x, y, win->textures->square[(int)field[i]], win->screen);
    }
}

int			my_aff(t_window *win, char *field)
{
  int			i;
  char			*str[2];

  i = -1;
  while (win->names[++i] != NULL)
    {
      apply_surface(OFF_LET, i * OFF_LINE + 30, win->textures->square[i + 1],
		    win->screen);
      my_textput(win, OFF_LET + 10, i * OFF_LINE + 20, win->names[i]);
    }
  my_textput(win, OFF_LET * 9, 4 * OFF_LINE, "Cycle to die: ");
  if ((str[0] = malloc(sizeof(char) * 32)) == NULL)
    my_fatal("Memory allocation failed!\n", NULL);
  str[1] = str[0];
  my_putnbr_base(win->cycle, "0123456789", &str[0]);
  my_textput(win, OFF_LET * 9 + 14 * NUM_LARG, 4 * OFF_LINE, str[1]);
  free(str[1]);
  apply_texture(win, field);
  return (0);
}

char			**my_get_names(t_motherbrain *mother)
{
  int			i;
  char			**names;

  if ((names = malloc(sizeof(char *) * 5)) == NULL)
    return (NULL);
  i = -1;
  while (++i < 4)
    {
      if (mother->players[i] != NULL)
	{
	  names[i] = my_strdup(mother->players[i]->name);
	  my_putstr(mother->players[i]->name);
	  my_putchar('\n');
	}
      else
	names[i] = NULL;
    }
  names[4] = NULL;
  return (names);
}

char			*get_field(t_motherbrain *mother, t_dcchain *prg)
{
  t_dcchain		*start;
  t_current		*ptr;
  char			*field;
  int			i;

  i = -1;
  field = mother->field;
  while (++i < MEM_SIZE)
    field[i] = 0;
  start = prg;
  while (start != NULL)
    {
      ptr = (t_current *)start->ptr;
      field[ptr->cursor] = ptr->player;
      start = start->next;
    }
  return (field);
}

int			my_getimg(t_motherbrain *mother)
{
  static t_window	*win = NULL;
  char			*field;

  if (win == NULL)
    {
      if ((win = malloc(sizeof(t_window))) == NULL ||
	  (win->textures = my_get_textures()) == NULL ||
	  SDL_Init(SDL_INIT_VIDEO) == -1 ||
	  (win->names = my_get_names(mother)) == NULL ||
	  ((win->screen = SDL_SetVideoMode(800, 640, 32, SDL_HWSURFACE))
	   == NULL))
	my_fatal("Something wrong happened!", NULL);
      SDL_WM_SetCaption("VM Corewar", NULL);
      atexit(SDL_Quit);
    }
  my_fpscnt();
  win->cycle = mother->cycle_to_die;
  my_put_on_screen(win, (field = get_field(mother, mother->prgms)));
  if (SDL_VIDEOEXPOSE && SDL_Flip(win->screen) == -1)
    my_fatal("Failed to refresh the screen!\n", NULL);
  return (0);
}
