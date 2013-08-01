#ifndef _CARACTER_HH_
#define _CARACTER_HH_

#include <string>

class Character
{
protected:
    //caracteristiques 

    std::string name;
    std::string race;
    typedef int AttackRange;
    typedef int AttackClose;
    int Lvl;
    int Pv;
    int Power;
    
    //skill
    
    int Force;
    int Endurance;
    int Intelligence;
    int Esprit;
    int Agilite;
    
public:
  Character(std::string name, int lvl);
  ~Character();

  //info 

  int getPv() const;
  int getPower() const;
  const std::string &getName() const;
  int getLvl() const;

  //Attaque

  int CloseAttack();
  int RangeAttack();

  //Soin

  void Heal();
  void RestorePower();

  //Damages

  void TakeDamage(int _damage);
};

#endif
