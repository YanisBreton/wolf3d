/*
** initialization.c for wolf3d in /home/lecler_i/epitech/c/projets/wolf3d
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Tue Dec 18 11:26:50 2012 lecler_i
** Last update Sun Jan 13 19:59:15 2013 lecler_i
*/

#include "wolf.h"

t_win		*create_win(void *mlx_ptr, int width, int height, char *name)
{
  t_win			*win;

  win = xmalloc(sizeof(t_win));
  win->name = my_strdup(name);
  win->id = mlx_new_window(mlx_ptr, width, height, name);
  win->w = width;
  win->h = height;
  return (win);
}

t_img		*create_img(void *mlx_ptr, int width, int height)
{
  t_img			*img;

  img = xmalloc(sizeof(t_img));
  img->img_ptr = mlx_new_image(mlx_ptr, width, height);
  img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->sizeline, &img->endian);
  img->w = width;
  img->h = height;
  return (img);
}

t_img		*create_texture_img(void *mlx_ptr, char *path)
{
  t_img			*img;
  
  my_printf("Chargement de texture : \"%s\" : ", path);
  img = xmalloc(sizeof(t_img));
  if (!(img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img->w, &img->h)))
    {
      my_printf("FAIL\n");
      exit (0);
    }
  img->data = mlx_get_data_addr(img->img_ptr,
				&img->bpp,
				&img->sizeline,
				&img->endian);
  my_printf("DONE\n");
  return (img);
}

t_texture		*create_texture(void *mlx_ptr, char alias, char *path)
{
  static t_texture	*texture;
  static t_texture	*first;

  if (texture)
    {
      texture->next = xmalloc(sizeof(t_texture));
      texture = texture->next;
    }
  else
    {
      texture = xmalloc(sizeof(t_texture));
      first = texture;
    }
  texture->alias = alias;
  texture->path = path;
  texture->img = create_texture_img(mlx_ptr, path);
  texture->next = NULL;
  return (texture);
}
