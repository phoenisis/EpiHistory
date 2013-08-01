#include "koaladoctor.h"
#include "sickkoala.h"
#include <string>

int main()
{
  KoalaDoctor a("House");
  SickKoala b("deadly");

  a.diagnose(&b);
  a.timeCheck();

}
