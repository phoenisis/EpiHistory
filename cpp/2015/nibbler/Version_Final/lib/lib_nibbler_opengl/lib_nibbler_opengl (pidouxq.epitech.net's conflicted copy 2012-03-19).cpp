
#include <GL/glut.h>
#include <iostream>
#include <functional>
#include <sstream>
#include <string>
#include "lib_nibbler_opengl.hpp"
#include "CExceptions.hpp"
#include "Player.hpp"
#include "Case.hpp"

float	cameraAngleX = 0;
float	cameraAngleY = 0;
OpenGL	*OpenGL::_this;

/*
** _CTOR & _DTOR
*/

OpenGL::OpenGL(int nbCaseWidth, int nbCaseHeight)
  :	_caseWidth(1),
	_caseHeight(1)
{
  _this = this;
  this->_currentDirection = RIGHT;
  this->_speed = 70;
  this->_screenWidth = nbCaseWidth * this->_caseWidth;
  this->_screenHeight = nbCaseHeight * this->_caseHeight;
  this->_zoom = _this->_screenHeight / 2.0 + _this->_screenWidth / 2.0;
  this->_zoomMin = this->_zoom / 2.0;
  this->_zoomMax = this->_zoom * 2.0;
}

OpenGL::~OpenGL()
{
  
  delete (_this->_player);
  glutDestroyWindow(this->_scoreWindow);
  glutDestroyWindow(this->_mainWindow);
  glDeleteLists(this->_displayList, 3);
}

/*
** Getter's for screen and case
*/

int           OpenGL::getScrWidth()	const
{
  return (this->_screenWidth);
}

int           OpenGL::getScrHeight()	const
{
  return (this->_screenHeight);
}

size_t        OpenGL::getCaseWidth()  const
{
  return (this->_caseWidth);
}

size_t        OpenGL::getCaseHeight() const
{
  return (this->_caseHeight);
}

// Initialize the display list compiled

void		OpenGL::initCallList()
{
  this->_displayList = glGenLists(3);

  glNewList(PREY_PART, GL_COMPILE); // new proie
  gluSphere(gluNewQuadric(), this->_caseWidth / 2.0, 50 , 50);
  glEndList();

  glNewList(GRASS_PART, GL_COMPILE); // new map
  glBegin(GL_QUADS);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, this->_caseHeight, 0.0);
  glVertex3f(this->_caseWidth, this->_caseHeight, 0.0);
  glVertex3f(this->_caseWidth, 0.0, 0.0);
  glEnd();
  glEndList();

  glNewList(SNAKE_PART, GL_COMPILE); // new snake corp
  glutSolidCube(this->_caseWidth);
  glEndList();
}

/*
** Screen display when you lose
*/

void		OpenGL::looseScreenDisplay()
{
  std::string	output;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glColor3f(1, 1, 1);
  glRasterPos3f(12.50, 25.0, 0);
  output = "GAME OVER";
  for (size_t i = 0 ; i < output.size() ; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, output[i]);

  glRasterPos3f(2.5, 20.0, 0);
  output = "Press SPACE to play again or ESC to quit.";
  for (size_t i = 0 ; i < output.size() ; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, output[i]);
  glutPostRedisplay();
  glFlush();
  glutSwapBuffers();
}

/*
** For reset and replay the game
*/

void		OpenGL::loosingKeyHandler(unsigned char key, int, int)
{
  switch (key)
    {
    case ' ':
      _this->_player->reset();
      _this->_speed = 50;
      _this->_currentDirection = RIGHT;
      glClearColor (1.0, 1.0, 1.0, 0.0);
      glutKeyboardFunc(&OpenGL::keyHandler);
      glutSpecialFunc(&OpenGL::specialKeyHandler);
      glutDisplayFunc(&OpenGL::mainCameraDisplay);
      glutMouseFunc(&OpenGL::mouseFunc);
      glutMotionFunc(&OpenGL::mouseMotion);
      break;
    case 27:
      delete (_this);
      exit(EXIT_SUCCESS);
    default:
      break;
    };
}

void		OpenGL::loosingSpecialKeyHandler(int, int, int)
{
}

void		OpenGL::looseTimerFunc(int)
{
  glutPostRedisplay();
}

/*
** for manage key right left up down and scrolling
*/

void		OpenGL::looseMouseFunc(int, int, int, int)
{
}

/*
** for manage right and left click of the mouse
*/

void		OpenGL::looseMotionFunc(int, int)
{
}

/*
** Initialization of game glut window all init function
*/

