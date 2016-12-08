/*
** is_ended.c for  in /home/planch_j/rendu/CPE/sudoki-bi/bonus/game/src/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Feb 28 21:31:34 2016 Jean PLANCHER
** Last update Sun Feb 28 23:12:27 2016 Jean PLANCHER
*/

#include "my_bonus.h"

static void		winning_screen(t_struct *b)
{
  t_bunny_pixelarray	*end;

  if ((end = bunny_load_pixelarray("img/end.jpg")) == NULL)
    return ;
  bunny_delete_clipable(&b->pix->clipable);
  b->pix = bunny_new_pixelarray(SQUARE_SIZE * 9 + ECART * 2,
			     SQUARE_SIZE * 9 + ECART * 2);
  fox_mod_stretch(b->pix, end);
  fox_load_music(b->music, "sound/end.wav", 100);
}

void	check_is_finish(t_struct *b)
{
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	if (!check_same(b->grille, b->res_grille, i, j))
	    return ;
    }
      b->k = 1;
      winning_screen(b);
}
