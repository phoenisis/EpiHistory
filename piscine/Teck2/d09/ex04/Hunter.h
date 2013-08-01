#ifndef _Hunter_h_
#define _Hunter_h_
#include "Character.hh"

#include <iostream>
#include <string>

class Hunter :public Character
{
private:
    std::string weaponName;
    
public:
    Hunter(std::string &name, int lvl);
    ~Hunter();
    
    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
    
protected:
    //caracteristiques
    bool isClose;
    std::string classe;
};

#endif