void          OpenGL::init(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(800, 600); // size of mainWindow
  glutInitWindowPosition(100, 100);
  this->_mainWindow = glutCreateWindow("nibbler de oufffff"); // fenetre principale
  this->initCallList();
}

/*
** dessine le sol
*/

void		OpenGL::drawGrass(Case const * const cs) const
{  
  glPushMatrix();
  glTranslatef(cs->getX() - 0.5, cs->getY() - 0.5, -0.5);
  glColor3f(0.98, 0.66, 0.32);
  glCallList(GRASS_PART); // appelle l'objet Grass
  glPopMatrix();
}

/*
** dessine le fruit ou la proie
*/

void		OpenGL::drawPrey(Case const * const cs) const
{
  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslatef(cs->getX(), cs->getY(), 0.0);
  glCallList(PREY_PART);
  glPopMatrix();
}

/*
** dessine le serpent
*/

void		OpenGL::drawSnake(Case const * const cs) const
{
  glPushMatrix();
  glTranslatef(cs->getX(), cs->getY(), 0.0);
  if (cs->getType() == SNAKE_HEAD)
    glColor3f(0, 0, 1);
  else
    glColor3f(0, 0.59, 1);
  glCallList(SNAKE_PART);
  glPopMatrix();
}

/*
** affiche le score + level par rapport au score
*/

void		OpenGL::putScore()
{
  std::stringstream	ss(std::ios::out | std::ios::in);
  std::stringstream	ss1(std::ios::out | std::ios::in);
  std::string		score;
  std::string		level;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode (GL_MODELVIEW);

  glColor3f(1.0, 1.0, 1.0);
  ss << _this->_player->getScore();
  ss >> score;
  
  ss1 << _this->_player->getLevel();
  ss1 >> level;
  
  level = "Level ouf : " + level;

  glRasterPos3f(-0.97, -0.10, 0);
  for (size_t i = 0 ; i < level.size() ; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, level[i]);

  score = "Score : " + score;
  glRasterPos3f(0.75, -0.10, 0);
  for (size_t i = 0 ; i < score.size() ; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, score[i]);

  glutPostRedisplay();
  glFlush();
  glutSwapBuffers();
}

/*
** draw all display object
*/

void          OpenGL::display(std::list<toDisplay *> const &data)
{
  std::list<toDisplay *>::const_iterator	it;
  
  for (it = data.begin(); it != data.end(); ++it)
    (*it)->display();
}

/*
** affiche sur l'ecran les objets
*/

void          OpenGL::putOnScreen(Case const * const cs)
{
  switch (cs->getType())
    {
    case SNAKE_HEAD:case SNAKE_BODY:
      this->drawSnake(cs);
      break;
    case FRUIT:
      this->drawPrey(cs);
      break;
    case GRASS:
      this->drawGrass(cs);
      break;
    };
}

/*
** Initialize Camera de batard 
*/

void		OpenGL::initMainCamera()
{
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glMatrixMode(GL_PROJECTION);
  glShadeModel (GL_SMOOTH);
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glLoadIdentity();
  gluPerspective(90.0,180/180, 1, 100);
  //_this->eye[0] = _this->_screenWidth / (_this->_caseWidth * 2);
}

/*
** Gestion de l'affichage de la camera
*/

void		OpenGL::mainCameraDisplay()
{
  double	center[3];
  double	up[3] = {0, 1, 1};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  _this->eye[0] = _this->_screenWidth / (_this->_caseWidth * 2);
  _this->eye[1] = _this->_screenHeight / (_this->_caseHeight * 2) - 10;
  _this->eye[2] = _this->_zoom;

  center[0] = _this->_screenWidth / (_this->_caseWidth * 2);
  center[1] = _this->_screenHeight / (_this->_caseHeight * 2);
  center[2] = 0;
  //up[0] = cameraAngleX; putain l'angle ne marche pas comme on veux
  //up[1] = cameraAngleX; bordel de merde
  //up[2] = cameraAngleX; glTranslate glRotate
  glLoadIdentity();
  gluLookAt(_this->eye[0], _this->eye[1], _this->eye[2],
	    center[0], center[1], center[2],
	    up[0], up[1], up[2]);
  _this->_player->move(_this->_currentDirection);
  _this->_currentDirection = FORWARD;
  
  glFlush();
  glutSwapBuffers();
}

/*
** key escape
*/

void		OpenGL::keyHandler(unsigned char key, int, int)
{
  switch (key)
    {
    case 27:
      delete (_this);
      exit(EXIT_SUCCESS);
    default:
      break;
    };
}

