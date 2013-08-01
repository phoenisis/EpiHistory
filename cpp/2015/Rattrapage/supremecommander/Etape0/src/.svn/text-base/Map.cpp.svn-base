#include "../inc/Map.hh"

Map::Map()
: init(false), Pmass(0), Pengy(0), Cengy(0), id(0)
{
    this->choice["EDP"]=&Map::EDP;
    this->choice["MDP"]=&Map::MDP;
    this->choice["ME1"]=&Map::ME1;
    this->choice["ME1"]=&Map::ME1;
    this->choice["ME2"]=&Map::ME2;
    this->choice["ME3"]=&Map::ME3;
    this->choice["MF2"]=&Map::MF2;
    this->choice["MF3"]=&Map::MF3;
    this->choice["PG1"]=&Map::PG1;
    this->choice["PG2"]=&Map::PG2;
    this->choice["PG3"]=&Map::PG3;
    this->choice["HPP"]=&Map::HPP;
    this->choice["EST"]=&Map::EST;
    this->choice["MST"]=&Map::MST;
}

Map::Map(const int x, const int y)
:Pmass(0), Pengy(0), Cengy(0), id(0)
{
    setSize(x, y);
    this->choice["EDP"]=&Map::EDP;
    this->choice["MDP"]=&Map::MDP;
    this->choice["ME1"]=&Map::ME1;
    this->choice["ME1"]=&Map::ME1;
    this->choice["ME2"]=&Map::ME2;
    this->choice["ME3"]=&Map::ME3;
    this->choice["MF2"]=&Map::MF2;
    this->choice["MF3"]=&Map::MF3;
    this->choice["PG1"]=&Map::PG1;
    this->choice["PG2"]=&Map::PG2;
    this->choice["PG3"]=&Map::PG3;
    this->choice["HPP"]=&Map::HPP;
    this->choice["EST"]=&Map::EST;
    this->choice["MST"]=&Map::MST;
}

void  Map::setSize(const int x, const int y)
{
    std::pair<int, int> tmp(x, y);

    this->_size = tmp;

    for (int t_x = 0; t_x <= x; ++t_x)
        for (int t_y = 0; t_y <= y ; ++t_y)
            this->available[std::make_pair(t_x, t_y)] = NULL;

    this->init = true;
}

const std::pair<int, int> Map::getMapSize()
{
    return this->_size;
}

const bool Map::getStatut()
{
    return this->init;
}

const bool  Map::checkPosDisp(const int x, const int y, const std::pair<int, int> size, const _res need, Field *type)
{
    std::string find;
    bool needer = false;

    if (need == MASS){
        find = "MDP";
        needer = true;
    }
    else if (need == ENGY){
        find = "EDP";
        needer = true;
    }

    for (int t_x = x; t_x <= (x+size.first -1); ++t_x){
        for (int t_y = y; t_y <= (y+size.second -1); ++t_y) {
            std::map<std::pair<int, int>, Field *>::iterator it = this->available.find(std::make_pair(t_x, t_y));
            if (it != this->available.end()){
                if (needer == true){
                    if ((*it).second != NULL || (*it).second->getCode().compare(find) != 0)
                        return false;
                }
                else{
                    if ((*it).second != NULL)
                        return false;
                }
            }
        }
    }

    for (int t_x = x; t_x <= (x+size.first -1); ++t_x)
        for (int t_y = y; t_y <= (y+size.second -1); ++t_y)
            this->available[std::make_pair(t_x, t_y)]=type;

    return true;
}

// Parsing

void  Map::parse(const std::string code, const int x, const int y)
{
    this->x = x;
    this->y = y;

    std::map<std::string, void(Map::*)(void) >::iterator it = this->choice.find(code);
    if (it != this->choice.end())
        (*this.*it->second)();

    else
        std::cerr << "Unknow Building" << std::endl;
}

