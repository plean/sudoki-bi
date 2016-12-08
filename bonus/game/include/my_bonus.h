/*
** my_bonus.h for  in /home/planch_j/rendu/CPE/sudoki-bi/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Feb 28 20:24:51 2016 Jean PLANCHER
** Last update Sun Feb 28 22:23:25 2016 Jean PLANCHER
*/

#ifndef MY_BONUS_H_
# define MY_BONUS_H_

# include <lapin.h>
# include "sudoku.h"

# define HEIGHT 1000
# define WIDTH 1400
# define SQUARE_SIZE 100
# define ECART 10

typedef struct		s_struct
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*lettre;
  t_bunny_pixelarray	*nb;
  t_bunny_pixelarray	*back;
  t_bunny_pixelarray	*square;
  t_bunny_music		*music;
  t_bunny_position	pos;
  unsigned char		grille[9][9];
  unsigned char		res_grille[9][9];
  unsigned char		is_printable[9][9];
  int			k;
}			t_struct;

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int	color);
int		fox_calc_pos(int x, int y, t_bunny_pixelarray *pix);
void		fox_mod_stretch(t_bunny_pixelarray *pix,
				t_bunny_pixelarray *ori);
void		tekfull(t_struct *t);
unsigned int	interpol(unsigned int a, unsigned int b);
void		load_case(t_struct *b,
			  int n, int e);
void		incr_case(t_struct *a,
			  t_bunny_position *pos,
			  char c);
int		check_same(unsigned char grille[9][9],
			   unsigned char res_grille[9][9],
			   int y, int x);
int		init_tabl(t_struct *a);
void		check_is_finish(t_struct *b);
int		fox_load_music(t_bunny_music *music,
			       char *filepath, int volume);

#endif /* !MY_BONUS_H_ */
