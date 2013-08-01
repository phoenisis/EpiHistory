#include "Character.hh"
#include "Hunter.hh"
#include <iostream>
#include <string>

Hunter::Hunter(const std::string &name, int lvl) : Character(name, lvl)
{
    this->name = name;
    Character::Lvl = lvl;
    
    Character::Pv = 100;
    Character::Power = 100;
    
    this->weaponName = "sword";
    this->classe = "chasseur";
    this->race = "Elf";
    this->Force = 9;
    this->Endurance = 9;
    this->Intelligence = 5;
    this->Esprit = 6;
    this->Agilite = 24;
    
    std::cout << this->name 
    <<" is born from a tree" 
    << std::endl;
    this->Attack = RANGE;
}

Hunter::~Hunter()
{
}

int Hunter::CloseAttack()
{
    int final;
    final = 20 + this->Force;
    
    if (this->Power >= 30)
    {
        this->Power -= 30;
        std::cout << this->name 
        << " strikes with his "
        << this->weaponName
		<< std::endl;
        return (final);
    }
    else
    {
        std::cout << this->name 
        << " out of power"
		<< std::endl;
        return (0);
    }
}

int Hunter::RangeAttack()
{
    int final = 20 + this->Agilite;
    if (this->Power >= 25)
    {
        this->Power -= 25;
        std::cout << this->name 
        << " uses his bow" 
		<< std::endl;
        return (final);
    }
    else 
    {
        std::cout << this->name 
        << " out of power"
		<< std::endl;
        return (0);
    }
    return 0;
}

void Hunter::Heal()
{
    int i = 0;
    
    while (i < 50 && this->Pv < 100)
    {
        this->Pv += 1;
        i++;
    }
    std::cout << this->name 
    << " takes a potion"
    << std::endl;
}

void Hunter::RestorePower()
{
    int i = 0;
    
    while (i < 100 && this->Power <= 100)
    {
        this->Power += 1 ;
        i++;
    }
    std::cout << this->name 
    << " meditates" 
    << std::endl;
}