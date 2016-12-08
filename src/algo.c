/*
** algo.c for Algo in /home/mei/Rendu/sudoki-bi/fini/srcs/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 00:46:16 2016 Michel Mancier
** Last update Sun Feb 28 20:40:13 2016 Jean PLANCHER
*/

#include "sudoku.h"

static t_bool	is_valid(unsigned char grille[9][9],
			 const t_list *pos, t_check *c)
{
  int		i;
  int		j;
  int		k;

  if (pos == NULL)
    return true;
  i = pos->i;
  j = pos->j;
  k = -1;
  while (++k < 9)
    {
      if (!c->onrow[i][k] && !c->oncol[j][k] && !c->onsqu[getsqu(i, j)][k])
	{
	  c->onrow[i][k] = c->oncol[j][k] = c->onsqu[getsqu(i, j)][k] = true;
	  if (is_valid(grille, pos->next, c))
	    {
	      grille[i][j] = k + 1;
	      return true;
	    }
	  c->onrow[i][k] = c->oncol[j][k] = c->onsqu[getsqu(i, j)][k] = false;
	}
    }
  return (false);
}

static int	nb_avail(int i, int j, const t_check *c)
{
  int		ret;
  int		k;

  ret = 0;
  k = -1;
  while (++k < 9)
    if (!c->onrow[i][k] && !c->oncol[j][k] && !c->onsqu[getsqu(i, j)][k])
      ++ret;
  return (ret);
}

void	init_check(t_check *c)
{
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  c->onrow[i][j] = false;
	  c->oncol[i][j] = false;
	  c->onsqu[i][j] = false;
	}
    }
}

void	construct_check(unsigned char grille[9][9], t_check *c)
{
  int	i;
  int	j;
  int	k;

  k = 0;
  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	if ((k = grille[i][j]) != 0)
	  {
	    c->onrow[i][k - 1] = true;
	    c->oncol[j][k - 1] = true;
	    c->onsqu[getsqu(i, j)][k-1] = true;
	  }
    }
}

void	resolution(unsigned char grille[9][9], t_check *c)
{
  int		i[2];
  t_list	*pos;

  pos = NULL;
  if ((i[0] = if_zero_line(grille)) == -1)
    while (++i[0] < 9)
      {
	i[1] = -1;
	while (++i[1] < 9)
	  if (grille[i[0]][i[1]] == 0)
	    add_to_head(&pos, i[0], i[1], nb_avail(i[0], i[1], c));
	}
  else
    while (--i[0] > -1)
      {
	i[1] = 9;
	while (--i[1] > -1)
	  if (grille[i[0]][i[1]] == 0)
	    add_to_head(&pos, i[0], i[1], nb_avail(i[0], i[1], c));
	}
  pos = sort_list(pos);
  is_valid(grille, pos, c);
  free_list(&pos);
}
