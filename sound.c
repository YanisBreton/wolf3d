/*
** sound.c for wolf3d in /home/lecler_i/epitech/c/projets/ok/fmod/fmodapi44404linux/examples/playstream
**
** Made by thomas leclercq
** Login   <lecler_i@epitech.net>
**
** Started on  Thu Jan 17 23:28:28 2013 thomas leclercq
** Last update Fri Jan 18 15:55:06 2013 thomas leclercq
*/

#include "wolf.h"
#include "sound/fmod/inc/fmod.h"
#include "sound/fmod/inc/fmod_errors.h"

void		ERRCHECK(FMOD_RESULT result)
{
  if (result != FMOD_OK)
    {
      printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
      /* my_printf("FAIL"); */
      exit(-1);
    }
}

FMOD_SOUND	*create_sound(FMOD_SYSTEM *system, char *path, int boucle)
{
  FMOD_SOUND       *sound;
  FMOD_RESULT       result;
  int               key;

  my_printf("Loading Sound : \"%s\" : ", path);
  FMOD_System_Init(&system, 1, FMOD_INIT_NORMAL, NULL);  

  if (boucle)
    result = FMOD_System_CreateSound(system, path,			\
  				     FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL,
  				     0,
  				     &sound);
  else
    result = FMOD_System_CreateSound(system, path,			\
  				     FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM,
  				     0,
  				     &sound);
  /* ERRCHECK(result); */
  my_printf("DONE\n");
  return (sound);
}


int		play_sound(FMOD_SYSTEM *system, FMOD_SOUND *sound)
{  
  FMOD_CHANNEL     *channel = 0;
  FMOD_RESULT	   result;

  result = FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, &channel);
  /* ERRCHECK(result); */
}
