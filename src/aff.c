/*
** aff.c for Affichage in /home/mei/Rendu/sudoki-bi/fini/srcs/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 01:42:51 2016 Michel Mancier
** Last update Sun Feb 28 20:39:58 2016 Jean PLANCHER
*/

#include "sudoku.h"

void	aff_wrong_sudoku()
{
  printf("|------------------|\n| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n|------------------|\n");
}

void	aff_sudoku(unsigned char grille[9][9])
{
  int	i;
  int	j;

  printf("|------------------|\n");
  i = -1;
  while (++i < 9)
    {
      j = -1;
      printf("|");
      while (++j < 9)
	printf(" %d", grille[i][j]);
      printf("|\n");
    }
  printf("|------------------|\n");
}
