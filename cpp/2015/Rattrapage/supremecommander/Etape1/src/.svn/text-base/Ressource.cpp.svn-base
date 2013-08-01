#include "../inc/Ressource.hh"

// class ENERGY

Ressource::Ressource(const std::string code, const int x, const int y)
{
    setCode(code);
    setPos(x, y);
}

const std::string Ressource::getName()
{
    return this->_name;
}

const std::string Ressource::getCode()
{
    return this->_code;
}

const std::pair<int, int> Ressource::getSize()
{
    return this->_size;
}

const int Ressource::getType()
{
    return this->_type;
}

const int Ressource::getId()
{
    return this->_id;
}

const std::pair<int, int> Ressource::getPos()
{
    return this->_pos;
}

void Ressource::setName(const std::string n)
{
    this->_name = n;
}

void Ressource::setCode(const std::string n)
{
    this->_code = n;
}

void Ressource::setSize(const int x, const int y)
{
    this->_size = std::pair<int, int> (x, y);
}

void Ressource::setType(const int i)
{
    this->_type = i;
}

void Ressource::setId(const int i)
{
    this->_id = i;
}

void Ressource::setPos(const int x, const int y)
{
    this->_pos = std::pair<int, int> (x, y);
}
