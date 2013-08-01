
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <list>
#include "Case.hpp"
#include "CExceptions.hpp"
#include "toDisplay.hpp"
#include "Nibbler.hpp"
#include "lib_nibbler_sdl.hpp"

/*
**  CTOR & DTOR
*/

SDL::SDL(size_t nbCaseW, size_t nbCaseH)
  : _caseWidth(16), _caseHeight(16), _speed(50), _end(false), _gameOver(false), _screen(NULL)
{
  this->_scrWidth = (nbCaseW * this->_caseWidth);
  this->_scrHeight = (nbCaseH * this->_caseHeight);
}

SDL::~SDL()
{
  TTF_Quit();
  SDL_Quit();
}

/*
** Getter's
*/

int		SDL::getScrWidth() const
{
  return this->_scrWidth;
}

int		SDL::getScrHeight() const
{
  return this->_scrHeight;
}

size_t		SDL::getCaseWidth() const
{
  return this->_caseWidth;
}

size_t		SDL::getCaseHeight() const
{
    return this->_caseHeight;
}

/*
** Fonction de gestion de l'affichage
*/

void		SDL::init(int, char **)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
    throw CError("Error while SDL_Init.");
  if (TTF_Init() == -1)
    throw CError("Error while TTF_Init.");
  if ((this->_screen = SDL_SetVideoMode(this->_scrWidth, this->_scrHeight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    throw CError("Error while SDL_SetVideoMode.");
  SDL_WM_SetCaption("Nibbler by aysan_r & deu_f & pidoux_q", NULL);

  this->_imgLand = IMG_Load("ressources/img/land/sable.png");
}

void		SDL::display(std::list<toDisplay *> const& data)
{
  std::list<toDisplay *>::const_iterator	it;
  
  for (it = data.begin(); it != data.end(); ++it)
    (*it)->display();
  //  SDL_Flip(this->_screen);
}

/*
** Gestion du screen
*/

void		SDL::putOnScreen(Case const * const cs)
{
  SDL_Surface*	newCase = NULL;
  SDL_Rect	poz;
  
  poz.x = cs->getX();
  poz.y = cs->getY();

  if (cs->getType() == GRASS)
    {
      if ((newCase = this->_imgLand) == NULL)
	{
	  newCase = SDL_CreateRGBSurface(SDL_HWSURFACE, this->_caseWidth, this->_caseHeight, 32, 0, 0, 0, 0);
	  SDL_FillRect(newCase, NULL, SDL_MapRGB(this->_screen->format, 0, 255, 0));
	}
    }
  else if (cs->getType() == FRUIT)
    {
      if ((newCase = IMG_Load(std::string("ressources/img/fruit/orange.png").c_str())) == NULL)
	{
	  newCase = SDL_CreateRGBSurface(SDL_HWSURFACE, this->_caseWidth, this->_caseHeight, 32, 0, 0, 0, 0);
	  SDL_FillRect(newCase, NULL, SDL_MapRGB(this->_screen->format, 255, 0, 0));
	}
    }
  else if (cs->getType() == SNAKE_HEAD)
    {
      newCase = SDL_CreateRGBSurface(SDL_HWSURFACE, this->_caseWidth, this->_caseHeight, 32, 0, 0, 0, 0);
      SDL_FillRect(newCase, NULL, SDL_MapRGB(this->_screen->format, 255, 255, 0xff));
    }
  else
    {
      newCase = SDL_CreateRGBSurface(SDL_HWSURFACE, this->_caseWidth, this->_caseHeight, 32, 0, 0, 0, 0);
      SDL_FillRect(newCase, NULL, SDL_MapRGB(this->_screen->format, 0, 0x99, 0xff));
    }

  SDL_BlitSurface(newCase, NULL, this->_screen, &poz);
  if (cs->getType() != GRASS)
    SDL_FreeSurface(newCase);
}

/*
** Gestion du score
*/

void			SDL::displayScore(Player const * const p)
{
  SDL_Rect		scorePoz;
  SDL_Surface		*score = NULL;
  TTF_Font		*font = NULL;
  SDL_Color		color = {255, 255, 255, 0};
  std::stringstream	s_score;
  
  s_score << p->getScore();
  if ((font = TTF_OpenFont("ressources/font/arial.ttf", 16)) == NULL)
    throw CError("Can't open font.");
  TTF_SetFontStyle(font, TTF_STYLE_BOLD);
  if ((score = TTF_RenderText_Solid(font, s_score.str().c_str(), color)) == NULL)
    throw CError("Can't Render Text.");
  
  scorePoz.x = this->_screen->w - score->w - 10;
  scorePoz.y = 10;
  
  SDL_BlitSurface(score, NULL, this->_screen, &scorePoz);      
  //  SDL_Flip(this->_screen);

  TTF_CloseFont(font);  
  SDL_FreeSurface(score);
}

/*
** Deplacement et demarrage du jeu
*/

void		SDL::moveAndFlip(Player *player, direction dir)
{
  player->move(dir);
  if (!this->_gameOver)
    displayScore(player);
  SDL_Flip(this->_screen);
  SDL_Delay(this->_speed);
}

/*
** La mainloop du jeu
*/

void		SDL::mainLoop(Player* player)
{
  direction	dir;

  SDL_EnableKeyRepeat(10, 10);
  while (!this->_end)
    {
      SDL_PollEvent(&(this->_event));
      dir = FORWARD;
      switch(this->_event.type)
	{
	case SDL_QUIT:
	  this->_end = true;
	  break;
	case SDL_KEYDOWN:
	  switch(this->_event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      this->_end = true;
	      break;
	    case SDLK_q:
	      this->_end = true;
	      break;
	    case SDLK_RETURN:case SDLK_SPACE:
	      if (this->_gameOver == true)
		{
		  player->reset();
		  this->_gameOver = false;
		}
	      break;
	    case SDLK_LEFT:case SDLK_a:
	      if (player->getDirection() != RIGHT)
		dir = LEFT;
	      break;
	    case SDLK_RIGHT:case SDLK_d:
	      if (player->getDirection() != LEFT)
		dir = RIGHT;
	      break;
	    case SDLK_UP:case SDLK_w:
	      if (player->getDirection() != DOWN)
		dir = UP;
	      break;
	    case SDLK_DOWN:case SDLK_s:
	      if (player->getDirection() != UP)
		dir = DOWN;
	      break;
	    default:
	      break;
	    }
	  break;
	}
      if (!this->_gameOver)
	{  
	  moveAndFlip(player, dir);
	}
      
      (void)player;
      if (((player->getScore() % 25) == 0) && ((this->_speed - 3) >= 35) && player->getScore() != 0)
	{
	  
	  if (player->getScore() != this->_score)
	    {
	  
	      this->_speed -= 10;
	      //	      this->_score = player->getScore();
	    }
	}
    }
}

/*
** La fin du jeu
*/

void		SDL::endingGame()
{
  SDL_Rect	txtPoz;
  SDL_Rect	bgPoz;
  SDL_Rect	quitPoz;
  SDL_Rect	playPoz;

  TTF_Font	*font = NULL;
  TTF_Font	*oFont = NULL;

  SDL_Surface	*gameOver = NULL;
  SDL_Surface	*quit = NULL;
  SDL_Surface	*replay = NULL;
  SDL_Surface	*background = NULL;

  SDL_Color	textColor = { 255, 255, 255, 0 };

  this->_gameOver = true;
  if ((font = TTF_OpenFont("ressources/font/arial.ttf", 42)) == NULL)
    throw CError("Can't open font.");
  if ((oFont = TTF_OpenFont("ressources/font/arial.ttf", 21)) == NULL)
    throw CError("Can't open font.");
  TTF_SetFontStyle(font, TTF_STYLE_BOLD);
  if ((gameOver = TTF_RenderText_Solid(font, "Game Over", textColor)) == NULL)
    throw CError("Can't Render Text.");
  TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
  if ((quit = TTF_RenderText_Solid(oFont, "Press Q or ESC to quit.", textColor)) == NULL)
    throw CError("Can't Render Text.");
  if ((replay = TTF_RenderText_Solid(oFont, "Press ENTER or SPACE to replay.", textColor)) == NULL)
    throw CError("Can't Render Text.");

  if ((background = SDL_CreateRGBSurface(SDL_HWSURFACE, this->_scrWidth, this->_scrHeight, 32, 0, 0, 0, 0)) == NULL)
    throw CError("Error while loading background");  
  SDL_FillRect(background, NULL, SDL_MapRGB(this->_screen->format, 0, 0, 0));

  txtPoz.x = (this->_scrWidth / 2) - (gameOver->w / 2);
  txtPoz.y = (this->_scrHeight / 2) - (gameOver->h / 2) - (gameOver->h * 2);

  quitPoz.x = (this->_scrWidth / 2) - (quit->w / 2);
  quitPoz.y = ((this->_scrHeight / 2) - (gameOver->h / 2));

  playPoz.x = (this->_scrWidth / 2) - (replay->w / 2);
  playPoz.y = ((this->_scrHeight / 2) - (replay->h / 2)) + gameOver->h;

  bgPoz.x = 0;
  bgPoz.y = 0;

  SDL_BlitSurface(background, NULL, this->_screen, &bgPoz);
  SDL_BlitSurface(gameOver, NULL, this->_screen, &txtPoz);
  SDL_BlitSurface(quit, NULL, this->_screen, &quitPoz);
  SDL_BlitSurface(replay, NULL, this->_screen, &playPoz);

  SDL_Flip(this->_screen);

  TTF_CloseFont(font);
  TTF_CloseFont(oFont);

  SDL_FreeSurface(gameOver);
  SDL_FreeSurface(quit);
  SDL_FreeSurface(replay);
  SDL_FreeSurface(background);
}
