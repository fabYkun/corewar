##
## Makefile for Makefile in /home/rustam_t/rendu/corewar/alphaasm
## 
## Made by Timur Rustamov
## Login   <rustam_t@epitech.net>
## 
## Started on  Thu Apr 10 11:52:57 2014 Timur Rustamov
##

CC		=	gcc

NAME		=	asm

SRCS		=	asm_command.c \
			asm_label.c \
			asm_label2.c \
			asm_write.c \
			asm_write2.c \
			asm_dotcor.c \
			epur.c \
			functions.c \
			my_fatal.c \
			my_err.c \
			get_name.c \
			my_str_to_wordtab.c \
			op.c\
			my_putchar.c\
			my_getnbr.c\
			my_power_rec.c\
			my_putstr.c\
			my_strlen.c\
			my_strncmp.c\
			my_strcmp.c\
			my_strdup.c\
			my_strcat.c\
			my_strcpy.c\
			my_put_nbr.c\
			main.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
