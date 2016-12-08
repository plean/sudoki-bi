/*
** fct.c for Functions in /home/mei/Rendu/sudoki-bi/fini/srcs/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 01:42:14 2016 Michel Mancier
** Last update Sun Feb 28 20:40:22 2016 Jean PLANCHER
*/

#include "sudoku.h"

int	getsqu(int i, int j)
{
  return (3 * (i / 3) + (j / 3));
}
