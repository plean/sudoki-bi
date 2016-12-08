## Makefile for  in /home/planch_j/rendu/iconofsin_2020
##
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
##
## Started on  Thu Nov 19 09:46:44 2015 Jean PLANCHER
## Last update Sun Feb 28 21:56:48 2016 Jean PLANCHER
##

NAME	= ../sudoku

LIB	= -L/home/${USER}/.froot/lib/ -llapin \
	  -L/usr/local/lib \
	  -lsfml-audio \
	  -lsfml-graphics \
	  -lsfml-window \
	  -lsfml-system \
	  -lstdc++ -ldl \
	  -lm

FLAG	= -W -Wall -Wextra -O3 -I/home/${USER}/.froot/include/ -I../include

SRC	= main.c \
	tekpixel.c \
	init_tabl.c \
	case.c \
	fox_mod_stretch.c \
	fox_calc_pos.c \
	aff.c \
	algo.c \
	fct.c \
	get_grid.c \
	list.c \
	test_sudoku.c \
	is_ended.c \
	fox_load_music.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.c.o:
	gcc -c $< -o $@ $(FLAG)
