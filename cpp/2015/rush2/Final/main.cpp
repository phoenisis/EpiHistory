//
//  main.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright rush2012. All rights reserved.
//

#include "Jouet.h"
#include "Objet.h"
#include "Nounours.h"
#include "PetitPoney.h"
#include "Carton.h"
#include "PapierCadeau.h"
#include "MesTestUnitaires.h"
#include <iostream>
#include <string>

Objet **MesTestUnitaires()
{
    Objet * pp = new PetitPoney("Poney gay");
    Objet * nn = new Nounours("Bisounours");
        
    Objet **tab = new Objet*[3];
    
    tab[0] = pp;
    tab[1] = nn;
    
    return tab;
}					

Objet *MesTestUnitaires(Objet **tab)
{
  int jouet;
  int carton;
  int papier;
    
  for (jouet = 0; tab[jouet] != NULL; jouet++)
    {
      if (tab[jouet]->getType() == 0)
	break;
      if (tab[jouet]->getType() == 3)
	break;
      if (tab[jouet]->getType() == 4)
	break;
    }
  for (carton = 0; tab[carton] != NULL; carton++)
    {
      if (tab[carton]->getType() == 1)
	break;
    }
  for (papier = 0; tab[papier] != NULL; papier++)
    {
      if (tab[papier]->getType() == 2)
	break;
    }
  tab[carton]->emballeMoiCa(tab[jouet]);
  tab[papier]->emballeMoiCa(tab[carton]);
  return tab[papier];
}

int main()
{
    Objet * pp = new PetitPoney("Poney gay");
    Objet * ca = new Carton();
    Objet * pc = new PapierCadeau();
    Objet *cadeau;
    Objet **tab;
    
    Objet *tab2[4];
    tab2[0] = pp;
    tab2[1] = ca;
    tab2[2] = pc;
    tab2[3] = NULL;

    tab = MesTestUnitaires();
    cadeau = MesTestUnitaires(tab2);
    
    tab[0]->estPris();
    tab[1]->estPris();
}
