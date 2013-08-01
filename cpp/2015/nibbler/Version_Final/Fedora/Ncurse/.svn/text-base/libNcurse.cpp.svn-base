//
//  libNcurse.cpp
//  Nibbler
//
//  Created by quentin PIDOUX on 06/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#include <curses.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "Ncurse_mod.hh"

#define ESCAPE 27

Ncurse_mod::Ncurse_mod()
{}

Ncurse_mod::~Ncurse_mod()
{}

void	Ncurse_mod::init(int x, int y)
{
  char			*term;
  struct termios	line;

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

  (void)x;
  (void)y;
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
  bkgd(COLOR_PAIR(1));
}

void	Ncurse_mod::print_map(int x, int y)
{
  int	i = 0;

  erase();
  move(0, 0);
  printw("+");
  while (i < x)
    {
      printw("-");
      i++;
    }
  printw("+");
  i = 1;
   while (i < y + 1)
    {
      move(i, 0);
      printw("|");
      move(i, x + 1);
      printw("|");
      i++;
    } 
   move(i, 0);
   printw("+");
   i = 1;
   while (i <= x)
    {
      printw("-");
      i++;
    }
   printw("+");
}

void	Ncurse_mod::print_snake(int x, int y, bool isHead)
{
  move(x + 1, y + 1);
  if (isHead)
    printw("H");
  else
    printw("O");
}

void	Ncurse_mod::print_apple(int x, int y)
{
  move(x + 1, y + 1);
  printw("X");
}

void	Ncurse_mod::print_score(int highscore, int score, int apple_eat, int x)
{
  move(12, x + 5);
  printw("Highscore:");
  move(12, x + 16);
  printw("%d", highscore);
  move(15, x + 5);
  printw("Score:");
  move(15, x + 12);
  printw("%u", score);
  move(16, x + 5);
  printw("Apple:");
  move(16, x + 12);
  printw("%d", apple_eat);
  refresh();
}

int	Ncurse_mod::new_game()
{
  int	key = -1;

  erase();
  move(15, 15);
  printw("Game Over.\nContinue ?       Yes <- or -> No");
  refresh();
  while (42)
    {
      key = getch();
      if (key == 260)
	return 0;
      else if (key == 261 || key == ESCAPE)
	return 1;
      else
	key = -1;
    }
}

int	Ncurse_mod::get_key()
{
  if (getch() == 260)
    return 1;
  else if (getch() == 261)
    return 2;
  else if (getch() == 259)
    return 3;
  else if (getch() == 258)
    return 4;
  else 
    return getch();
}

void	Ncurse_mod::close()
{
  endwin();
}

extern "C" Ncurse_mod	*Display_builder()
{
  return new Ncurse_mod;
}
