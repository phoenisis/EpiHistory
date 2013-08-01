/*
** get_signal.c for  in /home/pidoux_q/
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Fri Nov 19 10:21:02 2010 quentin pidoux
** Last update Fri Nov 19 10:30:04 2010 quentin pidoux
*/

#include <signal.h>

void    sighup()
{
  execl("/usr/X11R6/bin/xlogo", "xlogo", 0);
}

int     main()
{
  signal(SIGHUP, sighup);
  while (1)
    pause();
}
