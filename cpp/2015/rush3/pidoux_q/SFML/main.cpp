#include <cstdlib>
#include <SFML/Graphics.hpp> 
#include "my_put_nbr.hh"
#include "SFML.hh"
#include <sstream>
#include <string>
#include <iostream>

static int _x = 0;
static int _y = 0;

using namespace sf;

SFML_Mod::SFML_Mod()
{
}

SFML_Mod::~SFML_Mod()
{
  delete this->app;
}

void SFML_Mod::print_CPU(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;
  Shape Title_Cadre;
  Title_Cadre.AddPoint(_y, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(_y, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.EnableFill(true);   
  Title_Cadre.EnableOutline(false);
  Title_Cadre.SetOutlineWidth(5);
  
  String Title;
  Title.SetColor(sf::Color(0, 0, 0));
  Title.SetText("CPU");
  Title.SetSize(25);
  Title.SetPosition((sizeY/2 + _y/2)-30, _x);

  Shape cadre;
  cadre.AddPoint(_y, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(_y, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.EnableFill(true);   
  cadre.EnableOutline(false);
  cadre.SetOutlineWidth(5); 

  String CPU_REF;
  CPU_REF.SetText("CPU Ref: ");
  CPU_REF.SetSize(15);
  CPU_REF.SetPosition(20+_y, 40+_x);

  String CPU_REF_TXT;
  CPU_REF_TXT.SetText(this->info.getCoretype().c_str());
  CPU_REF_TXT.SetSize(10);
  CPU_REF_TXT.SetPosition(25+_y, 60+_x);

  String NB_CORE;
  NB_CORE.SetText("Core: ");
  NB_CORE.SetSize(15);
  NB_CORE.SetPosition(20+_y, 80+_x);

  String NB_CORE_TXT;
  NB_CORE_TXT.SetText(this->info.getNbcore().c_str());
  NB_CORE_TXT.SetSize(15);
  NB_CORE_TXT.SetPosition(90+_y, 80+_x);

  this->app->Draw(cadre);
  this->app->Draw(Title_Cadre);
  this->app->Draw(Title);
  this->app->Draw(CPU_REF);
  this->app->Draw(CPU_REF_TXT);
  this->app->Draw(NB_CORE);
  this->app->Draw(NB_CORE_TXT);
}

void SFML_Mod::print_RAM(int x, int y)
{
  int sizeX = x +_x;
  int sizeY = y +_y;

  Shape Title_Cadre;
  Title_Cadre.AddPoint(_y, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(_y, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.EnableFill(true);   
  Title_Cadre.EnableOutline(false);
  Title_Cadre.SetOutlineWidth(5);
  
  String Title;
  Title.SetColor(sf::Color(0, 0, 0));
  Title.SetText("RAM");
  Title.SetSize(25);
  Title.SetPosition((sizeY/2 + _y/2)-30, _x);

  Shape cadre;
  cadre.AddPoint(_y, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(_y, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.EnableFill(true);   
  cadre.EnableOutline(false);
  cadre.SetOutlineWidth(5); 

  String RAM_CAP;
  RAM_CAP.SetText("RAM capacity: ");
  RAM_CAP.SetSize(15);
  RAM_CAP.SetPosition(20+_y , 40+_x);

  String RAM_CAP_TXT;
  std::string str;
  my_put_nbr(this->info.getRamtotal(), str);
  RAM_CAP_TXT.SetText(str.c_str());
  RAM_CAP_TXT.SetSize(15);
  RAM_CAP_TXT.SetPosition(120+_y, 40+_x);

  String RAM_FREE;
  RAM_FREE.SetText("FREE RAM: ");
  RAM_FREE.SetSize(15);
  RAM_FREE.SetPosition(20+_y , 65+_x);

  String RAM_FREE_TXT;
  std::string str2;
  my_put_nbr(this->info.getRamfree(), str2);
  RAM_FREE_TXT.SetText(str2.c_str());
  RAM_FREE_TXT.SetSize(15);
  RAM_FREE_TXT.SetPosition(110+_y, 65+_x);

  Shape border;
  border.AddPoint(35+_y, 100+_x, Color(255, 0,0), Color(255,0,0));
  border.AddPoint(135+_y, 100+_x, Color(255, 0, 0), Color(255,0,0));
  border.AddPoint(135+_y, 115+_x, Color(250,0 , 0), Color(250,0,0));
  border.AddPoint(35+_y, 115+_x, Color(250, 0, 0), Color(250,0,0));
  border.EnableFill(false); 
  border.EnableOutline(true);
  border.SetOutlineWidth(3); 

  long t = 100 - ((this->info.getRamtotal() - this->info.getRamfree())*100) / this->info.getRamtotal();

  Shape progress;
  progress.AddPoint(35+_y , 100+_x, Color(0, 0, 153), Color(0,0,153));
  progress.AddPoint(135+_y-t , 100+_x, Color(0, 0, 153), Color(0,0,153));
  progress.AddPoint(135+_y-t, 115+_x, Color(0, 0, 153), Color(0,0,153));
  progress.AddPoint(35+_y , 115+_x, Color(0, 0, 153), Color(0,0,153));
  progress.EnableFill(true);  
  progress.EnableOutline(false); 
  progress.SetOutlineWidth(3); 

  String POURCENT;
  std::string str3;
  my_put_nbr(100 - t, str3);
  POURCENT.SetText(str3.c_str());
  POURCENT.SetSize(15);
  POURCENT.SetPosition(80+_y, 98+_x);

  this->app->Draw(cadre);
  this->app->Draw(Title_Cadre);
  this->app->Draw(Title);
  this->app->Draw(RAM_CAP);
  this->app->Draw(RAM_CAP_TXT);
  this->app->Draw(RAM_FREE);
  this->app->Draw(RAM_FREE_TXT);
  this->app->Draw(border);
  this->app->Draw(progress);
  this->app->Draw(POURCENT);
}

void SFML_Mod::print_Network(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;

  Shape Title_Cadre;
  Title_Cadre.AddPoint(_y, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(_y, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.EnableFill(true);   
  Title_Cadre.EnableOutline(false);
  
  String Title;
  Title.SetColor(sf::Color(0, 0, 0));
  Title.SetText("NETWORK");
  Title.SetSize(25);
  Title.SetPosition((sizeY/2 + _y/2)-70, _x);

  Shape cadre;
  cadre.AddPoint(_y, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(_y, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.EnableFill(true);   
  cadre.EnableOutline(false);
  cadre.SetOutlineWidth(5); 

  String REC;
  REC.SetText("Received: ");
  REC.SetSize(15);
  REC.SetPosition(20+_y , 60+_x);

  String REC_TXT;
  std::string str;
  my_put_nbr(this->info.getReceived(), str);
  REC_TXT.SetText(str.c_str());
  REC_TXT.SetSize(15);
  REC_TXT.SetPosition(110+_y, 60+_x);

  String TRANS;
  TRANS.SetText("Transmited: ");
  TRANS.SetSize(15);
  TRANS.SetPosition(20+_y, 95+_x);

  String TRANS_TXT;
  std::string str2;
  my_put_nbr(this->info.getTransmited(), str2);
  TRANS_TXT.SetText(str2.c_str());
  TRANS_TXT.SetSize(15);
  TRANS_TXT.SetPosition(110+_y, 95+_x);

  this->app->Draw(cadre);
  this->app->Draw(Title_Cadre);
  this->app->Draw(Title);
  this->app->Draw(REC);
  this->app->Draw(REC_TXT);
  this->app->Draw(TRANS);
  this->app->Draw(TRANS_TXT);
}


void SFML_Mod::print_Clock(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;

  Shape Title_Cadre;
  Title_Cadre.AddPoint(_y, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(_y, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.EnableFill(true);   
  Title_Cadre.EnableOutline(false);
  Title_Cadre.SetOutlineWidth(5);
  
  String Title;
  Title.SetColor(sf::Color(0, 0, 0));
  Title.SetText("CLOCK");
  Title.SetSize(25);
  Title.SetPosition((sizeY/2 + _y/2) -45, _x);

  Shape cadre;
  cadre.AddPoint(_y, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(_y, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.EnableFill(true);   
  cadre.EnableOutline(false);
  cadre.SetOutlineWidth(5); 

  String Time;
  Time.SetText(this->info.getDate().c_str());
  Time.SetSize(20);
  Time.SetPosition(45+_y , 60+_x);

  String Time_TXT;
  sf::Font MyFont;
  if (MyFont.LoadFromFile("Police.TTF", 50))
    { 
      Time_TXT.SetText(this->info.getHeure().c_str());
      Time_TXT.SetFont(MyFont);
      Time_TXT.SetSize(50);
      Time_TXT.SetPosition(20+_y, 95+_x);
    }
  else 
    {
      Time_TXT.SetText(this->info.getHeure().c_str());
      Time_TXT.SetSize(50);
      Time_TXT.SetPosition(20+_y, 95+_x);
    }
  this->app->Draw(cadre);
  this->app->Draw(Title_Cadre);
  this->app->Draw(Title);
  this->app->Draw(Time);
  this->app->Draw(Time_TXT);
}

void SFML_Mod::print_Host(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;

  Shape Title_Cadre;
  Title_Cadre.AddPoint(_y, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, _x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(sizeY, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.AddPoint(_y, 30+_x, Color(220, 220, 220), Color(220,220,220));
  Title_Cadre.EnableFill(true);   
  Title_Cadre.EnableOutline(false);
  Title_Cadre.SetOutlineWidth(5);
  
  String Title;
  Title.SetColor(sf::Color(0, 0, 0));
  Title.SetText("HOST");
  Title.SetSize(25);
  Title.SetPosition((sizeY/2 + _y/2) -45, _x);

  Shape cadre;
  cadre.AddPoint(_y, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, _x, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(sizeY, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.AddPoint(_y, sizeX, Color(142, 142, 142), Color(142,142,142));
  cadre.EnableFill(true);   
  cadre.EnableOutline(false);
  cadre.SetOutlineWidth(5); 

  String Name;
  Name.SetText("User: ");
  Name.SetSize(15);
  Name.SetPosition(20+_y , 40+_x);

  String Name_TXT;
  Name_TXT.SetText(this->info.getUsername().c_str());
  Name_TXT.SetSize(15);
  Name_TXT.SetPosition(60+_y, 40+_x);

  String Des;
  Des.SetText("Host: ");
  Des.SetSize(15);
  Des.SetPosition(20+_y, 60+_x);

  String Des_TXT;
  Des_TXT.SetText(this->info.getHostname().c_str());
  Des_TXT.SetSize(15);
  Des_TXT.SetPosition(60+_y, 60+_x);

  String Distrib;
  Distrib.SetText("OS: ");
  Distrib.SetSize(15);
  Distrib.SetPosition(20+_y, 80+_x); 

  String Distrib_TXT;
  Distrib_TXT.SetText(this->info.getOstype().c_str());
  Distrib_TXT.SetSize(15);
  Distrib_TXT.SetPosition(60+_y, 80+_x);

  String Ker;
  Ker.SetText("Kernel: ");
  Ker.SetSize(15);
  Ker.SetPosition(20+_y, 100+_x); 

  String Ker_TXT;
  Ker_TXT.SetText(this->info.getOsrelease().c_str());
  Ker_TXT.SetSize(13);
  Ker_TXT.SetPosition(25+_y, 120+_x);

  sf::Image image;
  if (!image.LoadFromFile("fedora-logo.png"))
    {
    }
  sf::Sprite monSprite(image);
  monSprite.Resize(30, 30);
  monSprite.SetPosition(sizeY -25,_x);

  this->app->Draw(cadre);
  this->app->Draw(Title_Cadre);
  this->app->Draw(Title);
  this->app->Draw(Name);
  this->app->Draw(Name_TXT);
  this->app->Draw(Des);
  this->app->Draw(Des_TXT);
  this->app->Draw(Distrib);
  this->app->Draw(Distrib_TXT);
  this->app->Draw(Ker);
  this->app->Draw(Ker_TXT);
  this->app->Draw(monSprite);
}

void SFML_Mod::check_i(int i)
{
  if (i == 1)
    {
      _y = 200;
      _x = 0;
    }
  else if (i == 2)
    {
      _y = 0;
      _x = 200;
    }
  else if (i == 3)
    {
      _y = 200;
      _x = 200;
    }
  else if (i == 4)
    {
      _y = 100;
      _x = 400;
    }
}


int SFML_Mod::init(std::string str)
{
  int x, y, i = 0;
  int len = str.length();

  if (len == 1)
    {
      x = 200;
      y = 200;
    }
  else if(len == 2)
    {
      x = 400;
      y = 200;
    }
  else if (len == 3 || len == 4)
    {
      x = 400;
      y = 400;
    }
  else
    {
      x = 400;
      y = 600;
    }

  this->app = new RenderWindow(VideoMode(x, y, 32), "Rush3 SFML !");
  
  while (app->IsOpened())
    {
      Event event;
      
      while (app->GetEvent(event))
	{
	  if (event.Type == Event::Closed)
	    {
	      this->app->Close();
	      break;
	    }
	  if (event.Type == Event::KeyPressed)
	    {
	      if (event.Key.Code == 256)
		return 27;
	    }
        }
      _x = _y = i = 0;
      sleep(1);
      app->Clear();
      this->info.refresh();
      while (i < len)
	{
	  if (str[i] == 'C')
	    {
	      check_i(i++);
	      print_CPU(200, 200);
	    }
	  else if (str[i] == 'R')
	    {
	      check_i(i++);
	      print_RAM(200, 200);
	    }
	  else if (str[i] == 'N')
	    {
	      check_i(i++);
	      print_Network(200, 200);
	    }
	  else if (str[i] == 'T')
	    {
	      check_i(i++);
	      print_Clock(200, 200);
	    }
	  else if (str[i] == 'H')
	    {
	      check_i(i++);
	      print_Host(200, 200);
	    }
	  else
	    {
	      std::cout << "Bad Usage" << std::endl;
	      return EXIT_FAILURE;
	    }
	}
      _x = _y = i = 0;
      app->Display();
    }
  return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
  if (ac < 2)
    {
      std::cout << "Usage ./MyGKrellM CRHTN" << std::endl
		<< "C = CPU, R = RAM, H = Host, T = Clock, N = Network, information" << std::endl;
      return 0;
    }

  SFML_Mod tata;
  tata.init(av[1]);
  
  return 0;
}
