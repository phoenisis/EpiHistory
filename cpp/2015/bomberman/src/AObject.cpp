/*
**  src/AObject.cpp
**  Bomberman
**
**  Created by Quentin PIDOUX on 30/04/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include <list>
#include <utility>

#include "../inc/AObject.hh"

void AObject::initialize()
{}

void	AObject::add_positions(Vector3f *position, float rotation)
{
  this->positions.push_back(std::pair<Vector3f*, float>(position, rotation));
}
