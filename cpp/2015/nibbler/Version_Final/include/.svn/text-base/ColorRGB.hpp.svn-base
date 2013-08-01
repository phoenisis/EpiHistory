
#ifndef  __COLOR_RGB_HPP__
# define __COLOR_RGB_HPP__

enum	NibbleColor
  {
    SNAKE_HEAD = 0x000000ff,
    SNAKE_BODY = 0x000099ff,
    GRASS = 0x0000cc00,
    FRUIT = 0x00ff0000
  };

class	ColorRGB
{
private:
  int	_red;
  int	_green;
  int	_blue;

public:
  ColorRGB(int color);
  ~ColorRGB() {}
  ColorRGB(ColorRGB const &rgb);

  ColorRGB	&operator=(ColorRGB const &rgb);
  
  int		getRed()	const;
  int		getGreen()	const;
  int		getBlue()	const;
};

#endif /* ! __COLOR_RGB_HPP__ */
