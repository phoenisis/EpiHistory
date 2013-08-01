#include "Config.hh"
#include "bomberlib.hh"



Config1::Config1()
{
  this->Up = gdl::Keys::Up;
  this->Down = gdl::Keys::Down;
  this->Right = gdl::Keys::Right;
  this->Left = gdl::Keys::Left;
  this->Bomb = gdl::Keys::Numpad0;
}

Config2::Config2()
{
  this->Up = gdl::Keys::W;
  this->Down = gdl::Keys::S;
  this->Right = gdl::Keys::D;
  this->Left = gdl::Keys::A;
  this->Bomb = gdl::Keys::G;
}
