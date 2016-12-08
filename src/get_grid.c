/*
** get_grid.c for Get Grid in /home/mei/Rendu/sudoki-bi/fini/srcs/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 00:44:53 2016 Michel Mancier
** Last update Sun Feb 28 20:40:28 2016 Jean PLANCHER
*/

#include "sudoku.h"

static int	get_case(unsigned char grille[9][9], char c, int y, int x)
{
  if (c == ' ')
    {
      grille[y][x] = 0;
      return (0);
    }
    else if (c >= 48 && c <= 57)
    {
      grille[y][x] = c - 48;
      return (0);
    }
  return (1);
}

static int	get_grid(unsigned char grille[9][9], const char *line, int n)
{
  int		i;

  if (n == 0 || n == 10)
    return ((strcmp(line, "|------------------|\n") != 0));
  if (line[0] != '|' || line[19] != '|')
    return (1);
  i = 2;
  while (i < 19)
    {
      if (get_case(grille, line[i], n - 1, (i / 2) - 1) || line[i - 1] != ' ')
	return (1);
      i = i + 2;
    }
  return (0);
}

int		my_errors(unsigned char grille[9][9])
{
  static t_bool	e;
  char		*line;
  int		i;
  size_t	len;
  ssize_t	read;

  line = NULL;
  i = -1;
  len = 0;
  while (i < 10 && (read = getline(&line, &len, stdin)) != -1)
      if (get_grid(grille, line, ++i))
	{
	  free(line);
	  return (0);
	}
  if (e == true && i == 10)
    printf("####################\n");
  e = true;
  free(line);
  return (i == 10 || i == -1) ? (1 + (i == 10)) : (0);
}
