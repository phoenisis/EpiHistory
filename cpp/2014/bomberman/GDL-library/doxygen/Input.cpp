#include "InputImpl.hpp"
#include "Input.hpp"
#include "WindowImpl.hpp"
#include "Window.hpp"
#include <iostream>

gdl::Input::Input(gdl::Window & window)
  : input_(gdl::InputImpl::getInstance(window))
{
  this->getInput();
}

gdl::Input::~Input()
{
}

bool	gdl::Input::isKeyDown(gdl::Keys::Key key)
{
  return (this->input_.isKeyDown(key));
}

bool	gdl::Input::isMouseButtonDown(gdl::Mouse::Button button)
{
  return (this->input_.isMouseButtonDown(button));
}

void	gdl::Input::getInput()
{
  this->input_.getInput();
}

int	gdl::Input::getMousePositionX(void) const
{
  return (this->input_.getMousePositionX());
}

int	gdl::Input::getMousePositionY(void) const
{
  return (this->input_.getMousePositionY());
}
