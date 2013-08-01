#ifndef commander_Building_hh_
# define commander_Building_hh_
# include <string>
# include <map>
# include <iostream>

# include "Field.hh"

class Building : public Field {
public:
    Building(const std::string, const int, const int);
     ~Building(){};
    
    virtual const std::string getName();
    virtual const std::string getCode();
    virtual const std::pair<int, int> getSize();
    virtual const int                 getType();
    virtual const int                 getId();
    virtual const std::pair<int, int> getPos();
    virtual const int                 getBonus();
    virtual const std::pair<float, float> getRessource();

    const int   getPerimetre();
    const int   getBonusType();
    
    virtual void      setName(const std::string);
    virtual void      setCode(const std::string);
    virtual void      setSize(const int, const int);
    virtual void      setType(const int);
    virtual void      setId(const int);
    virtual void      setPos(const int, const int);
    virtual void      setBonus(const int);
    virtual void      setRessource(const float, const float);
    void      setBonusEnergy(const int);
    void      setBonusMass(const int);
    void      setBonusType(const int);
    void      ActionBonus(const int, const int, const int);
    
    virtual void      show();
    
private:
    
    std::map<std::string, void(Building::*)(void) > choice;
    
    int bonusEnergy;
    int BonusMass;
    int perimetre;
    int bonusType;
};

#endif
