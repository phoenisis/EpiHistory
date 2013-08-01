#ifndef _SICKKOALA_H_
#define _SICKKOALA_H_
#include <string>

class SickKoala
{
 public :
  SickKoala(std::string);
  void poke();
  bool takeDrug(std::string med);
  void overDrive(std::string sentence);
  ~SickKoala();

 private:
  std::string name;
 };

#endif
