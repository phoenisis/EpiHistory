#ifndef _SFML_H_
#define _SFML_H_
#include "../../fleuro_m/Info.hh"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <string>

class SFML_Mod
{
public:
  SFML_Mod();
  ~SFML_Mod();

  void print_CPU(const int,const  int);
  void print_RAM(const int,const  int);
  void print_Network(const int, const int);
  void print_Clock(const int, const int);
  void print_Host(const int, const int);
  void check_i(const int);
  int init(const std::string);
  void Cadre();

private:
  Info info;
  sf::RenderWindow *app;

};

#endif
