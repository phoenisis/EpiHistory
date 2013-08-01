//
// Head.cpp for Haed in /home/hubert_s//nibbler-2014-pidoux_q
// 
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
// 
// Started on  Mon Mar  7 13:28:14 2011 sevan hubert
// Last update Sat Mar 19 12:17:25 2011 sevan hubert
//

#include <cstdlib>
#include <fstream>
#include "Snake.hh"
#include "Head.hh"
#include "Map.hh"

Head::Head(Map const &m)
  : Snake(m.getSizeX() / 2, m.getSizeY() / 2)
{
  this->direction = RIGHT;
  init_highscore();
  this->score = 0;
  this->apple_eat = 0;
}


Head::~Head()
{
  save_highscore();
}


void	Head::setDir(int dir)
{
  if (dir >= 0 && dir <= 3 &&
      !((this->direction == LEFT && dir == RIGHT)
       || (this->direction == RIGHT && dir == LEFT)
       || (this->direction == UP && dir == DOWN)
       || (this->direction == DOWN && dir == UP)))
    this->direction = dir;
}


bool	Head::has_snap()
{
  Snake	*verif = this->next;

  while (verif != NULL)
    {
      if (verif->getPosX() == this->posx && verif->getPosY() == this->posy)
	return true;
      verif = verif->getNext();
    }
  return false;
}


bool	Head::is_out(Map const &M)
{
  if ((this->posx < 0) || (this->posx >= M.getSizeX())
      || (this->posy < 0) || (this->posy >= M.getSizeY()))
    return true;
  else
    return false;
}


static void	m_right(Head *hd)
{
  hd->setPosY(hd->getPosY() + 1);
}


static void	m_left(Head *hd)
{
  hd->setPosY(hd->getPosY() - 1);
}


static void	m_up(Head *hd)
{
  hd->setPosX(hd->getPosX() - 1);
}


static void	m_down(Head *hd)
{
  hd->setPosX(hd->getPosX() + 1);
}

static void	(*move_dir[])(Head *hd) =
    {&m_down, &m_up, &m_left, &m_right};


void	Head::move()
{
  this->next->move_tail(this->posx, this->posy);
  move_dir[this->direction](this);
  if (this->score > 0)
    this->score--;
}


static bool	pop_left(Head *hd, Snake *tail, Map const &M)
{
  if (M.case_is_free(tail->getPosX(), tail->getPosY() - 1, *hd))
    {
      tail->getNext()->setPosY(tail->getPosY() - 1);
      tail->getNext()->setPosX(tail->getPosX());
      return true;
    }
  return false;
}


static bool	pop_up(Head *hd, Snake *tail, Map const &M)
{
  if (M.case_is_free(tail->getPosX() - 1, tail->getPosY(), *hd))
    {
      tail->getNext()->setPosY(tail->getPosY());
      tail->getNext()->setPosX(tail->getPosX() - 1);
      return true;
    }
  return false;
}


static bool	pop_right(Head *hd, Snake *tail, Map const &M)
{
  if (M.case_is_free(tail->getPosX(), tail->getPosY() + 1, *hd))
    {
      tail->getNext()->setPosY(tail->getPosY() + 1);
      tail->getNext()->setPosX(tail->getPosX());
      return true;
    }
  return false;
}


static bool	pop_down(Head *hd, Snake *tail, Map const &M)
{
  if (M.case_is_free(tail->getPosX() + 1, tail->getPosY(), *hd))
    {
      tail->getNext()->setPosY(tail->getPosY());
      tail->getNext()->setPosX(tail->getPosX() + 1);
      return true;
    }
  return false;
}


static bool	(*pop_tail[])(Head *hd, Snake *tail, Map const &M) =
{&pop_down, &pop_up, &pop_left, &pop_right};


void	Head::grown_up(Map const &M)
{
  Snake	*grow = this;
  Snake	*new_case = new Snake(-1, -1, 0);
  int	i = 0;

  while (grow->getNext() != NULL)
    grow = grow->getNext();
  grow->setNext(new_case);
  while (i < 4 && !(pop_tail[i](this, grow, M)))
    i++;
  i = 0;
  if (new_case->getPosX() == -1)
    {
      this->move();
      while (i < 4 && !(pop_tail[i](this, grow, M)))
	i++;
    }
  this->apple_eat++;
  this->score += 50 + this->apple_eat;
}


int	Head::get_score() const
{
  return(this->score);
}


int	Head::get_apple_eat() const
{
  return(this->apple_eat);
}


int	Head::get_highscore() const
{
  return(this->highscore);
}


void	Head::set_highscore(int n)
{
  if (n > this->highscore)
    this->highscore = n;
}


void	Head::init_highscore()
{
  int length;
  char * buffer;

  int des;

  std::fstream file;

  file.open("score", std::fstream::in | std::fstream::out | std::fstream::app);

  file.seekg (0, std::ios::end);
  length = file.tellg();
  file.seekg (0, std::ios::beg);

  buffer = new char [length];

  file.read (buffer,length);
  file.close();

  des = atoi(buffer);
  this->highscore = des;

  delete[] buffer;
}

void	Head::save_highscore()
{
  FILE * file;
  
  file = fopen ("score", "w");
  fprintf (file, "%d\n",this->highscore);

  fclose (file);
}
