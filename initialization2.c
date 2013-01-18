/*
** initialization.c for wolf3d in /home/lecler_i/epitech/c/projets/wolf3d
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Tue Dec 18 11:26:50 2012 lecler_i
** Last update Fri Jan 18 18:19:35 2013 thomas leclercq
*/

#include "wolf.h"

void			fill_key(t_infos *infos)
{
  infos->keys[KEY_UP][0] = 119;
  infos->keys[KEY_DOWN][0] = 115;
  infos->keys[KEY_LEFT][0] = 97;
  infos->keys[KEY_RIGHT][0] = 100;
  infos->keys[KEY_ACTION][0] = 102;
  infos->keys[KEY_SPACE][0] = 32;
  infos->keys[KEY_EXIT][0] = 65307;
  infos->keys[KEY_SHIFT][0] = 65505;
  infos->keys[KEY_1][0] = 49;
  infos->keys[KEY_2][0] = 50;
  infos->keys[KEY_UP][1] = 0; 
  infos->keys[KEY_DOWN][1] = 0; 
  infos->keys[KEY_LEFT][1] = 0; 
  infos->keys[KEY_RIGHT][1] = 0; 
  infos->keys[KEY_ACTION][1] = 0; 
  infos->keys[KEY_SPACE][1] = 0; 
  infos->keys[KEY_EXIT][1] = 0;
  infos->keys[KEY_SHIFT][1] = 0;
  infos->keys[KEY_1][1] = 0;
  infos->keys[KEY_2][1] = 0;
  infos->keys[13][0] = 0;
  infos->keys[13][1] = 0;
}

t_interface		*create_interface(void *mlx_ptr)
{
  t_interface   	*ui;

  ui = xmalloc(sizeof(t_interface));
  ui->actions[0] = create_texture_img(mlx_ptr, "texture/xpm/ui/action.xpm");
  ui->main = create_texture_img(mlx_ptr, "texture/xpm/ui/ui.xpm");
  ui->load = create_texture_img(mlx_ptr, "texture/xpm/ui/load.xpm");
  return (ui);
}

t_infos		*create_infos(char **argv)
{
  t_infos		*infos;

  infos = xmalloc(sizeof(t_infos));
  infos->mlx_ptr = mlx_init();
  fill_key(infos);
  infos->win = NULL;
  infos->img = NULL;
  infos->map = NULL;
  infos->cur_weap_anim = 0;
  return (infos);
}

t_p_infos	*create_p_infos(t_infos *infos)
{
  t_p_infos		*p_infos;

  p_infos = xmalloc(sizeof(t_p_infos));
  p_infos->y = 1 * B_SIZE + (B_SIZE / 2);
  p_infos->x = 1 * B_SIZE;
  p_infos->angle = 0;
  p_infos->height = 0.5;
  p_infos->fov = 60;
  p_infos->weapon = 1;
  return (p_infos);
}
