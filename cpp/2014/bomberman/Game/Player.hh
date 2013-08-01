#ifndef		__PLAYER_HH__
# define	__PLAYER_HH__

#include "bomberlib.hh"
#include "Map.hh"
#include "Camera.hh"
#include "Bomberman.hh"
#include "Bomb.hh"
#include "Config.hh"

class	Player : public Model::Bomberman
{
public :
  Player(Map *map, Model::Bomb *bomb, Config *config);
  ~Player();
  void	Action(gdl::Input &input);

  Camera	*camera_;

private :
  gdl::Keys::Key	Up;
  gdl::Keys::Key	Down;
  gdl::Keys::Key	Right;
  gdl::Keys::Key	Left;
  gdl::Keys::Key	Bomb;
};

#endif
