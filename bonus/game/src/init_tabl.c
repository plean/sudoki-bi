/*
** init_tabl.c for  in /home/planch_j/rendu/CPE/sudoki-bi/bonus/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sat Feb 27 23:41:05 2016 Jean PLANCHER
** Last update Sun Feb 28 23:18:53 2016 Jean PLANCHER
*/

#include <stdio.h>
#include "my_bonus.h"

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

static int	get_tabl(t_struct *a)
{
  int		i[3];

  if (!(i[0] = my_errors(a->grille)))
    {
      fprintf(stderr, "MAP ERROR\n\n");
      return (1);
    }
  i[1] = -1;
  while (++i[1] < 9)
    {
      i[2] = -1;
      while (++i[2] < 9)
	{
	  a->res_grille[i[1]][i[2]] = a->grille[i[1]][i[2]];
	  a->is_printable[i[1]][i[2]] = (a->grille[i[1]][i[2]]) ? (1) : (0);
	}
    }
  return (0);
}

int		init_tabl(t_struct *a)
{
  t_check	c;

  if (get_tabl(a))
    return (1);
  init_check(&c);
  full_and_incorrect(a->res_grille);
  construct_check(a->res_grille, &c);
  if (test_sudoku(a->res_grille))
    {
      resolution(a->res_grille, &c);
      if (if_zero(a->res_grille))
	return (0);
    }
  return (1);
}
