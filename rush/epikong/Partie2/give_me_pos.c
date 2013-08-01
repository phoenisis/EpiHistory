/*
** give_me_pos.c for  in /afs/epitech.net/users/all/pidoux_q/public/epikong/Partie1
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 18:39:33 2011 sevan hubert
** Last update Sat Mar 26 18:53:02 2011 sevan hubert
*/

#include "epikong.h"

int	posX(s_map *this, int pos)
{
  return (pos % this->sizeX);
}

int	posY(s_map *this, int pos)
{
  return (pos / this->sizeX);
}
