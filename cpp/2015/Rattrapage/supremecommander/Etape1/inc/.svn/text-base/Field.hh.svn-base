//
//  Field.hh
//  commander
//
//  Created by Quentin PIDOUX on 21/07/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#ifndef commander_Field_hh
#define commander_Field_hh

class Field {
public:
    Field(){};
    virtual ~Field(){};
    
    virtual const std::string           getName() = 0;
    virtual const std::string           getCode() = 0;
    virtual const std::pair<int, int>   getSize() = 0;
    virtual const int                   getType() = 0;
    virtual const int                   getId() = 0;
    virtual const std::pair<int, int>   getPos() = 0;
    virtual const int                   getBonus() = 0;
    virtual const std::pair<float, float>   getRessource() = 0;
    
    virtual void setName(const std::string) = 0;
    virtual void setCode(const std::string) = 0;
    virtual void setSize(const int, const int) = 0;
    virtual void setType(const int) = 0;
    virtual void setId(const int) = 0;
    virtual void setPos(const int, const int) = 0;
    virtual void setBonus(const int) = 0;
    virtual void setRessource(const float, const float) = 0;
    
    virtual void ActionBonus(const int, const int, const int) = 0;

    virtual void show() = 0;
    
protected:
    std::string         _name;
    std::string         _code;
    std::pair<int, int> _size;
    int                 _type;
    int                 _id;
    std::pair<int, int> _pos;
    int                 _bonus;
    std::pair<float, float> _ressource;
    
};

#endif
