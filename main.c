  /*
** main.c for main fdf in /home/lecler_i//c/projets/fdf
** 
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
** 
** Started on  Thu Dec  6 18:23:58 2012 thomas leclercq
** Last update Fri Jan 18 23:04:28 2013 thomas leclercq
*/

#include "wolf.h"

void	load_textures(t_infos *infos)
{
  infos->texture = create_texture(infos->mlx_ptr, '0', "texture/xpm/walls/0.xpm");
  create_texture(infos->mlx_ptr, '1', "texture/xpm/walls/1.xpm");
  create_texture(infos->mlx_ptr, '2', "texture/xpm/walls/2.xpm");
  create_texture(infos->mlx_ptr, '3', "texture/xpm/walls/3.xpm");
  create_texture(infos->mlx_ptr, '4', "texture/xpm/walls/4.xpm");
  create_texture(infos->mlx_ptr, '5', "texture/xpm/walls/5.xpm");
  create_texture(infos->mlx_ptr, '6', "texture/xpm/walls/6.xpm");
  create_texture(infos->mlx_ptr, '7', "texture/xpm/walls/7.xpm");
  create_texture(infos->mlx_ptr, '8', "texture/xpm/walls/8.xpm");
  create_texture(infos->mlx_ptr, '9', "texture/xpm/walls/9.xpm");  
  create_texture(infos->mlx_ptr, 'a', "texture/xpm/decoration/a.xpm");
  create_texture(infos->mlx_ptr, 'b', "texture/xpm/decoration/b.xpm");
  create_texture(infos->mlx_ptr, 'c', "texture/xpm/decoration/c.xpm");
  create_texture(infos->mlx_ptr, 'd', "texture/xpm/decoration/d.xpm");
  create_texture(infos->mlx_ptr, 'e', "texture/xpm/decoration/e.xpm");
  create_texture(infos->mlx_ptr, 'f', "texture/xpm/decoration/f.xpm");
  create_texture(infos->mlx_ptr, 'g', "texture/xpm/decoration/g.xpm");
  create_texture(infos->mlx_ptr, 'h', "texture/xpm/decoration/h.xpm");
  create_texture(infos->mlx_ptr, 'i', "texture/xpm/decoration/i.xpm");
  create_texture(infos->mlx_ptr, 'j', "texture/xpm/decoration/j.xpm");
  create_texture(infos->mlx_ptr, 'k', "texture/xpm/decoration/k.xpm");
}

void	load_textures2(t_infos *infos)
{
  create_texture(infos->mlx_ptr, 'l', "texture/xpm/decoration/l.xpm");
  create_texture(infos->mlx_ptr, 'm', "texture/xpm/decoration/m.xpm");
  create_texture(infos->mlx_ptr, 'n', "texture/xpm/decoration/n.xpm");
  create_texture(infos->mlx_ptr, 'o', "texture/xpm/decoration/o.xpm");
  create_texture(infos->mlx_ptr, 'p', "texture/xpm/decoration/p.xpm");
  create_texture(infos->mlx_ptr, 'q', "texture/xpm/decoration/q.xpm");
  create_texture(infos->mlx_ptr, 'r', "texture/xpm/decoration/r.xpm");
  create_texture(infos->mlx_ptr, 's', "texture/xpm/decoration/s.xpm");

  create_texture(infos->mlx_ptr, 'A', "texture/xpm/objects/A.xpm");
  create_texture(infos->mlx_ptr, 'B', "texture/xpm/objects/B.xpm");
  create_texture(infos->mlx_ptr, 'C', "texture/xpm/objects/C.xpm");
  create_texture(infos->mlx_ptr, 'D', "texture/xpm/objects/D.xpm");
  create_texture(infos->mlx_ptr, 'E', "texture/xpm/objects/E.xpm");
  create_texture(infos->mlx_ptr, 'F', "texture/xpm/objects/F.xpm");
  create_texture(infos->mlx_ptr, 'G', "texture/xpm/objects/G.xpm");
  create_texture(infos->mlx_ptr, 'I', "texture/xpm/objects/I.xpm");
  create_texture(infos->mlx_ptr, 'J', "texture/xpm/objects/J.xpm");
}

int	wolf(int argc, char **argv)
{
  t_infos	*infos;
  FMOD_SOUND	*bg_sound;
  
  infos = create_infos(argv);

  FMOD_System_Create(&infos->system_sound);
  FMOD_System_Init(&infos->system_sound, 1, FMOD_INIT_NORMAL, NULL);  

  infos->win = create_win(infos->mlx_ptr, P_X, P_Y, "Wolf3D Ok Sans Sprites");
  infos->img = create_img(infos->mlx_ptr, P_X, P_Y);
  infos->ui = create_interface(infos->mlx_ptr);
  load_textures(infos);
  load_textures2(infos);
  infos->p_infos = create_p_infos(infos);  
  infos->map = pars_map(argv[1], infos);
  create_weapons(infos);
  

  
  bg_sound = create_sound(infos->system_sound, "sound/wolf_sounds/pilgrimage_march.ogg", 1);
  play_sound(infos->system_sound, bg_sound);


  infos->x11_display.dpy = XOpenDisplay(0);
  mlx_key_pulse_press(infos->win->id, &key_press, infos);
  mlx_key_pulse_release(infos->win->id, &key_release, infos);
  mlx_mouse_motion(infos->win->id, &mouse_motion, infos);
  mlx_mouse_hook(infos->win->id, &mouse_event, infos);
  mlx_expose_hook(infos->win->id, &refresh, infos);
  mlx_loop_hook(infos->mlx_ptr, &event, infos);
  mlx_loop(infos->mlx_ptr);
  return (1);
}
int	main(int argc, char **argv, char **env)
{
  if (!env[0])
    {
      my_putstr("C'est pas tres gentil tout ca...\n");
      return (0);
    }
  if (argc <= 1)
    {
      my_putstr("Correct Syntax : ./wolf3d [Map]...\n");
      exit(0);
    }
  else
    {
      wolf(argc, argv);
    }
  return (0);
}
