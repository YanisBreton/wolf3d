/*
** casting.c for wolf3d in /home/lecler_i/epitech/c/projets/wolf3d
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Tue Dec 18 12:51:43 2012 lecler_i
** Last update Sun Jan 13 19:23:06 2013 lecler_i
*/

#include "wolf.h"

int	dir(float angle, int bool)
{
  angle = check_angle(angle);
  if (bool == 1)
    {
      if (angle >= 180 && angle <= 360)
	return (UP);
      if (angle >= 0 && angle < 180)
	return (DOWN);
    }
  if (bool == 2)
    {
      if (angle >= 0 && angle < 90)
	return (LEFT);
      if (angle > 270 && angle <= 360)
	return (LEFT);
      if (angle >= 90 && angle <= 270)
	return (RIGHT);
    }
  return (angle);
}

int	calc_distance(t_p_infos *p_infos, int x, int y)
{
  int	distance;

  distance = ((p_infos->x - x) * (p_infos->x - x)); 
  distance += ((p_infos->y - y) * (p_infos->y - y));
  distance = sqrt(distance);
  return (distance);
}

int	calc_dist(t_infos *infos)
{
  return ((NB_CAST / 2) / tan(RAD(infos->p_infos->fov / 2)));
}
