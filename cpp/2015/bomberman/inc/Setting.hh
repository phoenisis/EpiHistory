/*
**  inc/Setting.hh
**  Bomberman
**
**  Created by Quentin PIDOUX on 01/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef	Setting_hh_
# define Setting_hh_

# include "Bomberlib.hh"

class	Setting
{
public :
  gdl::Keys::Key	Up;
  gdl::Keys::Key	Down;
  gdl::Keys::Key	Right;
  gdl::Keys::Key	Left;
  gdl::Keys::Key	Space;
};

class	Setting1 : public Setting
{
public :
  Setting1();
};

class	Setting2 : public Setting
{
public :
  Setting2();
};

#endif
