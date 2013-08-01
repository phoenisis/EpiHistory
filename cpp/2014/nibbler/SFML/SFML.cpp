//
//  SFML.cpp
//  
//
//  Created by quentin PIDOUX on 06/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "SFML_mod.hh"
#include <sstream>

using namespace sf;


SFML_mod::SFML_mod(RenderWindow *app)
{
  this->app = app;
}

SFML_mod::~SFML_mod()
{
  delete this->app;
}
  
void SFML_mod::print_map(int x, int y)
{
    
    int sizeX, sizeY;
    sizeX = 5 + (x * 10);
    sizeY = 5 + (y * 10);
    
    Shape cadre;
    cadre.AddPoint(5, 5, Color(255, 255, 0), Color(255,255,255));
    cadre.AddPoint(sizeY, 5, Color(255, 255, 0), Color(255,0,0));
    cadre.AddPoint(sizeY, sizeX, Color(0, 255, 255), Color(0,255,0));
    cadre.AddPoint(5, sizeX, Color(0, 255, 255), Color(0,0,255));
    cadre.EnableFill(false);   // Remplissage activé
    cadre.EnableOutline(true); // Bordures activées
    cadre.SetOutlineWidth(5);  // Bordures de taille 5 pixels

    this->app->Clear();
    this->app->Draw(cadre);
}

void SFML_mod::print_snake(int x, int y, bool isHead)
{
  int sizeX, sizeY;
  sizeX = 5 + (x * 10);
  sizeY = 5 + (y * 10);
    
  Shape carre;
  if (isHead)
    {
      carre.AddPoint(sizeY + 2, sizeX + 2, Color(0, 255, 0), Color(0, 125, 255));
      carre.AddPoint(sizeY + 2, sizeX + 8, Color(0, 255, 0), Color(0, 125, 255));
      carre.AddPoint(sizeY + 8, sizeX + 8, Color(0, 255, 0), Color(0, 125, 255));
      carre.AddPoint(sizeY + 8, sizeX + 2, Color(0, 255, 0), Color(0, 125, 255));
    }
  else
    {
      carre.AddPoint(sizeY + 2, sizeX + 2, Color(0, 255, 0), Color(0, 255, 0));
      carre.AddPoint(sizeY + 2, sizeX + 8, Color(0, 255, 0), Color(0, 255, 0));
      carre.AddPoint(sizeY + 8, sizeX + 8, Color(0, 255, 0), Color(0, 255, 0));
      carre.AddPoint(sizeY + 8, sizeX + 2, Color(0, 255, 0), Color(0, 255, 0));
    }
  carre.EnableFill(false);
  carre.EnableOutline(true); // Bordures activées
  carre.SetOutlineWidth(2);  // Bordures de taille 2 pixels
  
  this->app->Draw(carre);
}

void SFML_mod::print_apple(int x, int y)
{
  int sizeX, sizeY;
  sizeX = 5 + (x * 10);
  sizeY = 5 + (y * 10);
  
  Shape apple;
  apple.AddPoint(sizeY, sizeX, Color(255, 0, 0), Color(255, 0, 0));
  apple.AddPoint(sizeY, sizeX + 10, Color(255, 0, 0), Color(255, 0, 0));
  apple.AddPoint(sizeY + 10, sizeX + 10, Color(255, 0, 0), Color(255, 0, 0));
  apple.AddPoint(sizeY + 10, sizeX, Color(255, 0, 0), Color(255, 0, 0));
  apple.EnableFill(true);
  
  this->app->Draw(apple);
  
}

#include <cstdio>

int SFML_mod::get_key()
{
  Event	event;

  while (this->app->GetEvent(event))
    {
      if (event.Type == Event::KeyPressed)
	{
	  if (event.Key.Code == 291)
	    return 260;
	  else if (event.Key.Code == 292)
	    return 261;
	  else if (event.Key.Code == 293)
	    return 259;
	  else if (event.Key.Code == 294)
	    return 258;
	  else if (event.Key.Code == 256)
	    return 27;
	}
    }
  return -1;
}

void SFML_mod::print_score(int highscore, int score, int apple_eat, int x)
{
  int sizeX;
  sizeX = x * 10;

  std::ostringstream High;
  High << highscore;
  std::ostringstream Sc;
  Sc << score;
  std::ostringstream Ap;
  Ap << apple_eat;

  String Highscore_txt;
  Highscore_txt.SetText("Highscore: ");
  Highscore_txt.SetSize(15);
  Highscore_txt.SetPosition(sizeX +20 , 20);

  String Highscore;
  Highscore.SetText(High.str());
  Highscore.SetSize(15);
  Highscore.SetPosition(sizeX + 100, 20);

  String Score_txt;
  Score_txt.SetText("Score: ");
  Score_txt.SetSize(15);
  Score_txt.SetPosition(sizeX + 20, 50);

  String Score;
  Score.SetText(Sc.str());
  Score.SetSize(15);
  Score.SetPosition(sizeX + 80, 50);

  String Apple_txt;
  Apple_txt.SetText("Apple: ");
  Apple_txt.SetSize(15);
  Apple_txt.SetPosition(sizeX + 20, 65);

  String Apple;
  Apple.SetText(Ap.str());
  Apple.SetSize(15);
  Apple.SetPosition(sizeX + 80, 65);

  this->app->Draw(Highscore_txt);
  this->app->Draw(Highscore);
  this->app->Draw(Score_txt);
  this->app->Draw(Score);
  this->app->Draw(Apple_txt);
  this->app->Draw(Apple);
  this->app->Display();
}

int  SFML_mod::new_game()
{
  Event event;

  String Destiny;
  Destiny.SetText("Try Again ? Press Y");
  Destiny.SetSize(15);
  Destiny.SetPosition(150, 20);

  String Death;
  Death.SetText("Quit ? Press N");
  Death.SetSize(15);
  Death.SetPosition(150, 40);
  
  this->app->Clear();
  this->app->Draw(Destiny);
  this->app->Draw(Death);

   while (this->app->GetEvent(event) || 42)
     {
       this->app->Display();
       if (event.Type == Event::Closed)
	 {
	   this->app->Close();
	   break;
       }
       if (event.Type == Event::KeyPressed)
	 {
	   if (event.Key.Code == Key::Y)
	     return 0;
	   else if (event.Key.Code == Key::N)
	    return 1;
	 }
     }
  return 42;
}

void	SFML_mod::init(int x, int y)
{
int sizeX, sizeY;
  sizeX = x * 10;
  sizeY = y * 10;

  this->app = new RenderWindow(VideoMode(sizeY + 170, sizeX + 10, 32), "Nibbler SFML !");
}

void	SFML_mod::close()
{
  this->app->Close();
}
  
extern "C" SFML_mod	*Display_builder()
{
  return new SFML_mod(new RenderWindow);
}
