#include "NCURSE.hh"
#include "../../fleuro_m/Info.hh"
#include <curses.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <cstdio>
#include <fcntl.h>
#include <sys/ioctl.h>

static int _x = 0;
static int _y = 0;

NCURSE::NCURSE()
{
}

NCURSE::~NCURSE()
{
}


void NCURSE::print_CPU(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;

  move(sizeY, sizeX);
  printw("CPU");

  move(2+sizeY, 2+sizeX);
  printw("CPU Ref: ");

  move(3+sizeY, 3+sizeX);
  printw("%s", this->info.getCoretype().c_str());

  move(4+sizeY, 2+sizeX);
  printw("Frequence: %s",  this->info.getFrequence().c_str());

  move(6+sizeY, 2+sizeX);
  printw("Core: ");

  move(6+sizeY, 8+sizeX);
  printw("%s", this->info.getNbcore().c_str());
}

void NCURSE::print_RAM(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;
  long i, j;

  move(sizeY, sizeX);
  printw("RAM");
  
  i = this->info.getRamtotal();
  j = this->info.getRamfree();
  move(2+sizeY, 2+sizeX);
  printw("Total RAM : %ld\n  Free RAM : %ld\n  Used RAM : %ldkB\n  [", i, j, i - j);
    for(int k = 0 ; k != ((i - j) * 20 / i) ; k++)
  {
  printw("|");
  }
  for(int k = 0 ; k != 20 - ((i - j) * 20 / i) ; k++)
  {
  printw(" ");
  }
  printw("] %d%%", (i - j) * 100 / i);

}

void NCURSE::print_Network(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;

  move(sizeY, sizeX);
  printw("NETWORK");

  move(2+sizeY, 2+sizeX);
  printw("Received: ");

  move(2+sizeY, 12+sizeX);
  printw("%ld", this->info.getReceived());

  move(4+sizeY, 2+sizeX);
  printw("Transmited: ");

  move(4+sizeY, 14+sizeX);
  printw("%ld", this->info.getTransmited());
}

void NCURSE::print_Clock(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;

  move(sizeY, sizeX);
  printw("Clock");

  move(2+sizeY, 2+sizeX);
  printw("Date: ");

  move(2+sizeY, 8+sizeX);
  printw("%s", this->info.getDate().c_str());

  move(4+sizeY, 2+sizeX);
  printw("%s", this->info.getHeure().c_str());
}

void NCURSE::print_Host(int x, int y)
{
  int sizeX = x + _x;
  int sizeY = y + _y;
  
  move(sizeY, sizeX);
  printw("HOST");

  move(2+sizeY, 2+sizeX);
  printw("User: ");

  move(2+sizeY, 8+sizeX);
  printw("%s", this->info.getUsername().c_str());

  move(4+sizeY, 2+sizeX);
  printw("Host: ");

  move(4+sizeY, 8+sizeX);
  printw("%s", this->info.getHostname().c_str());

  move(6+sizeY, 2+sizeX);
  printw("OS: ");

  move(6+sizeY, 8+sizeX);
  printw("%s", this->info.getOstype().c_str());

  move(8+sizeY, 2+sizeX);
  printw("Kernel: ");

  move(9+sizeY, 4+sizeX);
  printw("%s", this->info.getOsrelease().c_str());
}

void NCURSE::check_i(int i)
{
  if (i == 1)
    {
      _y = 0;
      _x = 30;
    }
  else if (i == 2)
    {
      _y = 12;
      _x = 0;
    }
  else if (i == 3)
    {
      _y = 12;
      _x = 30;
    }
  else if (i == 4)
    {
      _y = 24;
      _x = 20;
    }
}

void    NCURSE::init_ncurses()
{
  char                  *term;
  struct termios        line;

  if (ioctl(0, TCGETA, &line) == -1)
    exit(EXIT_FAILURE);
  line.c_lflag &= ~(ICANON | ECHO | O_NONBLOCK);
  if (ioctl(0, TCSETA, &line) == -1)
    exit(EXIT_FAILURE);
  if (fcntl(0, F_SETFL, O_NONBLOCK) == -1)
    exit(EXIT_FAILURE);
  term = getenv("TERM");
  if (term == NULL)
    exit(EXIT_FAILURE);

  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
  bkgd(COLOR_PAIR(1));
}

int NCURSE::init(std::string str)
{
  int x, y, i = 0;
  int len = str.length();

  while(42)
    {
      _x = _y = i = 0;
      erase();
      sleep(1);
      this->info.refresh();
      while (i < len)
	{
	  if (str[i] == 'C')
	    {
	      check_i(i++);
	      print_CPU(0, 0);
	    }
	  else if (str[i] == 'R')
	    {
	      check_i(i++);
	      print_RAM(0, 0);
	    }
	  else if (str[i] == 'N')
	    {
	      check_i(i++);
	      print_Network(0, 0);
	    }
	  else if (str[i] == 'T')
	    {
	      check_i(i++);
	      print_Clock(0, 0);
	    }
	  else if (str[i] == 'H')
	    {
	      check_i(i++);
	      print_Host(0, 0);
	    }
	  else
	    {
	      std::cout << "Bad usage" << std::endl;
	      return EXIT_FAILURE;
	    }
	}
      refresh();
    }
  return EXIT_SUCCESS;
}

int	main(int ac, char **av)
{
  WINDOW *menubar,*messagebar;

  NCURSE tata;
  if (ac < 2)
    {
      std::cout << "Usage ./MyGKrellM CRHTN" << std::endl
		<< "C = CPU, R = RAM, H = Host, T = Clock, N = Network, information" << std::endl;
      return 0;
    }

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  if (w.ws_row < 36 || w.ws_col < 65)
    {
      std::cout << "Open a Terminal larger than 36x65 please." << std::endl;
      return 0;
    }

  tata.init_ncurses();
  
  bkgd(COLOR_PAIR(1));
  menubar = subwin(stdscr, 1, 80, 0, 0);
  messagebar = subwin(stdscr, 1, 79, 23, 1);
  tata.init(av[1]);
  return 0;
}

