#include "PapierCadeau.h"

PapierCadeau::PapierCadeau()
{
  this->setType(Objet::PAPIERCADEAU);
}

PapierCadeau::PapierCadeau(const PapierCadeau& other)
{
  this->setIn(other.getIn());
  this->setType(other.getType());
}

PapierCadeau::~PapierCadeau()
{
}

PapierCadeau&	PapierCadeau::operator=(const PapierCadeau& other)
{
  if (this != &other)
    {
      this->setIn(other.getIn());
      this->setType(other.getType());
    }
  return *this;
}

void	PapierCadeau::emballeMoiCa(Objet* aEmballer)
{
  if (!this->_in)
    this->_in = aEmballer;
  else
    std::cout << "Le papier cadeau est deja plein" << std::endl;
}
