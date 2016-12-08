/*
** generator.c for Generator in /home/mei/SudokuGenerator/srcs/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 05:47:05 2016 Michel Mancier
** Last update Sun Feb 28 18:44:12 2016 Michel Mancier
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	match(char *s1, char *s2);
void	caesar(char *src, int hints);
void	swap_col(char *src, int from, int to);
void	swap_row(char *src, int from, int to);

void	init_source(char *source, char *filename)
{
  FILE		*fp;
  size_t	read;

  fp = fopen(filename, "r");
  read = fread(source, 1, 81, fp);
  if (read != 81)
    {
      printf("Invalid .doki file, or read failed.\n");
      exit(-1);
    }
  fclose(fp);
}

void	generator(char *src, int cnt, int shuffle, int hints)
{
  int	i[2];
  int	r[3];

  i[0] = -1;
  while (++i[0] < cnt)
    {
      i[1] = -1;
      while (++i[1] < shuffle)
	{
	  r[2] = ((rand() % 3) * 3);
	  r[0] = rand() & 1;
	  r[1] = rand() % 6;
	  if (r[1] == 0)
	    swap_row(src, r[2] + 0, r[0] ? r[2] + 1 : r[2] + 2);
	  else if (r[1] == 1)
	    swap_row(src, r[2] + 1, r[0] ? r[2] + 0 : r[2] + 2);
	  else if (r[1] == 2)
	    swap_row(src, r[2] + 2, r[0] ? r[2] + 0 : r[2] + 1);
	  else if (r[1] == 3)
	    swap_col(src, r[2] + 0, r[0] ? r[2] + 1 : r[2] + 2);
	  else (r[1] == 4) ? (swap_col(src, r[2] + 1, r[0] ? r[2] + 0 : r[2] + 2)) :
	      (swap_col(src, r[2] + 2, r[0] ? r[2] + 0 : r[2] + 1));
	}
      caesar(src, hints);
    }
}

int	main(int ac, char **av)
{
  int	cnt;
  int	shuffle;
  int	hints;
  char	source[82];

  if (ac != 5)
    return (printf("Usage: %s source count shuffle hints%%", av[0]));
  if (!match(av[1], "*.doki"))
    return (printf("Source needs to be a .doki file\n"));
  srand(time(NULL));
  cnt = atoi(av[2]);
  shuffle = atoi(av[3]);
  hints = atoi(av[4]);
  (hints >= 100 ? hints = 100 : 0);
  init_source(source, av[1]);
  generator(source, cnt, shuffle, hints);
}
