/*
** free.c for free in /home/lecler_i/epitech/c/projets/wolf3d
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Sun Dec 16 19:18:37 2012 lecler_i
** Last update Fri Jan 18 02:33:17 2013 thomas leclercq
*/

#include "wolf.h"

void	free_map(t_map *map)
{
  int	y;
  int	x;

  y = 0;
  while (map->tab[y])
    {
      x = 0;
      while (map->tab[y][x])
	{
	  free(map->tab[y][x]->str);
	  free(map->tab[y][x]);
	  x++;
	}
      free(map->tab[y]);
      y++;
    }
  free(map->tab);
  free(map->path);
  free(map);
}

void	free_win(t_win *win)
{
  free(win->name);
  free(win);
}

void	free_img(t_img *img)
{
  free(img);
}

void	free_p_infos(t_p_infos *p_infos)
{
  free(p_infos);
}

void	my_exit(t_infos *infos)
{
  write(1, "Lets free() all this shit !\n", 28);
  /* mlx_destroy_window(infos->mlx_ptr, infos->win->id); */
  /* free_map(infos->map); */
  /* free_win(infos->win); */
  /* free_img(infos->img); */
  /* free_p_infos(infos->p_infos); */
  /* free(infos); */
  exit(1);
}
