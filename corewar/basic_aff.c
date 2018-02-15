/*
** basic_aff.c for basic_aff in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Sun Apr 13 23:06:41 2014 fabien borel
** Last update Sun Apr 13 23:15:02 2014 fabien borel
*/

#include		<time.h>
#include		<SDL/SDL.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		"doth.h"
#include		"my.h"
#include		"prototypes.h"

void			apply_surface(int x, int y, SDL_Surface *src,
				      SDL_Surface *dest)
{
  SDL_Rect		offset;

  offset.x = x;
  offset.y = y;
  if (SDL_BlitSurface(src, NULL, dest, &offset) == -1)
    my_fatal("System call blit failed!\n", NULL);
}

void			my_textput(t_window *win, int x, int y, char *text)
{
  int			i;

  i = -1;
  while (text[++i] != 0)
    {
      if (text[i] >= '0' && text[i] <= '9')
	{
	  apply_surface(x, y, win->textures->numbers[text[i] - 48],
			win->screen);
	  x += NUM_LARG;
	}
      else if ((text[i] >= 'a' && text[i] <= 'z') ||
	       (text[i] >= 'A' && text[i] <= 'Z'))
	{
	  if (text[i] >= 'a' && text[i] <= 'z')
	    apply_surface(x, y, win->textures->letters[text[i] - 'a'],
			  win->screen);
	  else
	    apply_surface(x, y, win->textures->letters[text[i] - 'A'],
			  win->screen);
	  x += NUM_LARG;
	}
      else
	x += NUM_LARG;
    }
}

void			my_put_on_screen(t_window *win, char *field)
{
  if (SDL_FillRect(win->screen, NULL, 0xFFFFFFF) == -1)
    my_fatal("Something wrong happened!\n", "SDL : ");
  apply_surface(0, 0, win->textures->bckgrd, win->screen);
  my_aff(win, field);
  if (SDL_Flip(win->screen) == -1)
    my_fatal("Failed to refresh the screen!\n", NULL);
}

t_textures		*my_get_textures()
{
  t_textures		*txt;
  char			*let;
  int			i;

  if ((txt = malloc(sizeof(t_textures))) == NULL ||
      (txt->bckgrd = SDL_LoadBMP("./textures/backgrd.bmp")) == NULL ||
      (txt->square = malloc(sizeof(SDL_Surface *) * 5)) == NULL ||
      (txt->square[0] = SDL_LoadBMP("./textures/white.bmp")) == NULL ||
      (txt->square[1] = SDL_LoadBMP("./textures/red.bmp")) == NULL ||
      (txt->square[2] = SDL_LoadBMP("./textures/blue.bmp")) == NULL ||
      (txt->square[3] = SDL_LoadBMP("./textures/green.bmp")) == NULL ||
      (txt->square[4] = SDL_LoadBMP("./textures/orange.bmp")) == NULL ||
      (txt->letters = malloc(sizeof(SDL_Surface *) * 26)) == NULL ||
      (txt->numbers = malloc(sizeof(SDL_Surface *) * 10)) == NULL)
    my_fatal("Failed to fetch images!\n", NULL);
  let = my_strdup("./textures/alphanum/@.bmp");
  i = -1;
  while (++let[20] <= 'Z')
      if ((txt->letters[++i] = SDL_LoadBMP((const char *)let)) == NULL)
	my_fatal("Failed to load letters!\n", NULL);
  let[20] = 47;
  i = -1;
  while (++let[20] <= '9')
    if ((txt->numbers[++i] = SDL_LoadBMP((const char *)let)) == NULL)
      my_fatal("Failed to load numbers!\n", NULL);
  return (txt);
}

void                    my_fpscnt()
{
  static clock_t	*time1 = NULL;
  clock_t		time2;
  float			timediff;

  if (time1 == NULL)
    {
      if ((time1 = malloc(sizeof(clock_t))) == NULL)
        my_fatal("Failed to malloc!", NULL);
      *time1 = clock();
    }
  time2 = clock();
  timediff = (float)(time2 - *time1) / CLOCKS_PER_SEC;
  *time1 = time2;
  if (timediff < 0.0016666)
    usleep((int)((0.0016666 - timediff) * 1000));
}
