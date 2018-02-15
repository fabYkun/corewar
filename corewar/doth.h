/*
** doth.h for doth in /home/rustam_t/rendu/corewar/graphics
** 
** Made by Timur Rustamov
** Login   <rustam_t@epitech.net>
** 
** Started on  Fri Apr 11 12:41:59 2014 Timur Rustamov
** Last update Fri Apr 11 17:05:02 2014 Timur Rustamov
*/

#ifndef DOTH_H
#define DOTH_H

#include <SDL/SDL.h>

#define NUM_LARG	(20)
#define OFF_LET		(25)
#define OFF_LINE	(30)
#define	COLNB		(96)
#define X_INI		(17)
#define Y_INI		(175)

typedef struct	s_txtures
{
  SDL_Surface	*bckgrd;
  SDL_Surface	**square;
  SDL_Surface	**numbers;
  SDL_Surface	**letters;
} t_textures;

typedef struct s_window
{
  char		**names;
  int		cycle;
  SDL_Surface	*screen;
  t_textures	*textures;
} t_window;

#endif /* DOTH_H */
