/*
** fox_mod_stretch.c for Fox Mod Stretch in /home/mei/GitHub/LibMcCloud/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sat Dec 26 13:29:32 2015 Michel Mancier
** Last update Sun Feb 28 20:26:11 2016 Jean PLANCHER
*/

#include "my_bonus.h"

void	fox_mod_stretch(t_bunny_pixelarray *pix,
			t_bunny_pixelarray *ori)
{
  int	x_ratio;
  int	y_ratio;
  int	i;
  int	j;
  int	xy[2];

  x_ratio = (int)((ori->clipable.clip_width << 16)
	     / pix->clipable.clip_width) + 1;
  y_ratio = (int)((ori->clipable.clip_height << 16)
	     / pix->clipable.clip_height) + 1;
  i = 0;
  while (i < pix->clipable.clip_height)
    {
      j = 0;
      while (j < pix->clipable.clip_width)
	{
	  xy[0] = ((j * x_ratio) >> 16);
	  xy[1] = ((i * y_ratio) >> 16);
	  ((t_color *)pix->pixels)[fox_calc_pos(j, i, pix)] =
	  ((t_color *)ori->pixels)[fox_calc_pos(xy[0], xy[1], ori)];
	  j = j + 1;
	}
      i = i + 1;
    }
}
