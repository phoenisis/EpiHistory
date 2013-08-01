//
// Warpsystem.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d08m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 11 10:25:14 2011 quentin PIDOUX
// Last update Tue Jan 11 16:38:21 2011 quentin PIDOUX
//

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

WarpSystem::Core::Core()
{
}

QuantumReactor * WarpSystem::Core::checkReactor()
{
  return(this->_coreReactor);
}

WarpSystem::Core::~Core()
{
}

