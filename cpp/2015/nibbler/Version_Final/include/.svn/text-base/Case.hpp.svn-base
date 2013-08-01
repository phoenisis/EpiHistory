
#ifndef  __CASE_HPP__
# define __CASE_HPP__

enum	NibbleType
  {
    SNAKE_HEAD,
    SNAKE_BODY,
    GRASS,
    FRUIT
  };

class	Case
{
private:
  Case(Case const &);
  Case	&operator=(Case const &);

protected:
  NibbleType	_type;
  unsigned int	_posX;
  unsigned int	_posY;

public:
  Case(NibbleType type, unsigned int posX, unsigned int posY);
  ~Case() {}

  int		getX()		const;
  int		getY()		const;
  NibbleType	getType()	const;

  void			setX(unsigned int x);
  void			setY(unsigned int y);
  void			setType(NibbleType type);
};

#endif /* ! __CASE_HPP__ */
