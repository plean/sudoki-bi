##
## Makefile for sudoki-gen in /home/mei/SudokuGenerator
##
## Made by Michel Mancier
## Login   <mancie_m@epitech.net>
##
## Started on  Sun Feb 28 04:55:56 2016 Michel Mancier
## Last update Sun Feb 28 19:48:55 2016 Jean PLANCHER
##

CC	=	gcc
RM	=	\rm -f

NAME1	=	bin/doki
SRCS1	=	srcs/doki/main.c \
		srcs/doki/match.c
OBJS1	=	$(SRCS1:.c=.o)

NAME2	=	bin/generator
SRCS2	=	srcs/generator/generator.c \
		srcs/generator/fct.c \
		srcs/generator/match.c
OBJS2	=	$(SRCS2:.c=.o)

CFLAGS	=	-W -Wall -Wextra

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
		@echo -e "\e[0m"
		@$(CC) $(OBJS1) -o $(NAME1)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME1) "\e[32mcreated !\e[0m"

$(NAME2):	$(OBJS2)
		@echo -e "\e[0m"
		@$(CC) $(OBJS2) -o $(NAME2)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME2) "\e[32mcreated !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o files..."
		@$(RM) $(OBJS1) $(OBJS2)
		@echo -e "	 [\e[32mOk !\e[39m]\e[0m"

fclean:		clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME1) $(NAME2)
		@echo -e "		 [\e[32m0k !\e[39m]\e[0m"

re:		fclean all

.c.o:%.c
	@$(CC) -c $< -o $@ $(CFLAGS) && \
	echo -e "\e[32m[OK]" $< "\e[93m"|| \
	echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY:		all clean fclean re
