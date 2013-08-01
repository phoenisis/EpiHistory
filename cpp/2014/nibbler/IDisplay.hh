//
//  IDisplay.hh
//  
//
//  Created by quentin PIDOUX on 06/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#ifndef _IDisplay_hh
#define	_IDisplay_hh

class	IDisplay
{
public :
  virtual ~IDisplay() {};

  virtual void print_map(int x, int y) = 0;
  virtual void print_snake(int x, int y, bool isHead) = 0;
  virtual void print_apple(int x, int y) = 0;
  virtual void print_score(int highscore, int score, int apple_eat, int x) = 0;
  virtual void init(int x, int y) = 0;
  virtual int  new_game() = 0;
  virtual int  get_key() = 0;
  virtual void close() = 0;
};

#endif
