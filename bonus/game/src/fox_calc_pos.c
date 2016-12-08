/*
** fox_calc_pos.c for Fox Calc Pos in /home/mei/GitHub/LibMcCloud/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sat Dec 26 13:30:05 2015 Michel Mancier
** Last update Sun Feb 28 20:26:17 2016 Jean PLANCHER
*/

#include "my_bonus.h"

int	fox_calc_pos(int x, int y, t_bunny_pixelarray *pix)
{
  return (y * pix->clipable.clip_width + x);
}
