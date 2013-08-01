#ifndef commander_Ressource_hh_
# define commander_Ressource_hh_
# include <string>

# include "Field.hh"

class Ressource : public Field
{
public:
    Ressource(const std::string, const int, const int);
    ~Ressource(){};
    virtual const std::string           getName();
    virtual const std::string           getCode();
    virtual const std::pair<int, int>   getSize();
    virtual const int                   getType();
    virtual const int                   getId();
    virtual const std::pair<int, int>   getPos();
    virtual const int                   getBonus(){return _bonus;};
    virtual const std::pair<float, float>   getRessource(){return _ressource;};
    
    virtual void setName(const std::string);
    virtual void setCode(const std::string);
    virtual void setSize(const int, const int);
    virtual void setType(const int);
    virtual void setId(const int);
    virtual void setPos(const int, const int);
    virtual void ActionBonus(const int, const int, const int){};
    virtual void setBonus(const int){};
    virtual void setRessource(const float, const float){};
    virtual void show(){};
};

#endif
