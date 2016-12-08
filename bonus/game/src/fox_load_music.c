/*
** fox_load_music.c for Fox Load Music in /home/mei/GitHub/LibMcCloud/fox
**
** Made by Michel Mancier
** Login   <mancie_m@epitech.net>
**
** Started on  Mon Dec 28 16:03:24 2015 Michel Mancier
** Last update Sun Feb 28 22:22:02 2016 Jean PLANCHER
*/

#include "my_bonus.h"

int	fox_load_music(t_bunny_music *music, char *filepath, int volume)
{
  if ((music = bunny_load_music(filepath)) == NULL)
    return (-1);
  bunny_sound_volume(&music->sound, volume);
  bunny_sound_loop(&music->sound, 1);
  bunny_sound_play(&music->sound);
  return (0);
}
