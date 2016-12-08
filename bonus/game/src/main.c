/*
** main.c for  in /home/planch_j/rendu/Info/flashlight_2020/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Feb 19 13:34:05 2016 Jean PLANCHER
** Last update Sun Feb 28 23:14:25 2016 Jean PLANCHER
*/

#include <math.h>
#include "my_bonus.h"

t_bunny_response	mouse_click(t_bunny_event_state state,
				    t_bunny_mousebutton button,
				    void *data)
{
  t_bunny_position	pos;
  t_struct		*b;

  b = (t_struct*)data;
  (void)b;
  pos = *bunny_get_mouse_position();
  if (state == GO_UP && button == BMB_LEFT)
      incr_case(b, &pos, 1);
  else if (state == GO_UP && button == BMB_RIGHT)
    incr_case(b, &pos, -1);
  return (GO_ON);
}

t_bunny_response	my_exit(t_bunny_event_state state,
				t_bunny_keysym key,
				void *data)
{
  t_bunny_position	pos;
  t_struct		*b;

  b = (t_struct*)data;
  (void)b;
  pos = *bunny_get_mouse_position();
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (state == GO_DOWN && key == BKS_C)
    b->is_printable[pos.y / (b->pix->clipable.clip_height / 9)]
  [pos.x / (b->pix->clipable.clip_width / 9)] =
  (check_same(b->grille, b->res_grille, pos.y /
	      (b->pix->clipable.clip_height / 9), pos.x /
	      (b->pix->clipable.clip_width / 9)));
  else if (state == GO_DOWN && key == BKS_RETURN)
    check_is_finish(b);
  return (GO_ON);
}

t_bunny_response	refresh_princeofbelair(void *a)
{
  t_struct		*b;
  int			i;

  b = (t_struct*)a;
  i = -1;
  while (++i < b->pix->clipable.clip_height * b->pix->clipable.clip_width - 1
	 && b->k == 0)
    {
      b->pos.x = i % b->pix->clipable.clip_height;
      b->pos.y = i / b->pix->clipable.clip_height;
      tekpixel(b->pix, &b->pos, BLACK);
    }
  i = 0;
  while (++i <= 81 && b->k == 0)
      load_case(b, i, (b->grille[(i - 1) % 9][(i - 1) / 9]));
  b->pos.x = 0;
  b->pos.y = 0;
  bunny_blit(&(b->win->buffer), &(b->pix->clipable), &(b->pos));
  bunny_display(b->win);
  return (GO_ON);
}

static void	destroy_windows(t_struct a)
{
  bunny_set_loop_main_function(&refresh_princeofbelair);
  bunny_set_key_response(&my_exit);
  bunny_set_click_response(&mouse_click);
  bunny_loop(a.win, 30, (void*)&a);
  if (a.music != NULL)
    {
      bunny_sound_stop(&a.music->sound);
      bunny_delete_sound(&a.music->sound);
    }
  bunny_stop(a.win);
  bunny_delete_clipable(&(a.pix->clipable));
}

int		main(int ac, char **av)
{
  t_struct	a;

  if (init_tabl(&a))
    return (0);
  a.k = 0;
  a.music = NULL;
  a.back = (ac > 1) ? bunny_load_pixelarray(av[1]) :
      bunny_load_pixelarray("img/carré2.png");
  a.lettre = bunny_load_pixelarray("img/nombres.png");
  if (a.lettre == NULL || a.back == NULL)
    return (0);
  a.square = bunny_new_pixelarray(SQUARE_SIZE, SQUARE_SIZE);
  fox_mod_stretch(a.square, a.back);
  a.nb = bunny_new_pixelarray(SQUARE_SIZE * 9, SQUARE_SIZE);
  fox_mod_stretch(a.nb, a.lettre);
  a.win = bunny_start_style(SQUARE_SIZE * 9 + ECART * 2,
			    SQUARE_SIZE * 9 + ECART * 2,
			    TITLEBAR | CLOSE_BUTTON, "Sudoku");
  a.pix = bunny_new_pixelarray(SQUARE_SIZE * 9 + ECART * 2,
			       SQUARE_SIZE * 9 + ECART * 2);
  destroy_windows(a);
  return (0);
}
