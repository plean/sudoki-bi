/*
** test_sudoku.c for  in /home/planch_j/rendu/CPE/sudoki-bi/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Feb 28 03:07:45 2016 Jean PLANCHER
** Last update Sun Feb 28 16:58:54 2016 Michel Mancier
*/

#include "sudoku.h"

int	if_zero_line(unsigned char grille[9][9])
{
  int	line;
  int	j;
  int	cnt[2];

  cnt[0] = 0;
  cnt[1] = 0;
  line = 0;
  j = -1;
  while (++j < 9)
    {
      if (grille[line][j])
	cnt[0] = cnt[0] + 1;
    }
  line = 8;
  j = -1;
  while (++j < 9)
    {
      if (grille[line][j])
	cnt[1] = cnt[1] + 1;
    }
  if (cnt[0] > cnt[1])
    return (-1);
  else
    return (9);
}

int	if_zero(unsigned char grille[9][9])
{
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  if (!grille[i][j])
	    return (0);
	}
  }
  return (1);
}

int	check_line(unsigned char grille[9][9])
{
  char	*line;
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      line = strdup("123456789");
      j = -1;
      while (++j < 9)
	{
	  if (grille[i][j] != 0 &&
	      (line[grille[i][j] - 1] < '1' || line[grille[i][j] - 1] > '9'))
	    {
	      free(line);
	      return (0);
	    }
	  else if (grille[i][j] != 0)
	    line[grille[i][j] - 1] = 0;
	}
      free(line);
    }
  return (1);
}

int	check_column(unsigned char grille[9][9])
{
  char	*line;
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      line = strdup("123456789");
      j = -1;
      while (++j < 9)
	{
	  if (grille[j][i] != 0 &&
	      (line[grille[j][i] - 1] < '1' || line[grille[j][i] - 1] > '9'))
	    {
	      free(line);
	      return (0);
	    }
	  else if (grille[j][i] != 0)
	    line[grille[j][i] - 1] = 0;
	}
      free(line);
    }
  return (1);
}

int	test_sudoku(unsigned char grille[9][9])
{
  if (!check_line(grille) || !check_column(grille))
    return (0);
  return (1);
}
