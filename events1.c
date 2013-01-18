/*
** events.c for events in /home/lecler_i//c/projets/fdf
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Dec  6 19:57:15 2012 thomas leclercq
** Last update Sun Jan 13 21:49:25 2013 lecler_i
*/

#include "wolf.h"

float	check_angle(float angle)
{
  if (angle < 0)
    angle += 360;
  if (angle > 360)
    angle -= 360;
  return (angle);
}

void	calc_vec_infos(t_infos *infos, t_vec *vec, int type, float angle)
{
  vec->angle = angle + infos->p_infos->angle;  
  if (type == 1)
    vec->offset = vec->x % B_SIZE;
  if (type == 2)
    vec->offset = vec->y % B_SIZE;
  if (type == 3)
    vec->offset = 0;
}

int	get_closer(int a, int b)
{
  int	bool;

  if (a == -1 && b == -1)
    bool = 0;
  else if (a != -1 && b == -1)
    bool = 1;
  else if (a == -1 && b != -1)
    bool = 2;
  else if (a <= b)
    bool = 1;
  else
    bool = 2;
  return (bool);
}

int	check_action(t_infos *infos)
{
  int	bool;
  t_vec	hor;
  t_vec	ver;
  t_vec vec;
  
  hor.distance = hor_walls(infos->p_infos, infos->map, infos->p_infos->angle, &hor);
  ver.distance = ver_walls(infos->p_infos, infos->map, infos->p_infos->angle, &ver);
  bool = get_closer(hor.distance, ver.distance);
  vec = (bool == 1 ? hor : (bool == 2 ? ver : vec));
  if (bool && vec.distance <= B_SIZE * 1.2 && vec.block->y_tp != 0 &&
      vec.block->x_tp != 0 && vec.block->wall == '2')
    {
      infos->action_possible = 1;
      if (infos->keys[KEY_ACTION][1])
	{
	  infos->p_infos->x = vec.block->x_tp * B_SIZE + (B_SIZE / 2);
	  infos->p_infos->y = vec.block->y_tp * B_SIZE + (B_SIZE / 2);
	}
    }
  else
    infos->action_possible = 0;
}
