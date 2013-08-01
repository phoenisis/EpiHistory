#include "deserialisation.h"
#include <iostream>
#include <string>

Objet		*addBox(Objet *cadeau)
{
  Objet		*cart = new Carton;
  Objet		*tmp;
  
  tmp = cadeau;
  while (tmp->getIn())
    {
      tmp = tmp->getIn();
    }
  tmp->setIn(cart);
  return cadeau;
}

Objet		*addPaper(Objet *cadeau)
{
  Objet		*pap = new PapierCadeau();
  Objet		*tmp;
  
  tmp = cadeau;
  if (tmp)
    {
      while (tmp->getIn())
	{
          tmp = tmp->getIn();
	}
      tmp->setIn(pap);
    }
  else
    cadeau = pap;
  return cadeau;
}

Objet		*addPoney(Objet *cadeau, std::string s)
{
  Objet		*poney = new PetitPoney(s);
  Objet		*tmp;

  tmp = cadeau;
  while (tmp->getIn())
    {
      tmp = tmp->getIn();
    }
  tmp->setIn(poney);
  return cadeau;
}

Objet		*addPedobear(Objet *cadeau, std::string s)
{
  Objet		*ours = new Nounours(s);
  Objet		*tmp;

  tmp = cadeau;
  while (tmp->getIn())
    {
      tmp = tmp->getIn();
    }
  tmp->setIn(ours);
  return cadeau;
}

void		pereNoel(char *filename)
{
  std::string	s;
  static int	i = 0;
  std::ifstream infile;
  Objet		*cadeau;
  int		nbBox = 0;
  int		nbPaper = 0;
  int		nbToy = 0;

  cadeau = NULL;
  infile.open(filename);
  if (infile.fail())
    std::cerr << "no such gift" << std::endl;
  while (infile.good())
    {
      getline(infile, s);
      if ((i == 0) && (s != "<papiercadeau>"))
	{
	  std::cerr << "sans papier cadeau autour ce n'est pas un cadeau." << std::endl;
	  return;
	}
      else if (s == "<carton>")
	{
	  cadeau = addBox(cadeau);
	  nbBox++;
	}
      else if (s == "<papiercadeau>")
	{
	  cadeau = addPaper(cadeau);
	  nbPaper++;
	}
      else if (s == "<petitponey>")
	{
	  getline(infile, s);
	  cadeau = addPoney(cadeau, s);
	  nbToy++;
	}
      else if (s == "<nounours>")
	{
	  getline(infile, s);
	  cadeau = addPedobear(cadeau, s);
	  nbToy++;
	}
      else if (s == "</carton>")
	nbBox--;
      else if (s == "</papiercadeau>")
	nbPaper--;
      else if (s == "</petitponey>")
	nbToy--;
      else if (s == "</nounours>")
	nbToy--;
      else
	{
	  std::cerr << "le cadeau est corrompue je ne peut le recreer" 
		    << std::endl;
	  return;
	}
      i = 1;
    }
  infile.close();
  while (cadeau->getIn())
    {
      cadeau = cadeau->getIn();
    }
  std::cout << cadeau->getName() << " dit "; 
  cadeau->estPris();
}

int		main(int ac, char **av)
{
  int	i;

  if (ac <= 2)
    for (i = 1; av[i] != NULL; i++)
      pereNoel(av[i]);
  return (0);
}
