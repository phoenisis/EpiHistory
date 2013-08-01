#ifndef _KOADOCTOR_H_
#define  _KOADOCTOR_H_
#include "sickkoala.h"
#include <string>

class KoalaDoctor
{
 private:
  std::string name;
  bool hospital;

 public:
  KoalaDoctor(std::string);
  void diagnose(SickKoala *);
  void timeCheck();
  ~KoalaDoctor();
};

#endif
