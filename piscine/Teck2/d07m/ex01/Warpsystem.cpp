#include "Warpsystem.hh"
#include <string>
#include <iostream>

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
  return(this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool varia)
{
  this->_stability = varia;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *cor)
{
  this->_coreReactor = cor;
}

WarpSystem::QuantumReactor * WarpSystem::Core::checkReactor()
{
  return(this->_coreReactor);
}

WarpSystem::Core::~Core()
{
}

