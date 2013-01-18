/*
** walls.c for walls in /home/lecler_i/epitech/c/projets/wolf3d/draw
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Mon Jan  7 18:16:49 2013 lecler_i
** Last update Sun Jan 13 09:39:32 2013 lecler_i
*/

#include "../wolf.h"

t_sprites		*fill_sprites(t_p_infos *p_infos, t_vec *vec, t_block *block)
{
  static t_sprites     	*sprite;
  static t_sprites	*first;

  if (sprite)
    {
      sprite->next = xmalloc(sizeof(t_sprites));
      sprite = sprite->next;
    }
  else
    {
      sprite = xmalloc(sizeof(t_sprites));
      first = sprite;
    }
  sprite->block = block;
  sprite->distance = 0;
  sprite->next = NULL;
  return (sprite);
}

void	balayage_sprites(t_infos *infos)
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
      hor.distance = hor_sprites(infos->p_infos, infos->map, angle + infos->p_infos->angle, &hor);
      ver.distance = ver_sprites(infos->p_infos, infos->map, angle + infos->p_infos->angle, &ver);
      bool = get_closer(hor.distance, ver.distance);
      vec = (bool == 1 ? hor : (bool == 2 ? ver : vec));
      if (bool)
	{
	  vec.distance = vec.distance * cos(RAD(angle));
	  vec.nb = i;
	  calc_vec_infos(infos, &vec, bool, angle);
	  draw_sprites(infos, vec);
	}
      angle += ((float)60 / NB_CAST);
      i++;
    }
}

int	hor_sprites(t_p_infos *p_infos, t_map *map, float angle, t_vec *vec)
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
  while (map->tab[y/B_SIZE][x/B_SIZE]->wall != '3')
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
  return (calc_distance(p_infos, x, y) + (B_SIZE / 2));
}

int	ver_sprites(t_p_infos *p_infos, t_map *map, float angle, t_vec *vec)
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
  while (map->tab[y/B_SIZE][x/B_SIZE]->wall != '3')
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
  return (calc_distance(p_infos, x, y) + (B_SIZE / 2));
}

int	draw_sprites(t_infos *infos, t_vec vec)
{
  float	rap;
  int	i;
  t_block *block;

  block = vec.block;
  rap = P_X / NB_CAST;
  vec.distance = calc_distance(infos->p_infos, block->x, block->y);
  vec.height = B_SIZE / (float)vec.distance * calc_dist(infos);
  vec.height *= (P_X / NB_CAST);
  i = 0;
  while (i < (int)rap * (int)rap)
    {
      draw_sprites_col(infos, P_X - (vec.nb * rap + i), vec);
      i++;
    }
  return (1);
}

int	draw_sprites_col(t_infos *infos, int x, t_vec vec)
{
  t_img	*texture;
  t_img	*mask;
  float	y;
  int	ecart;
  int	i;
  float	rap_y;
  float	rap_x;
  int	pos;
  int	color;

  texture = vec.block->texture[vec.facing - UP]->img;
  rap_y = texture->h / (float)vec.height;
  rap_x = B_SIZE / texture->w;
  i = 0;
  y = 0;
  ecart = P_Y / 2 - ((vec.height) / 2);
  while (i < vec.height)
    {
      if (ecart + i >= 0)
      	{
	  pos = pos_in_img(texture, (int)(vec.offset / rap_x), (int)(y));
	  if (pos != -1)
	    color = char_to_color(&texture->data[pos]);
	  if (vec.offset >= 0)
	    {
	      if (color != -6750071 && color != -1)
		my_pixel_put_to_image(infos->img, x, ecart + i, color);
	    }	
	}
      y += rap_y;
      i++;
    }
}
