#ifndef _CARACTER_HH_
#define _CARACTER_HH_

#include <string>

class  Character
{
protected:
    //caracteristiques

    std::string name;
    std::string race;
    int  AttackRange();
    int  AttackClose();
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
    explicit Character(const std::string &name, int lvl);
    Character(const Character&);
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
    typedef enum AttackRange
    {
        RANGE,
        CLOSE
    } Range;
    Range Attack;
};

#endif
