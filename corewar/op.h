/*
** op.h for op in /home/borel_d/rendu/CPE_2014_corewar
**
** Made by fabien borel
** Login   <borel_d@epitech.net>
**
** Started on  Mon Mar 24 16:40:36 2014 fabien borel
** Last update Sun Apr 13 22:29:10 2014 fabien borel
*/

#ifndef OP_H_
# define OP_H_

# define MEM_SIZE		(6 * 1024)
# define MAX_SIZE		1024
# define IDX_MOD		512
# define MAX_ARGS_NUMBER	4
# define NB_MAXPRGM		4

# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING         ".name"
# define COMMENT_CMD_STRING      ".comment"

# define REG_NUMBER		16

typedef char			t_args_type;

/*
** taille des options (registre, direct, indirect, labels)
** - registre
** - indirecte (ld #1, r1 met 1 dans r1)
** - indirecte relatif (ld 1, r1 met le contenu de (1 + pc) dans le registre 1
** - label
*/

# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

/*
** valeurs retournées en fonction du type par arg_type()
**
** - registre	= 1
** - direct	= 2
** - indirect	= 3
*/

# define R_REG			1
# define R_DIR			2
# define R_IND			3

# define S_REG			1
# define S_DIR			4
# define S_IND			2

struct				s_op
{
  char				*mnemonique;
  char				nbr_args;
  t_args_type			type[MAX_ARGS_NUMBER];
  char				code;
  int				nbr_cycles;
  char				*comment;
};

typedef struct s_op		t_op;

/*
** tailles =)
*/

# define IND_SIZE		2
# define REG_SIZE		4
# define DIR_SIZE		REG_SIZE

/*
** op_tab
*/

extern t_op			op_tab[];

/*
** header
*/

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

struct				s_header
{
  int				magic;
  char				name[PROG_NAME_LENGTH + 1];
  int				prog_size;
  char				comment[COMMENT_LENGTH + 1];
};

typedef struct s_header		t_header;

/*
** live
** CYCLE TO DIE est le nombre de cycles pour etre declare mort
*/

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		4
# define NBR_LIVE		2048

#endif /* !OP_H_ */
