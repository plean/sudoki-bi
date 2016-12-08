/*
** launch.c for  in /home/planch_j/rendu/CPE/sudoki-bi/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Feb 28 20:12:08 2016 Jean PLANCHER
** Last update Sun Feb 28 22:51:42 2016 Jean PLANCHER
*/

#include "sudoku.h"

static void	full_and_incorrect(unsigned char grille[9][9])
{
  int	i;

  if (if_zero(grille))
    {
      i = -1;
      while (++i < 9)
	{
	  grille[0][i] = 0;
	  grille[i][0] = 0;
	}
    }
}

void	launch_game(void)
{
  t_check	c;
  unsigned char	grille[9][9];
  int		k;

  if (!(k = my_errors(grille)))
    {
      fprintf(stderr, "MAP ERROR\n\n");
      return ;
    }
  if (k > 1)
    {
      init_check(&c);
      full_and_incorrect(grille);
      construct_check(grille, &c);
      if (test_sudoku(grille))
	{
	  resolution(grille, &c);
	  (if_zero(grille)) ? aff_sudoku(grille) : aff_wrong_sudoku();
	}
      else
	aff_wrong_sudoku();
      launch_game();
    }
}
