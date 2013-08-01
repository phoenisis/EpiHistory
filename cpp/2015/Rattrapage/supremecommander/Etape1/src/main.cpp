//
//  main.cpp
//  commander
//
//  Created by Quentin PIDOUX on 20/07/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#include "../inc/Ressource.hh"
#include "../inc/Building.hh"
#include "../inc/Map.hh"

#include <iostream>
#include <sstream>

int main(int argc, const char * argv[])
{
  Map map = *new Map;

  std::string str = "";
  std::string str2 = "";
  std::string type = "";

  int x = 0;
  int y = 0;
  size_t found;

  while (std::cin != '\0'){
    x = y = 0;

    std::getline(std::cin, str);

    found = str.find_first_of("#");
    str2 = str.substr(0,found);

    if (str2.length() > 0){
      std::istringstream	is(str2, std::istringstream::in);
      is >> type;
      is >> x;
      is >> y;

      if (type.compare("MAP") != 0 && map.getStatut() == true)
	map.parse(type, x, y);
      else
	map.setSize(x, y);
    }
    else
      if (str.length() < 1){
	break;
      }
  }
  map.setBonus();
  map.affASCII();
  std::cout << "MONITORING" << std::endl;
  map.showAll();
  std::cout << "# Total economique avec bonus:" << std::endl
	    << "# Eco Total_energy total_mass" << std::endl
	    << "Eco " << map.getTotalEngy() << " " << map.getPmass() << std::endl
	    << std::endl << "# Economic efficiency:" << std::endl
	    << "EcoEff " << map.getEcoEff() << std::endl;
  return 0;
}

