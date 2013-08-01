/*
**  src/Graph.cpp
**  Bomberman
**
**  Created by Quentin PIDOUX on 30/04/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "../inc/Graph.hh"
#include "../inc/Bomberlib.hh"
#include "../inc/Mygame.hh"
#include "../inc/AObject.hh"
#include <string>
#include <iostream>
#include <cstdlib>

namespace Disp
{
  //MENU

  Menu::Menu()
    : gdl::Game()
  {}

  void Menu::initialize()
  {
    window_.create();
    this->camera_.initialize();
    this->camera_.setpos(0.5f, 25.0f, 0.5f);
    this->camera_.setrot(0.5f, 0.0f, 0.0f);

    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
      (*itb)->initialize();
  }

  Menu::~Menu()
  {}

  void Menu::update()
  {
    if (this->lbl_->MenuDecide == true)
      this->window_.close();

    std::list<AObject*>::iterator itb = this->objects_.begin();

    for (; itb != this->objects_.end(); ++itb)
      (*itb)->update(gameClock_, input_);

    camera_.update(gameClock_, input_);
  }

  void Menu::draw(void)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
    glClearDepth(1.0f);
    std::list<AObject*>::iterator itb = this->objects_.begin();

    for (; itb != this->objects_.end(); ++itb)
      (*itb)->draw();

    this->window_.display();
  }

  void Menu::unload()
  {}

  void Menu::add_object(AObject *obj)
  {
    this->objects_.push_front(obj);
  }

  void Menu::intro()
  {}

  void Menu::close()
  {
    this->window_.close();
  }

  //MENULABEL

  MenuLabel::MenuLabel(int x, int y, int sizeX, int sizeY)
  {
    this->x = x;
    this->y = y;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->MenuCurr = 1;
    this->MenuDecide = false;
  }

  void MenuLabel::initialize(void)
  {
    std::list<AObject*>::iterator itb = this->objects_.begin();

    gdl::Image New_game = gdl::Image::load("./asserts/menu_big_play.png");
    gdl::Image Load = gdl::Image::load("./asserts/menu_big_load.png");
    gdl::Image Save = gdl::Image::load("./asserts/menu_big_save.png");
    gdl::Image Exit = gdl::Image::load("./asserts/menu_big_exit.png");

    this->menu_model[1]=New_game;
    this->menu_model[2]=Load;
    this->menu_model[3]=Save;
    this->menu_model[4]=Exit;

    for (; itb != this->objects_.end(); ++itb)
      (*itb)->initialize();
  }

  void MenuLabel::update(gdl::GameClock const & gameClock, gdl::Input & input_)
  {
    (void)gameClock;
    gdl::Model::Begin();
    glPushMatrix();

    if (this->MenuDecide == false) {
      if (input_.isKeyDown(gdl::Keys::Up) == true){
    	if (this->MenuCurr >= 2){
    	  this->MenuCurr--;
    	  draw();
    	}
	else
	  this->MenuCurr = 4;
      }

      else if (input_.isKeyDown(gdl::Keys::Down) == true){
    	if (this->MenuCurr <= 3){
    	  this->MenuCurr++;
    	  draw();
    	}
	else
	  this->MenuCurr = 1;
      }

      if (input_.isKeyDown(gdl::Keys::Space) == true ||
	  input_.isKeyDown(gdl::Keys::Return) == true)
    	this->MenuDecide = true;
      if (input_.isKeyDown(gdl::Keys::Escape) == true)
    	exit(0);
      glPopMatrix();
    }
    gdl::Model::End();
  }

  void MenuLabel::draw(void)
  {
    gdl::Image texture_ = this->menu_model.find(this->MenuCurr)->second;
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f((float)(this->x+1.8), 000.0f, (float)(this->y-3));
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f((float)(this->x + this->sizeX-0.8), 000.0f, (float)(this->y-3));
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f((float)((this->x + this->sizeX-0.8)), 000.0f, (float)((this->y + this->sizeY+13)));
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f((float)(this->x+2), 000.0f, (float)(this->y + this->sizeY+13));

    glEnd();
  }
}
