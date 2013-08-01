/*
**  src/Character.hh
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef		__CHARACTER_HH__
#define		__CHARACTER_HH__

#include	<string>
#include	"Map.hh"

//Player : 1
//box : 2
//wall : 3
//bonus : 4
//bomb : 5

class		Character
{
public:
  typedef enum e_action
    {
      RIGHT,
      LEFT,
      UP,
      DOWN,
      BOMB
    }	       action;
  Character(int, int, std::string);
  ~Character();
  
  int		getPosX() const;
  void		setPosX(int);
  int		getPosY() const;
  void		setPosY(int);
  int		getNbBombs() const;
  void		setNbBombs(int);
  int		getPower() const;
  void		setPower(int);
  void		checkBonus(map::map &, map::bloc_type);
  void		doBomb();
  void		movePlayer(map::map &, action, map::bloc_type);

private:
  int		_posX;
  int		_posY;
  std::string	_name;
  int		_nbBombs;
  int		_power;
  float		_speed;
};

#endif
