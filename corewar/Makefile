##
## Makefile for Makefile in /home/borel_d/rendu/CPE_2014_corewar/JOSECACA
## 
## Made by fabien borel
## Login   <borel_d@epitech.net>
## 
## Started on  Wed Apr  2 18:27:12 2014 fabien borel

##

NAME	=	corewar

CC	=	gcc

RM	=	rm -f

SYS_FX	=	sys_fx/add.c			\
		sys_fx/aff.c			\
		sys_fx/and.c			\
		sys_fx/do_command.c		\
		sys_fx/fork.c			\
		sys_fx/give_param.c		\
		sys_fx/ld.c			\
		sys_fx/ldi.c			\
		sys_fx/live.c			\
		sys_fx/lld.c			\
		sys_fx/lldi.c			\
		sys_fx/or.c			\
		sys_fx/st.c			\
		sys_fx/sti.c			\
		sys_fx/sub.c			\
		sys_fx/xor.c			\
		sys_fx/zjmp.c

FX	=	functions/my_getnbr.c		\
		functions/my_putmem.c		\
		functions/my_putchar.c		\
		functions/my_puterror.c		\
		functions/my_putstr.c		\
		functions/my_put_nbr.c		\
		functions/my_strdup.c		\
		functions/reverse_int.c		\
		functions/my_strlen.c

SRC	=	op.c				\
		header.c			\
		add_to_list.c			\
		players.c			\
		fill_blanks.c			\
		error_handler.c			\
		basic_aff.c			\
		aff.c				\
		my_fatal.c			\
		my_putnbr_base.c		\
		memory.c			\
		launch_cycle.c			\
		end_condition.c			\
		washmachine.c			\
		motherbrain.c

CFLAGS	=	-W -Wextra -Werror

SYSOBJ	=	$(SYS_FX:.c=.o)

FOBJ	=	$(FX:.c=.o)

OBJ 	=	$(SRC:.c=.o)

TMP 	=	$(SRC:.c=.c~)

all: 		$(NAME)

$(NAME) :	$(SYSOBJ) $(FOBJ) $(OBJ)
		$(CC) $(SYSOBJ) $(FOBJ) $(OBJ) -o $(NAME) -lSDL -lSDLmain

clean:
		$(RM) $(SYSOBJ) $(FOBJ) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

norm:		re
		$(RM) $(SYSOBJ) $(FOBJ) $(OBJ)
		$(RM) $(TMP)
