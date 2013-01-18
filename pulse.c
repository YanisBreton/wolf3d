/*
** pulse.c for pulse in /home/lecler_i/epitech/c/projets/wolf3d
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Fri Jan 11 12:53:47 2013 lecler_i
** Last update Fri Jan 18 03:31:54 2013 thomas leclercq
*/

#include "wolf.h"
#include "mlx_int.h"

extern int	(*(mlx_int_param_event[]))();

int		key_press(int keycode, t_infos *infos)
{
  int	i;

  i = 0;
  while (infos->keys[i][0])
    {
      if (infos->keys[i][0] == keycode)
	{
	  infos->keys[i][1] = 1;
	  return (i);
	}
      i++;
    }
  return (0);
}

int		key_release(int keycode, t_infos *infos)
{
  int	i;

  i = 0;
  while (infos->keys[i][0])
    {
      if (infos->keys[i][0] == keycode)
	{
	  infos->keys[i][1] = 0;
	  return (i);
	}
      i++;
    }
  return (0);
}

int		mlx_key_pulse_press(t_win_list *win,int (*funct)(),void *param)
{
  win->hooks[KeyPress].hook = funct;
  win->hooks[KeyPress].param = param;
  win->hooks[KeyPress].mask = KeyPressMask;
}

int		mlx_key_pulse_release(t_win_list *win,int (*funct)(),void *param)
{
  win->hooks[KeyRelease].hook = funct;
  win->hooks[KeyRelease].param = param;
  win->hooks[KeyRelease].mask = KeyReleaseMask;
}

int		mlx_mouse_motion(t_win_list *win,int (*funct)(),void *param)
{
  win->hooks[MotionNotify].hook = funct;
  win->hooks[MotionNotify].param = param;
  win->hooks[MotionNotify].mask = PointerMotionMask;
}

long		getTicks()
{
  long			ticks;
  struct timeval	now;

  gettimeofday(&now, NULL);
  ticks = now.tv_sec * 1000l;
  ticks += now.tv_usec / 1000l;
  return (ticks);
}
