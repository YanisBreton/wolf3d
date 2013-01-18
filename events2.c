/*
** events.c for events in /home/lecler_i//c/projets/fdf
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Dec  6 19:57:15 2012 thomas leclercq
** Last update Fri Jan 18 03:52:35 2013 thomas leclercq
*/

#include "wolf.h"

int	cast_ray(t_infos *infos, float angle)
{
  int	bool;
  t_vec	hor;
  t_vec	ver;
  t_vec vec;
  
  vec.distance = -1;
  hor.distance = hor_walls(infos->p_infos, infos->map, angle, &hor);
  ver.distance = ver_walls(infos->p_infos, infos->map, angle, &ver);
  bool = get_closer(hor.distance, ver.distance);
  vec = (bool == 1 ? hor : (bool == 2 ? ver : vec));
  return (vec.distance);
}

int	calc_pos(t_infos *infos, float move)
{
  int		x;
  int		y;
  t_p_infos	*p_infos;
  int		dist;

  if (infos->keys[KEY_SHIFT][1])
    move *= 1.5;
  p_infos = infos->p_infos;
  if (move < 0)
    {      
      if ((dist = cast_ray(infos, check_angle(p_infos->angle + 180))) < -move * 3)
	return (0);
      x = p_infos->x - (cos(RAD(p_infos->angle)) * move);
      y = p_infos->y + (sin(RAD(p_infos->angle)) * move);
    }
  else
    {      
      if ((dist = cast_ray(infos, p_infos->angle)) < move * 3)
	return (0);
      x = p_infos->x + (cos(RAD(p_infos->angle)) * -move);
      y = p_infos->y - (sin(RAD(p_infos->angle)) * -move);
    }
  p_infos->x = x;
  p_infos->y = y;
  return (1);
}

void	manage_keys(t_infos *infos)
{
  if (infos->keys[KEY_EXIT][1])
    my_exit(infos);
  if (infos->keys[KEY_LEFT][1])
    infos->p_infos->angle += (infos->keys[KEY_SHIFT][1] ? 4 : 2);
  if (infos->keys[KEY_RIGHT][1])
    infos->p_infos->angle -= (infos->keys[KEY_SHIFT][1] ? 4 : 2);
  if (infos->keys[KEY_UP][1])
    calc_pos(infos, 80);
  if (infos->keys[KEY_DOWN][1])
    calc_pos(infos, -25);
  if (infos->keys[KEY_SPACE][1] || infos->cur_weap_anim)
    shoot(infos);
  if (infos->keys[KEY_1][1])
    switch_weapon(infos, 0);
  if (infos->keys[KEY_2][1])
    switch_weapon(infos, 1);
    
}

void	mouse_move(t_xdisplay x_display)
{
  Window	root_window;

  root_window = XRootWindow(x_display.dpy, 0);
  XSelectInput(x_display.dpy, root_window, KeyReleaseMask);
  XWarpPointer(x_display.dpy, None, root_window, 0, 0, 0, 0, 532, 532);
  XFlush(x_display.dpy);
}

int     mouse_motion(int x, int y, t_infos *infos)
{
  /* printf("X : %d Y : %d\n", x, y); */
  if (x < P_X / 2)
    infos->p_infos->angle += (1);
  if (x > P_X / 2)
    infos->p_infos->angle -= (1);
}

int     mouse_event(int button, int x, int y, t_infos *infos)
{
  printf("BUTTON %d\n", button);
  if (button == 1)
    shoot(infos);
  if (button == 5)
    switch_weapon(infos, 1);
  if (button == 4)
    switch_weapon(infos, 0);
}

void	event(t_infos *infos)
{
  mouse_move(infos->x11_display);
  check_action(infos);
  manage_keys(infos);
  infos->p_infos->angle = check_angle(infos->p_infos->angle);
  draw_sky_floor(infos->img);
  balayage_walls(infos);
  refresh(infos);
}

void     refresh(t_infos *infos)
{
  mlx_put_image_to_window(infos->mlx_ptr,
			  infos->win->id, 
			  infos->img->img_ptr,
			  0, 0);
  mlx_put_image_to_window(infos->mlx_ptr,
  			  infos->win->id,
  			  infos->weapons[infos->p_infos->weapon]->img\
			  [infos->cur_weap_anim]->img_ptr,
  			  P_X / 2 - 124, P_Y - 256 - 117);
  mlx_put_image_to_window(infos->mlx_ptr,
  			  infos->win->id,
			  infos->ui->main->img_ptr,
  			  0, P_Y - 117);
  mlx_put_image_to_window(infos->mlx_ptr,
  			  infos->win->id,
  			  infos->weapons[infos->p_infos->weapon]->ui->img_ptr,
  			  P_X - 195, P_Y - 105);
  if (infos->action_possible)
    mlx_put_image_to_window(infos->mlx_ptr,
			    infos->win->id,
			    infos->ui->actions[0]->img_ptr,
			    P_X - 195, P_Y - 105);
  mlx_do_sync(infos->mlx_ptr);
}
