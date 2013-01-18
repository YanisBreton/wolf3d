/*
** draw.c for draw in /home/lecler_i//c/projets/fdf
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Dec  6 19:40:48 2012 thomas leclercq
** Last update Sun Jan 13 18:42:06 2013 lecler_i
*/

#include "../wolf.h"

int	pos_in_img(t_img *img, int x, int y)
{
  int   i;

  if (x < img->w && x >= 0 && y < img->h && y >= 0)
    {
      i = (x * (img->bpp / 8)) + (y * img->sizeline);
    }
  else
    i = -1;
  return (i);
}

int	char_to_color(char *tab)
{
  int	color;

  color = tab[3] + 0;
  color <<= 8;
  color += tab[2] + 1;
  color <<= 8;
  color += tab[1] + 1;
  color <<= 8;
  color += tab[0] + 1;
  return (color);
}

void	my_pixel_put_to_image(t_img *img, int x, int y, int color)
{
  int   i;

  if ((i = pos_in_img(img, x, y)) != -1)
    {
      img->data[i] = color & 0xff;
      img->data[i + 1] = (color >> 8) & 0xff;
      img->data[i + 2] = (color >> 16) & 0xff;
      img->data[i + 3] = (color >> 24) & 0xff;
    }
}

void	draw_sky_floor(t_img *img)
{
  int	x;
  int	y;
  int	color;

  color = SKY;
  y = 0;
  while (y <= img->h)
    {
      if (y >= img->h / 2)
	color = FLOOR;
      x = 0;
      while (x < img->w)
        {
          my_pixel_put_to_image(img, x, y, color);
          x = x + 1;
        }
      y = y + 1;
    }
}
