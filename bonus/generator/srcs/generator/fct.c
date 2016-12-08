/*
** fct.c for Functions in /home/mei/SudokuGenerator/srcs/generator/
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.eu>
**
** Started on  Sun Feb 28 14:30:53 2016 Michel Mancier
** Last update Sun Feb 28 18:42:54 2016 Michel Mancier
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	swap_row(char *src, int from, int to)
{
  char	*ptr1;
  char	*ptr2;
  int	i;
  int	tmp;

  ptr1 = src + (9 * from);
  ptr2 = src + (9 * to);
  i = -1;
  while (++i < 9)
    {
      tmp = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = tmp;
      ++ptr1;
      ++ptr2;
    }
}

void	swap_col(char *src, int from, int to)
{
  char	*ptr1;
  char	*ptr2;
  int	i;
  int	tmp;

  ptr1 = src + from;
  ptr2 = src + to;
  i = -1;
  while (++i < 9)
    {
      tmp = *ptr1;
      *ptr1 = *ptr2;
      *ptr2 = tmp;
      ptr1 += 9;
      ptr2 += 9;
    }
}

void	print_matrix(char *src, int hints)
{
  int	i;

  i = -1;
  printf("|------------------|\n");
  while (++i < 81)
    {
      if ((i % 9) == 0)
	printf("|");
      if ((i % 9) == 8)
	{
	  if (rand() % 100 > hints)
	    printf("  |\n");
	  else
	    printf(" %d|\n", src[i]);
	}
      else
	{
	  if (rand() % 100 > hints)
	    printf("  ");
	  else
	    printf(" %d", src[i]);
	}
    }
  printf("|------------------|\n");
}

void	caesar(char *src, int hints)
{
  int	i;
  int	offset;

  i = -1;
  offset = rand() % 9 + 1;
  while (++i < 81)
    src[i] = ((src[i] + offset) % 9) + 1;
  print_matrix(src, hints);
}
