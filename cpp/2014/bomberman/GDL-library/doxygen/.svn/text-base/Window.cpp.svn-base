#include "Input.hpp"
#include "Window.hpp"
#include "WindowImpl.hpp"
#include "Assert.hpp"

namespace gdl
{
  Window::Window(void)
    : window_(WindowImpl::getInstance())
  {
    window_.title_ = "Game";
    window_.width_ = 800;
    window_.height_ = 600;
    window_.fullscreen_ = false;

    //    window_.window_.OptimizeForNonOpenGL(true);
  }

  Window::~Window(void) { }

  void		Window::create(void)
  {
    if (this->window_.fullscreen_)
      window_.window_.Create(sf::VideoMode(this->window_.width_, this->window_.height_), this->window_.title_, (sf::Style::Fullscreen|sf::Style::Close|sf::Style::Resize));
    else
      window_.window_.Create(sf::VideoMode(this->window_.width_, this->window_.height_), this->window_.title_);
  }

  void		Window::catchEvent(void)
  {
    sf::Event e;
    while (this->window_.window_.GetEvent(e))
      {
	if (e.Type == sf::Event::Closed)
	  this->close();
      }
  }

  void		Window::display(void)
  {
    this->window_.window_.Display();
  }

  void		Window::close(void)
  {
    this->window_.window_.Close();
  }

  bool		Window::isOpened(void)
  {
    return (this->window_.window_.IsOpened());
  }

  void		Window::setTitle(std::string const &title)
  {
    this->window_.title_ = title;
  }

  void		Window::setWidth(std::size_t const width)
  {
#if DEBUG
    Assert(width > 0, std::string(__PRETTY_FUNCTION__) + " : invalide width");
#endif /* DEBUG */
    if (width > 0)
      this->window_.width_ = width;
    this->window_.window_.SetSize(width, this->window_.height_);
  }

  void		Window::setHeight(std::size_t const height)
  {
#if DEBUG
    Assert(height > 0, std::string(__PRETTY_FUNCTION__) + " : invalide height");
#endif /* DEBUG */
    if (height > 0)
      this->window_.height_ = height;
    this->window_.window_.SetSize(this->window_.width_, height);
  }

  size_t		Window::getWidth()		const
  {
    return this->window_.window_.GetWidth();
  }

  size_t		Window::getHeight()		const
  {
    return this->window_.window_.GetHeight();
  }


  void		Window::setFullscreen(bool const state)
  {
    this->window_.fullscreen_ = state;
  }

  void		Window::setCursorAt(unsigned int const x, unsigned int const y)
  {
    this->window_.window_.SetCursorPosition(x, y);
  }

  void		Window::showCursor(bool const status)
  {
    this->window_.window_.ShowMouseCursor(status);
  }
}
