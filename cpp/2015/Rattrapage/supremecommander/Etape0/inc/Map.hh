#ifndef commander_Map_hh_
# define commander_Map_hh_
# include <string>
# include <map>
# include <list>

# include "Building.hh"
# include "Ressource.hh"

enum _res{
    BLANK,
    MASS,
    ENGY,
    M1,
    M2,
    M3,
    F2,
    F3,
    P1,
    P2,
    P3,
    HP,
    ES,
    MS
};

class Map
{
public:
    Map();
    Map(const int, const int);
    ~Map(){};
    
    void                                        setSize(const int, const int);
    const std::pair<int, int>                   getMapSize();
    const bool                                  getStatut();
    const bool                                  checkPosDisp(const int, const int, const std::pair<int, int>, const _res,  Field *);

    //Parsing
    
    void      parse(const std::string, const int, const int);
    void      EDP();
    void      MDP();
    void      ME1();
    void      ME2();
    void      ME3();
    void      MF2();
    void      MF3();
    void      PG1();
    void      PG2();
    void      PG3();
    void      HPP();
    void      EST();
    void      MST();
    
    const float getEcoEff();
    const float getPmass();
    const float getPengy();
    const float getCengy();
    const float getTotalEngy();
    
    void        setBonus();
    void        checkRight();
    void        checkLeft();
    void        checkUp();
    void        checkDown();
    
    void        showAll();
    
    
private:
    std::pair<int, int> _size;
    std::map<std::pair<int, int>, Field *> available;
    // true  = libre
    // false = occuper
    
    bool init;
    
    //Parsing
    std::list<Field *> onMap;
    std::map<std::string, void(Map::*)(void) > choice;
    
    int x;
    int y;
    int id;
    
    float Pmass;
    float Pengy;
    float Cengy;
};

#endif