void              Map::EDP()
{
    Ressource *R = new Ressource("EDP", this->x, this->y);
    if (checkPosDisp(this->x, this->y, std::pair<int, int>(3, 3), BLANK, R) == true && init == true){
        R->setSize(3, 3);
        R->setName("Energy deposit");
        R->setType(ENGY);
        R->setId(++this->id);

        this->onMap.push_front(R);
    }
    else
        delete R;
}

void              Map::MDP()
{
    Ressource *R = new Ressource("MDP", this->x, this->y);
    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), BLANK, R) == true && init == true){
        R->setSize(1, 1);
        R->setName("Mass deposit");
        R->setType(MASS);
        R->setId(++this->id);

        this->onMap.push_front(R);
    }
}

void              Map::ME1()
{
    Building *B = new Building("ME1", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), MASS, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Mass Extractor T1");
        B->setRessource(-2, 2);
        B->setBonus(-40);
        B->setBonusType(1);
        B->setType(M1);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);
        this->Cengy += -2;
        this->Pmass += 2;
    }
}

void              Map::ME2()
{
    Building *B = new Building("ME2", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), MASS, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Mass Extractor T2");
        B->setRessource(-9, 6);
        B->setBonus(-60);
        B->setBonusType(1);
        B->setType(M2);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);
        this->Cengy += -9;
        this->Pmass += 6;
    }
}

void              Map::ME3()
{
    Building *B = new Building("ME3", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), MASS, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Mass Extractor T3");
        B->setRessource(-54, 18);
        B->setBonus(-80);
        B->setBonusType(1);
        B->setType(M3);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);
        this->Cengy += -54;
        this->Pmass += 18;
    }
}

void              Map::MF2()
{
    Building *B = new Building("MF2", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), BLANK, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Mass Fabricator T2");
        B->setRessource(-150, 1);
        B->setBonus(-10);
        B->setBonusType(1);
        B->setType(F2);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);

        this->Cengy += -150;
        this->Pmass += 1;
    }
}

void              Map::MF3()
{
    Building *B = new Building("MF3", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(3, 3), BLANK, B) == true && init == true){
        B->setSize(3, 3);
        B->setName("Mass Fabricator T3");
        B->setRessource(-3500, 12);
        B->setBonus(-40);
        B->setBonusType(1);
        B->setType(F3);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);

        this->Cengy += -3500;
        this->Pmass += 12;
    }
}

void              Map::PG1()
{
    Building *B = new Building("PG1", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), BLANK, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Power Generator T1");
        B->setRessource(20, 0);
        B->setBonus(-25);
        B->setBonusType(2);
        B->setType(P1);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);

        this->Pengy += 20;
    }
}

void              Map::PG2()
{
    Building *B = new Building("PG2", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(3, 3), BLANK, B) == true && init == true){
        B->setSize(3, 3);
        B->setName("Power Generator T2");
        B->setRessource(500, 0);
        B->setBonus(-50);
        B->setBonusType(2);
        B->setType(P2);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);

        this->Pengy += 500;
    }
}

void              Map::PG3()
{
    Building *B = new Building("PG3", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(4, 4), BLANK, B) == true && init == true){
        B->setSize(4, 4);
        B->setName("Power Generator T3");
        B->setRessource(2500, 0);
        B->setBonus(-75);
        B->setBonusType(2);
        B->setType(P3);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);

        this->Pengy += 2500;
    }
}

void              Map::HPP()
{
    Building *B = new Building("HPP", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(3, 3), ENGY, B) == true && init == true){
        B->setSize(3, 3);
        B->setName("HC Power Plant");
        B->setRessource(100, 0);
        B->setBonus(-50);
        B->setBonusType(2);
        B->setType(HP);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);

        this->Pengy += 100;
    }
}

void              Map::EST()
{
    Building *B = new Building("EST", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), BLANK, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Energy Storage");
        B->setBonus(50);
        B->setBonusType(2);
        B->setType(ES);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);
    }
}

