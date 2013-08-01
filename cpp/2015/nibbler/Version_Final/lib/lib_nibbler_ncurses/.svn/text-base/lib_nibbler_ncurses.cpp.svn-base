
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <list>
#include "Case.hpp"
#include "toDisplay.hpp"
#include "CExceptions.hpp"
#include "Nibbler.hpp"
#include "lib_nibbler_ncurses.hpp"

/*
**  CTOR & DTOR
*/

NCurses::NCurses(size_t nbCaseW, size_t nbCaseH)
  : _caseWidth(16), _caseHeight(16), _speed(50000), _end(false), _gameOver(false)
{
  this->_scrWidth = this->_caseWidth * nbCaseW;
  this->_scrHeight = this->_caseHeight * nbCaseH;
}

NCurses::~NCurses()
{
  endwin();
}

/*
** Getter's screen and case
*/

int		NCurses::getScrWidth() const
{
  return this->_scrWidth;
}

int		NCurses::getScrHeight() const
{
  return this->_scrHeight;
}

size_t		NCurses::getCaseWidth() const
{
  return this->_caseWidth;
}

size_t		NCurses::getCaseHeight() const
{
    return this->_caseHeight;
}

/*
** Fonction de gestion de l'affichage
*/

void		NCurses::init(int, char **)
{
  WINDOW	*screen;

  initscr();
  raw();

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(10, COLOR_WHITE, COLOR_GREEN);
  init_pair(11, COLOR_BLACK, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  init_pair(3, COLOR_BLACK, COLOR_RED);
  init_pair(4, COLOR_BLACK, COLOR_BLUE);
  init_pair(5, COLOR_BLACK, COLOR_CYAN);
  curs_set(0);

  noecho(); 
  keypad(stdscr, TRUE);

  screen = newwin(this->_scrWidth, this->_scrHeight * 2, 0, 0);
  this->_screen = screen;
  wbkgd(this->_screen, COLOR_PAIR(1));
  wrefresh(this->_screen);
  refresh();
}

/*
** Affichage des objets displayable
*/

void		NCurses::display(std::list<toDisplay *> const& data)
{
  std::list<toDisplay *>::const_iterator	it;
  
  for (it = data.begin(); it != data.end(); ++it)
    (*it)->display();
}

/*
** Affichage sur screen
*/

void		NCurses::putOnScreen(Case const * const cs)
{
  WINDOW	*newCase;
  
  newCase = subwin(this->_screen, 1, 2, cs->getY() / 16, cs->getX() * 2 / 16);
  if (cs->getType() == GRASS)
    wbkgd(newCase, COLOR_PAIR(2));
  if (cs->getType() == FRUIT)
    wbkgd(newCase, COLOR_PAIR(3));
  if (cs->getType() == SNAKE_HEAD)
    wbkgd(newCase, COLOR_PAIR(4));
  if (cs->getType() == SNAKE_BODY)
    wbkgd(newCase, COLOR_PAIR(5));
  delwin(newCase);
}

/*
** Affichage du score
*/

void			NCurses::displayScore(Player const * const p)
{
  WINDOW		*score;

  score = subwin(this->_screen, 1, 5, 0, 0);
  wprintw(score, " %d ", p->getScore());
  wbkgd(score, COLOR_PAIR(10));
  delwin(score);
}

/*
** Deplacement et demarrage du serpent
*/

void		NCurses::moveAndFlip(Player *player, direction dir)
{
  player->move(dir);
  if (!this->_gameOver)
    displayScore(player);
  wrefresh(this->_screen);
  refresh();
  usleep(this->_speed);
}

/*
** loop du game
*/

void		NCurses::mainLoop(Player* player)
{
  int		ch;
  direction	dir;

  while (!this->_end)
    {
      dir = FORWARD;
      nodelay(stdscr, TRUE);
      ch = getch();
      switch(ch)
	{
	case KEY_ESCAPE:
	  this->_end = true;
	  break;
	case KEY_RETURN:
	  if (this->_gameOver == true)
	    {
	      WINDOW	*over;
	      
	      over = subwin(this->_screen, 10, 30, 0, 0);
	      wprintw(over, "\n\n\n\n", this->_score);
	      wbkgd(over, COLOR_PAIR(11));
	      delwin(over);

	      player->reset();
	      this->_gameOver = false;
	      this->_speed = 50000;
	    }
	  break;
	case KEY_LEFT:
	  if (player->getDirection() != RIGHT)
	    dir = LEFT;
	  break;
	case KEY_RIGHT:
	  if (player->getDirection() != LEFT)
	    dir = RIGHT;
	  break;
	case KEY_UP:
	  if (player->getDirection() != DOWN)
	    dir = UP;
	  break;
	case KEY_DOWN:
	  if (player->getDirection() != UP)
	    dir = DOWN;
	  break;
	default:
	  break;
	}
      if (!this->_gameOver)
	moveAndFlip(player, dir);
      if (((player->getScore() % 25) == 0) && ((this->_speed - 3000) >= 35000) && player->getScore() != 0)
	if (player->getScore() != this->_score)
	  this->_speed -= 5000;
      this->_score = player->getScore();
    }
  endwin();
}

/*
** Fin du game
*/

void		NCurses::endingGame()
{
  WINDOW	*over;

  this->_gameOver = true;

  over = subwin(this->_screen, 10, 30, 0, 0);
  wprintw(over, "Game Over.\nScore: %d\nPress ESC pour Quitter.\nPress ENTER pour rejouer.\n", this->_score);
  wbkgd(over, COLOR_PAIR(11));
  delwin(over);
}
