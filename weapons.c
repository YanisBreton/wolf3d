/*
** initialization.c for wolf3d in /home/lecler_i/epitech/c/projets/wolf3d
**
** Made by lecler_i
** Login   <lecler_i@epitech.net>
**
** Started on  Tue Dec 18 11:26:50 2012 lecler_i
** Last update Fri Jan 18 15:39:26 2013 thomas leclercq
*/

#include "wolf.h"

t_img           *create_texture_img(void *mlx_ptr, char *path);

t_weapon		*create_pistol(t_infos *infos)
{
  t_weapon	*weapon;
  void		*mlx_ptr;

  mlx_ptr = infos->mlx_ptr;
  weapon = xmalloc(sizeof(t_weapon));
  weapon->id = 1;
  weapon->ammo = 8;
  weapon->img[0] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/pistol0.xpm");
  weapon->img[1] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/pistol1.xpm");
  weapon->img[2] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/pistol2.xpm");
  weapon->img[3] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/pistol3.xpm");
  weapon->img[4] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/pistol4.xpm");
  weapon->img[5] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/pistol5.xpm");
  weapon->img[6] = NULL;
  weapon->ui = create_texture_img(mlx_ptr,
				  "texture/xpm/ui/weapons/pistol_ui.xpm");
  weapon->use_sound = create_sound(infos->system_sound, "sound/wolf_sounds/weapons/pistol.mp3", 0);
  weapon->switch_sound = create_sound(infos->system_sound, "sound/wolf_sounds/weapons/switch_to_pistol.mp3", 0);
  return (weapon);
}

t_weapon		*create_knife(t_infos *infos)
{
  t_weapon	*weapon;
  void		*mlx_ptr;

  mlx_ptr = infos->mlx_ptr;
  weapon = xmalloc(sizeof(t_weapon));
  weapon->id = 0;
  weapon->ammo = 0;
  weapon->img[0] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/knife0.xpm");
  weapon->img[1] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/knife1.xpm");
  weapon->img[2] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/knife2.xpm");
  weapon->img[3] = create_texture_img(mlx_ptr,
				      "texture/xpm/ui/weapons/knife3.xpm");
  weapon->img[4] = NULL;
  weapon->ui = create_texture_img(mlx_ptr,
				  "texture/xpm/ui/weapons/knife_ui.xpm");
  weapon->use_sound = create_sound(infos->system_sound, "sound/wolf_sounds/weapons/knife.mp3", 0);
  weapon->switch_sound = create_sound(infos->system_sound, "sound/wolf_sounds/weapons/switch_to_knife.mp3", 0);
  return (weapon);
}

void			*create_weapons(t_infos *infos)
{
  infos->weapons[0] = create_knife(infos);
  infos->weapons[1] = create_pistol(infos);
  infos->weapons[2] = NULL;
}

int			shoot(t_infos *infos)
{
  static long		cooldown_time;
  static long		old_time;
  long			time;
  static int		sound;

  time = getTicks();
  if (time - cooldown_time < 600 && infos->cur_weap_anim == 0)
    return (0);
  if (!sound)
    play_sound(infos->system_sound, infos->weapons[infos->p_infos->weapon]->use_sound);
  sound = 1;
  if (infos->cur_weap_anim == 0)
    infos->cur_weap_anim++;
  cooldown_time = time;
  if (time - old_time > 80 && infos->cur_weap_anim != 0)
    {
      if (!infos->weapons[infos->p_infos->weapon]->img[infos->cur_weap_anim + 1])
  	{
	  infos->cur_weap_anim = 0;
	  sound = 0;
	}
      else
  	infos->cur_weap_anim++;
      old_time = time;
    }
}

int		switch_weapon(t_infos *infos, int weapon)
{
  static long		cooldown_time;
  long			time;

  time = getTicks();
  if (time - cooldown_time < 200 && infos->cur_weap_anim == 0)
    return (0);
  if (infos->cur_weap_anim == 0)
    {
      if (weapon != infos->p_infos->weapon)
	play_sound(infos->system_sound, infos->weapons[infos->p_infos->weapon]->switch_sound);
      infos->p_infos->weapon = weapon;
      cooldown_time = time;
    }
}
