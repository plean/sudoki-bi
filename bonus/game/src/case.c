/*
** load_case.c for  in /home/planch_j/rendu/CPE/sudoki-bi/bonus/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Feb 28 01:31:14 2016 Jean PLANCHER
** Last update Sun Feb 28 20:26:24 2016 Jean PLANCHER
*/

#include <stdio.h>
#include "my_bonus.h"

int	check_same(unsigned char grille[9][9],
		   unsigned char res_grille[9][9],
		   int y, int x)
{
  return (grille[y][x] == res_grille[y][x]);
}

void	incr_case(t_struct *a,
		  t_bunny_position *pos,
		  char c)
{
  int	x;
  int	y;

  x = pos->x / (a->pix->clipable.clip_width / 9);
  y = pos->y / (a->pix->clipable.clip_height / 9);
  if (!a->is_printable[y][x])
    a->grille[y][x] += 10 + c;
  a->grille[y][x] %= 10;
}

void		load_case(t_struct *b,
			  int n, int e)
{
  int		i;
  int		j;
  int		size;
  unsigned int	*pixel[3];

  pixel[0] = (unsigned *)b->pix->pixels;
  pixel[1] = (unsigned *)b->square->pixels;
  pixel[2] = (unsigned *)b->nb->pixels;
  size = b->square->clipable.clip_height;
  i = -1;
  while (++i < size)
    {
      j = -1;
      while (++j < size)
	pixel[0][(i + ECART * (((n - 1) / 3) % 3) + ((n - 1) % 9) * size) *
      b->pix->clipable.clip_width + j + ((n - 1) / 9) * (size) + ((n - 1) / 27)
      * ECART] = (e && pixel[2][i * size * 9 + j + (e - 1) * size] != 0xFFFFFFFF)
	  ? pixel[2][i * size * 9 + j + (e - 1) * size] : pixel[1][i * size + j]
      - 0x00666666 * (pixel[1][i * size + j] > 0xFFEEEEEE &&
		      b->is_printable[(n - 1) % 9][(n - 1) / 9] > 0);
    }
}
