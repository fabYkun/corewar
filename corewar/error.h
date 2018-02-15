/*
** error.h for error in /home/borel_d/rendu/CPE_2014_corewar/vm
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Tue Apr  8 14:56:55 2014 fabien borel
** Last update Sun Apr 13 11:29:58 2014 fabien borel
*/

#ifndef ERROR_H_
# define ERROR_H_

# define NAME			"VM"

# define NB_MALLOC		-1
# define NB_READ		-2
# define NB_OPEN		-3
# define NB_PROTO		-4
# define NB_MAGIC		-5
# define NB_SIZE		-6
# define NB_ERR_MAXPRGM		-7
# define NB_MEM_EMPTY		-8

# define ERR_MALLOC		"malloc has failed"
# define ERR_READ		"error on reading file"
# define ERR_OPEN		"error on open"
# define ERR_PROTO		"usage: ./exec file.cor"
# define ERR_MAGIC		"bad magic number"
# define ERR_SIZE		"champion's size is too big"
# define ERR_MAXPRGM		"too many champions"
# define ERR_MEM_EMPTY		"we couldn't find any valid instruction =("

#endif /* !ERROR_H_ */
