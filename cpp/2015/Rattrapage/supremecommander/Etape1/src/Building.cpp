#include "../inc/Building.hh"

Building::Building(const std::string code, const int x, const int y)
 :bonusEnergy(0), BonusMass(0)
{
  setCode(code);
  setPos(x, y);
}

const std::string Building::getName()
{
  return this->_name;
}

const std::string Building::getCode()
{
  return this->_code;
}

const std::pair<int, int> Building::getSize()
{
  return this->_size;
}

const int                 Building::getType()
{
  return this->_type;
}

const int                  Building::getId()
{
  return this->_id;
}

const std::pair<int, int> Building::getPos()
{
  return this->_pos;
}

const int		 Building::getBonus()
{
  return this->_bonus;
}

const std::pair<float, float>   Building::getRessource()
{
  return this->_ressource;
}

const int         Building::getPerimetre()
{
  return this->perimetre;
}

const int         Building::getBonusType()
{
  return this->bonusType;
}

void              Building::setName(const std::string n)
{
  this->_name = n;
}

void              Building::setCode(const std::string n)
{
  this->_code = n;
}

void              Building::setSize(const int x, const int y)
{
  this->_size = std::pair<int, int>(x, y);
}

void              Building::setType(const int i)
{
  this->_type = i;
}

void              Building::setId(const int i)
{
  this->_id = i;
}

void              Building::setPos(const int x, const int y)
{
  this->_pos = std::pair<int, int> (x, y);
}

void              Building::setBonus(const int i)
{
  this->_bonus = i;
}

void              Building::setRessource(const float e, const float m)
{
  this->_ressource = std::pair<float, float> (e, m);
}

void              Building::setBonusEnergy(const int i)
{
  this->bonusEnergy = i;
}

void              Building::setBonusMass(const int i)
{
  this->BonusMass = i;
}

void              Building::setBonusType(const int i)
{
  this->bonusType = i;
}

void              Building::ActionBonus(const int pourcent, const int type, const int occurence)
{
  float Bonus_recu = 0;
  float final = 0;
  float p = static_cast<float>(pourcent);
  float pr = getSize().first*2 + getSize().second*2;
  float oc = static_cast<float>(occurence);

  if (type == 1){
    Bonus_recu = (p/100) * (oc/pr);
    final = this->_ressource.first + this->_ressource.first * Bonus_recu;
    setRessource(final, _ressource.second);
  }
  else if (type == 2){
    Bonus_recu = (p/100) * (oc/pr);
    final = this->_ressource.second+ this->_ressource.second * Bonus_recu;
    setRessource(_ressource.first, final);
  }
}

void              Building::show()
{
  std::cout << getCode()
	    << "(" << getName() << ") "
	    << "pos: "<< getPos().first << "x" << getPos().second << " Energy :"
	    <<_ressource.first << " Mass:" << _ressource.second
	    << std::endl;
}
