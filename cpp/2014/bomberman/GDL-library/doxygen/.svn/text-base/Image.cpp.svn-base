#include <iostream>
#include "Image.hpp"
#include "ImageImpl.hpp"

namespace gdl
{

  Image::Image()
    : Resource<ImageImpl>(NULL)
  {
  }

  Image::Image(ImageImpl* impl)
    : Resource<ImageImpl>(impl)
  {
  }

  Image::~Image()
  {
  }

  Image			Image::load(std::string const & filename)
  {
    return ImageImpl::load(filename);
  }

  void			Image::bind(void)
  {
    this->data_->bind();
  }

  unsigned int		Image::getWidth(void) const
  {
    return this->data_->getWidth();
  }

  unsigned int		Image::getHeight(void) const
  {
    return this->data_->getHeight();
  }

  unsigned char const*	Image::getPixelPtr(void) const
  {
    return this->data_->getPixelPtr();
  }

}
