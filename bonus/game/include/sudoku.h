/*
** sudoku.h for  in /home/planch_j/rendu/CPE/sudoki-bi/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Feb 28 20:13:30 2016 Jean PLANCHER
** Last update Sun Feb 28 23:00:21 2016 Jean PLANCHER
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include "list.h"

typedef struct	s_check
{
  bool onrow[9][9];
  bool oncol[9][9];
  bool onsqu[9][9];
}		t_check;

void	launch_game(void);
void	aff_sudoku(unsigned char grille[9][9]);
int	getsqu(int i, int j);
int	my_errors(unsigned char grille[9][9]);
void	init_check(t_check *c);
void	construct_check(unsigned char grille[9][9], t_check *c);
void	resolution(unsigned char grille[9][9], t_check *c);
int	if_zero(unsigned char grille[9][9]);
void	aff_wrong_sudoku();
int	test_sudoku(unsigned char grille[9][9]);
int	if_zero_line(unsigned char grille[9][9]);

#endif /* !SUDOKU_H_ */
