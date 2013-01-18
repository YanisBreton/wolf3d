/*
** walls.c for walls in /home/lecler_i/epitech/c/projets/wolf3d/draw
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Mon Jan  7 18:16:49 2013 lecler_i
** Last update Sun Jan 13 22:59:40 2013 lecler_i
*/

#include "../wolf.h"

void	balayage_walls(t_infos *infos)
{
  int	i;
  float	angle;
  int	bool;
  t_vec	hor;
  t_vec	ver;
  t_vec vec;

  angle = -30.0000;
  i = 0;
  while (angle < 30)
    {
      hor.distance = hor_walls(infos->p_infos, infos->map, angle + infos->p_infos->angle, &hor);
      ver.distance = ver_walls(infos->p_infos, infos->map, angle + infos->p_infos->angle, &ver);
      bool = get_closer(hor.distance, ver.distance);
      vec = (bool == 1 ? hor : (bool == 2 ? ver : vec));
      if (bool)
	{
	  vec.distance = vec.distance * cos(RAD(angle));
	  vec.nb = i;
	  calc_vec_infos(infos, &vec, bool, angle);
	  draw_walls(infos, vec);
	}
      angle += ((float)60 / NB_CAST);
      i++;
    }
}

int	hor_walls(t_p_infos *p_infos, t_map *map, float angle, t_vec *vec)
{
  int		y;
  int		x;
  int		ya;
  int		xa;

  y = (p_infos->y / B_SIZE) * (B_SIZE) + ((dir(angle, 1)) == UP ? -1 : B_SIZE);
  x = p_infos->x + ((p_infos->y - y) / tan(RAD(angle)));
  ya = ((dir(angle, 1) == UP) ? -(B_SIZE) : B_SIZE);
  xa = ya / -tan(RAD(angle));
  if ((x/B_SIZE < 0 || y/B_SIZE < 0 || x/B_SIZE >= map->w || y/B_SIZE >= map->h))
    return (-1);
  while (map->tab[y/B_SIZE][x/B_SIZE]->wall != '1' &&
	 map->tab[y/B_SIZE][x/B_SIZE]->wall != '2')
    {
      x = x + xa;
      y = y + ya;
      if ((x/B_SIZE < 0 || y/B_SIZE < 0 || x/B_SIZE >= map->w || y/B_SIZE >= map->h))
	return (-1);
    }
  vec->x = x;
  vec->y = y;
  vec->facing = dir(angle, 1);
  vec->block = map->tab[y/B_SIZE][x/B_SIZE];
  return (calc_distance(p_infos, x, y));
}

int	ver_walls(t_p_infos *p_infos, t_map *map, float angle, t_vec *vec)
{
  int		y;
  int		x;
  int		ya;
  int		xa;

  x = (p_infos->x / B_SIZE) * (B_SIZE) + (dir(angle, 2) == RIGHT ? B_SIZE : -1);
  y = p_infos->y + ((p_infos->x - x) * tan(RAD(angle)));
  xa = (dir(angle, 2) == RIGHT ? B_SIZE : -B_SIZE);
  ya = xa * -tan(RAD(angle));
  if ((x/B_SIZE < 0 || y/B_SIZE < 0 || x/B_SIZE >= map->w || y/B_SIZE >= map->h))
    return (-1);
  while (map->tab[y/B_SIZE][x/B_SIZE]->wall != '1' &&
	 map->tab[y/B_SIZE][x/B_SIZE]->wall != '2')
    {
      x = x + xa;
      y = y + ya;
      if ((x/B_SIZE < 0 || y/B_SIZE < 0 || x/B_SIZE >= map->w || y/B_SIZE >= map->h))
	return (-1);
    }
  vec->x = x;
  vec->y = y;
  vec->facing = dir(angle, 2);
  vec->block = map->tab[y/B_SIZE][x/B_SIZE];
  return (calc_distance(p_infos, x, y));
}

int	draw_walls(t_infos *infos, t_vec vec)
{
  float	rap;
  int	i;
  t_draw	inf;

  rap = P_X / NB_CAST;
  vec.height = B_SIZE / (float)vec.distance * calc_dist(infos);
  vec.height *= (P_X / NB_CAST);
  i = 0;
  while (i < (int)rap)
    {
      inf.texture = vec.block->texture[vec.facing - UP]->img;
      if (vec.block->mask[vec.facing - UP])
	inf.mask = vec.block->mask[vec.facing - UP]->img;
      else
	inf.mask = inf.texture;
      inf.rap_y = inf.mask->h / (float)vec.height;
      inf.rap_x = B_SIZE / inf.mask->w;
      inf.ecart = P_Y / 2 - ((vec.height) / 2);
      draw_walls_col(infos, P_X - (vec.nb * rap + i), vec, inf);
      i++;
    }
  return (1);
}

int	draw_walls_col(t_infos *infos, int x, t_vec vec, t_draw inf)
{
  float	y;
  int	i;
  int	pos;
  int	color;

  i = 0;
  y = 0;
  while (i < vec.height && inf.ecart + i <= infos->img->h)
    {
      if (inf.ecart + i >= 0)
      	{
	  if ((pos = pos_in_img(inf.texture, (int)(vec.offset / inf.rap_x), (int)(y))) != -1)
	    color = char_to_color(&inf.mask->data[pos]);
	  if (vec.offset >= 0)
	    {
	      if ((color == -6750071 || color == -1) && pos != -1)
		color = char_to_color(&inf.texture->data[pos]);
	      if (color != -6750071 && color != -1)
		my_pixel_put_to_image(infos->img, x, inf.ecart + i, color);
	    }	
	}
      y += inf.rap_y;
      i++;
    }
}

