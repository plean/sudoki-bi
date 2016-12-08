/*
** tekpixel.c for  in /home/planch_j/rendu/Info/chromatic_2020
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Feb  5 14:42:15 2016 Jean PLANCHER
** Last update Sun Feb 28 20:45:08 2016 Jean PLANCHER
*/

#include "my_bonus.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*pixel;

  pixel = (unsigned int *)pix->pixels;
  if (pos->y >= 0 && pos->x >= 0 && pos->x < pix->clipable.clip_width
      && pos->y < pix->clipable.clip_height)
  pixel[pix->clipable.clip_width * pos->y + pos->x] = color;
}