/*
** Gestion des touches
*/

void		OpenGL::specialKeyHandler(int key, int, int)
{
  switch (key)
    {
    case GLUT_KEY_RIGHT:
      if (_this->_player->getDirection() != LEFT)
	_this->_currentDirection = RIGHT;
      break;
    case GLUT_KEY_LEFT:
      if (_this->_player->getDirection() != RIGHT)
	_this->_currentDirection = LEFT;
      break;
    case GLUT_KEY_UP:
      if (_this->_player->getDirection() != UP)
      _this->_currentDirection = DOWN;
      break;
    case GLUT_KEY_DOWN:
      if (_this->_player->getDirection() != DOWN)
      _this->_currentDirection = UP;
      break;
    default:
      break;
    };
}

/*
** Acceleration du snake
*/

void          OpenGL::moveAndDelay(int)
{
  if ((_this->_player->getScore() != 0) &&
      ((_this->_player->getScore() % 25) == 0)
      && (_this->_speed > 50))
    if ((100.0 - _this->_speed) != (_this->_player->getScore() / 5.0))
      {
	_this->_speed -= 5;
	//_this->_player->setLevel(_this->_player->getLevel() + 1);
      }
  glutTimerFunc(_this->_speed, &OpenGL::moveAndDelay, 0);
  glutPostRedisplay();
}

/*
** Gestion du zoom camera Bonus avec le scroll de la souris
*/

void		OpenGL::mouseFunc(int button, int state, int x, int y)
{
  _this->_mouseX = x;
  _this->_mouseY = y;

  switch (button)
    {
    case MOUSE_SCROLL_UP:
      if (_this->_zoom < _this->_zoomMax)
	_this->_zoom += 0.5;
      break;
    case MOUSE_SCROLL_DOWN:
      if (_this->_zoom > _this->_zoomMin)
	_this->_zoom -= 0.5;
      break;
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN)
	_this->_mouseLeftDN = true;
      else
	_this->_mouseLeftDN = false;
      break;
    case GLUT_RIGHT_BUTTON:
      if (state == GLUT_DOWN)
	_this->_mouseRightDN = true;
      else
	_this->_mouseRightDN = false;
      break;
    default:
      break;
    };
}

/*
** gere les touches de la souris change l'angle de la camera non bordel par contre on gere un autre bonus
*/

void	OpenGL::mouseMotion(int x, int y)
{
  if (_this->_mouseLeftDN)
    {
      cameraAngleX += (y - _this->_mouseY);
      cameraAngleY += (x - _this->_mouseX);
      _this->_mouseX = x;
      _this->_mouseY = y;
    }
  if (_this->_mouseRightDN)
    {
      _this->_cameraDistance += (y - _this->_mouseY) * 0.2f;
      _this->_mouseY = y;
    }
  glutPostRedisplay();
}

/*
** MainLoop du Game
*/

void          OpenGL::mainLoop(Player *player)
{
  this->_player = player;
  
  initMainCamera();
  glutKeyboardFunc(&OpenGL::keyHandler);
  glutSpecialFunc(&OpenGL::specialKeyHandler);
  glutDisplayFunc(&OpenGL::mainCameraDisplay);
  glutMouseFunc(&OpenGL::mouseFunc);
  glutMotionFunc(&OpenGL::mouseMotion);

  glutCreateSubWindow(this->_mainWindow, 0, 0, glutGet(GLUT_WINDOW_WIDTH), 20);
  glutDisplayFunc(&OpenGL::putScore);
  glutKeyboardFunc(&OpenGL::keyHandler);
  
  glutTimerFunc(this->_speed, &OpenGL::moveAndDelay, 0);

  glutMainLoop();
}

/*
** Fin du Game
*/

void          OpenGL::endingGame()
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glutDisplayFunc(&OpenGL::looseScreenDisplay);
  glutKeyboardFunc(&OpenGL::loosingKeyHandler);
  glutSpecialFunc(&OpenGL::loosingSpecialKeyHandler);
  glutMouseFunc(&OpenGL::looseMouseFunc);
  glutMotionFunc(&OpenGL::looseMotionFunc);
  glutTimerFunc(this->_speed, &OpenGL::looseTimerFunc, 0);
}

/*
** Pointeur sur interface global
*/

extern "C"
{
  IApplication* fuckInterface(size_t w, size_t h)
  {
    return (new OpenGL(w, h));
  }
}
