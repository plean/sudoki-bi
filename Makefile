##
## Makefile for  in /home/mei/Rendu/sudoki-bi/fini
##
## Made by Michel Mancier
## Login   <mancie_m@epitech.net>
##
## Started on  Sun Feb 28 01:51:38 2016 Michel Mancier
## Last update Sun Feb 28 20:37:20 2016 Jean PLANCHER
##

CC	=	gcc
RM	=	\rm -f

NAME	=	bin/sudoki-bi

SRCS	=	src/aff.c \
		src/algo.c \
		src/fct.c \
		src/get_grid.c \
		src/list.c \
		src/main.c \
		src/launch.c \
		src/test_sudoku.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -g -O3 -I./include

all:		$(NAME)

$(NAME):	$(OBJS)
		@echo -e "\e[0m"
		@$(CC) $(OBJS) -o $(NAME)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreated !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o files..."
		@$(RM) $(OBJS)
		@echo -e "	 [\e[32mOk !\e[39m]\e[0m"

fclean:		clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME)
		@echo -e "		 [\e[32m0k !\e[39m]\e[0m"

re:		fclean all

.c.o:%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY:		all clean fclean re
