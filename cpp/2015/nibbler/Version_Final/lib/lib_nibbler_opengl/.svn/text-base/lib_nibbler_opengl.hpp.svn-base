
#ifndef  __LIB_NIBBLER_OPENGL_HPP__
# define __LIB_NIBBLER_OPENGL_HPP__

#include "Player.hpp"
#include "IApplication.hpp"

enum	ListPart
  {
    GRASS_PART = 1,
    PREY_PART,
    SNAKE_PART
  };

enum
  {
    MOUSE_SCROLL_DOWN = 3,
    MOUSE_SCROLL_UP
  };

class	OpenGL: public	IApplication
{
private:
  Player	*_player;
  double	eye[3];
  int		_speed;
  direction	_currentDirection;
  size_t	_caseWidth;
  size_t	_caseHeight;
  int		_screenWidth;
  int		_screenHeight;
  float		_mouseX;
  float		_mouseY;
  float		_cameraDistance;
  bool		_mouseRightDN;
  bool		_mouseLeftDN;

  GLuint	_displayList;
  GLuint	_mainWindow;
  GLuint	_scoreWindow;
  double	_zoom;
  double	_zoomMin;
  double	_zoomMax;
  static OpenGL	*_this;

  OpenGL(OpenGL const &);
  OpenGL	&operator=(OpenGL const &);

  void			initCallList();

  void			initMainCamera();
  void			initScoreCamera();

  static void		reshapeFunc(int, int);

  static void		looseScreenDisplay();
  static void		loosingKeyHandler(unsigned char key, int, int);
  static void		looseTimerFunc(int);
  static void		looseMouseFunc(int, int, int, int);
  static void		looseMotionFunc(int, int);
  static void		loosingSpecialKeyHandler(int, int, int);

  void			drawGrass(Case const * const cs) const;
  void			drawPrey(Case const * const cs) const;
  void			drawSnake(Case const * const cs) const;

  static void		mainCameraDisplay();
  static void		specialKeyHandler(int key, int, int);
  static void		keyHandler(unsigned char key, int, int);
  static void		moveAndDelay(int sec);
  static void		mouseFunc(int button, int, int, int);
  static void		mouseMotion(int, int);
  static void		putScore();
  
public:
  OpenGL(int nbCaseWidh, int nbCaseHeight);
  ~OpenGL();

  virtual int           getScrWidth()	const;
  virtual int           getScrHeight()	const;

  virtual size_t        getCaseWidth()  const;
  virtual size_t        getCaseHeight() const;

  virtual void          init(int argc, char **);
  virtual void          display(std::list<toDisplay *> const&);
  virtual void          putOnScreen(Case const * const);

  virtual void          mainLoop(Player *);
  virtual void          endingGame();
};

extern "C"
{
  IApplication* fuckInterface(size_t w, size_t h);
}

#endif /* ! __LIB_NIBBLER_OPENGL_HPP__ */
