/*
** main.c for Doki Gen in /home/mei/SudokuGenerator/srcs/doki/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 06:41:24 2016 Michel Mancier
** Last update Sun Feb 28 13:51:44 2016 Michel Mancier
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	match(char *s1, char *s2);

void	printing(char *sudoku)
{
  int	i;

  i = 0;
  while (sudoku[i])
    {
      printf("%d ", sudoku[i]);
      ++i;
    }
}

void	write_doki(char *sudoku, char *filename)
{
  FILE	*fp;

  fp = fopen(filename, "w");
  fwrite(sudoku, 1, 81, fp);
  fclose(fp);
}

static int	get_case(char *sudoku, char c, int pos)
{
  if (c >= 48 && c <= 57)
    {
      sudoku[pos] = c - 48;
      return (0);
    }
  return (1);
}

static int	get_row(char *sudoku, char *line, int i)
{
  int	j;

  j = 2;
  i = (i - 1) * 9;
  if (line[0] != '|')
    return (1);
  if (line[19] != '|')
    return (1);
  while (j < 19)
    {
      if (get_case(sudoku, line[j], i) || line[j - 1] != ' ')
	return (1);
      j = j + 2;
      i = i + 1;
    }
  return (0);
}

void	get_sudoku(char	*sudoku, FILE *fp)
{
  char		*line;
  size_t	len;
  ssize_t	read;
  int		i;

  i = -1;
  len = 0;
  line = NULL;
  while (((read = getline(&line, &len, fp)) == 21) && (++i < 11))
    {
      printf("%s", line);
      if (i == 0 || i == 10)
	{
	  if (!(strcmp(line, "|------------------|\n")))
	    continue ;
	  else
	    exit(printf("Invalid map. Niktamer! 1\n"));
	}
      if (line != NULL)
	if (get_row(sudoku, line, i))
	  exit(printf("Invalid map. Niktamer! 2\n"));
    }
  if (read != 21 && i != 10)
    exit(printf("Invalid map. Niktamer! 3\n"));
  sudoku[81] = 0;
}

int	main(int ac, char **av)
{
  FILE	*fp;
  char	sudoku[82];

  if (ac < 2 || ac > 3)
    {
      printf("Usage : %s resolved_sudoku out.doki\n", av[0]);
      printf("Sudoki-bi format!\n");
      printf("If no *.doki name is given, or is invalid, output is out.doki\n");
    }
  fp = fopen(av[1], "r");
  if (fp == NULL)
    return (printf("Filename is not valid.\n"));
  get_sudoku(sudoku, fp);
  fclose(fp);
  if (av[2] != NULL)
    {
      if (match(av[2], "*.doki"))
	write_doki(sudoku, av[2]);
      else
	write_doki(sudoku, "out.doki");
      return (0);
    }
  write_doki(sudoku, "out.doki");
}