void              Map::MST()
{
    Building *B = new Building("HPP", this->x, this->y);

    if (checkPosDisp(this->x, this->y, std::pair<int, int>(1, 1), BLANK, B) == true && init == true){
        B->setSize(1, 1);
        B->setName("Mass Storage");
        B->setBonus(50);
        B->setBonusType(1);
        B->setType(MS);
        B->setId(++this->id);
        B->show();

        this->onMap.push_front(B);
    }
}

const float     Map::getEcoEff()
{
    return ((this->Pmass/this->Cengy)*(this->Pengy - this->Cengy)+this->Pmass);
}

const float     Map::getPmass()
{
    this->Pmass = 0;

    for(std::list<Field*>::iterator it = this->onMap.begin(); it != this->onMap.end(); ++it)
       this->Pmass += (*it)->getRessource().second;

    return this->Pmass;
}

const float     Map::getPengy()
{
    this->Pengy = 0;

    for(std::list<Field*>::iterator it = this->onMap.begin(); it != this->onMap.end(); ++it)
        if ((*it)->getRessource().first > 0)
            this->Pengy += (*it)->getRessource().first;

    return this->Pengy;
}

const float     Map::getCengy()
{
    this->Cengy = 0;

    for(std::list<Field*>::iterator it = this->onMap.begin(); it != this->onMap.end(); ++it)
        if ((*it)->getRessource().first < 0)
            this->Cengy += (*it)->getRessource().first;

    return this->Cengy;
}

const float     Map::getTotalEngy()
{
    return (this->Pengy - this->Cengy);
}

void            Map::setBonus()
{
    int x, y = 0;
    int s_x, s_y = 0;

    int id;
    int size;
    int occurence = 0;
    int pourcent = 0;
    int type = 0;

    for (std::list<Field *>::iterator it= this->onMap.begin(); it != this->onMap.end(); ++it) {
        x = (*it)->getPos().first;
        y = (*it)->getPos().second;
        s_x = (*it)->getSize().first;
        s_y = (*it)->getSize().second;
        type = (*it)->getType();
        pourcent = (*it)->getBonus();

        // Droite
        occurence = 0;
        if (x + s_x +1 < _size.first){
            for (int i = y; i != y + s_y ; i++) {
                std::map<std::pair<int, int>, Field *>::iterator it = this->available.find(std::make_pair(x+s_x+1, i));
                if ((*it).second != NULL && (*it).second->getType() < ES){
                    size = (*it).second->getSize().first;
                        id = (*it).second->getId();

                    if (occurence == size){
                        std::cout << "Droite" << std::endl;
                        (*it).second->ActionBonus(pourcent, type, occurence);
                        break;
                    }
                }
            }
        }

        //Gauche
        occurence = 0;
        if (x -1 >= 0){
            for (int i = y; i != y + s_y; i++) {
                std::map<std::pair<int, int>, Field *>::iterator it = this->available.find(std::make_pair(x-1, i));
                if ((*it).second != NULL && (*it).second->getType() < ES){
                    size = (*it).second->getSize().first;
                    id = (*it).second->getId();
                    if (occurence == size){
                        std::cout << "Gauche" << std::endl;
                        (*it).second->ActionBonus(pourcent, type, occurence);
                        break;
                    }
                }
            }
        }

        //Haut
        occurence = 0;
        if (y -1 > 0){
            for (int i = x; i != x + s_x; ++i) {
                std::map<std::pair<int, int>, Field *>::iterator it = this->available.find(std::make_pair(i, y-1));
                if ((*it).second != NULL && (*it).second->getType() < ES){
                    size = (*it).second->getSize().first;
                    id = (*it).second->getId();
                    if (occurence == size){
                        std::cout << "Haut" << std::endl;
                        (*it).second->ActionBonus(pourcent, type, occurence);
                        break;
                    }
                }
            }
        }

        //Bas

    }
}
