//
//  Graph.h
//  zappy
//
//  Created by Quentin PIDOUX on 14/06/12.
//  Copyright (c) 2012 Epitech. All rights reserved.
//

#ifndef zappy_Graph_h
# define zappy_Graph_h
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <sstream>

# include "Client.h"
# include "ResourcePath.hpp"

void                        callAction(void *);

class Graph {
public:
    sf::RenderWindow&   initWindow();
    sf::Rect<int>&      initRect();
    sf::View&           initView();
    sf::Sprite&         initSprite(const std::string);
    sf::Font&           initFont();
    sf::Music&          initMusic(const std::string);
    
    Graph();
    ~Graph();
    const sf::Sprite&           getMenu();
    const sf::Sprite&           getConnectionLost();
    const sf::Sprite&           getNothingFound();
    const sf::Sprite&           getWin();
    const sf::Sprite&           getCommunicationBox();
    const sf::Sprite&           getItemBox();
    const sf::Sprite&           getTimeControl();
    const sf::Sprite&           getTrantorian();
    const sf::Sprite&           getEgg();
    const sf::Sprite&           getGrass();
    const sf::Sprite&           getStone(const int);
    const sf::Sprite&           getFood();
    const sf::Sprite&           getWhatToDraw(const int);
    const sf::Font&             getFont();
    const sf::Text              getTextConsol();
    const sf::Text              getTextTrantorianInfo();
    const sf::Text              getTextWinner();
    sf::Music&                  getMusic();
    sf::RenderWindow&           getWindow();
    const sf::Rect<int>&        getRect();
    const int                   getMapSizeX();
    const int                   getMapSizeY();
    const std::pair<int, int>   getMousePosition();
    const bool                  getInfoBlockMouse();
    const std::string           getTrantorianInfo(const int);
    const bool                  getEndGame();
    const bool                  getMenuBool();
    const bool                  getNothingfoundBool();
    const bool                  getConnectionLostBool();
    const bool                  getWinBool();
    const int                   getNbPlayer();
    
    void                        setTextConsol(const std::string);
    void                        setPosTextConsol(const int, const int);
    void                        setTextTrantorianInfo(const std::string);
    void                        setTextWinner(const std::string);
    void                        setPosTextTrantorianInfo(const int, const int);
    void                        setPosTextWinner(const int, const int);
    void                        setMousePosition(const int, const int);
    void                        setPosCommunicationBox(const int, const int);
    void                        setPosItemBox(const int, const int);
    void                        setPosTimeControl(const int, const int);
    
    void                        setPosTrantorian(const int, const int);
    void                        setPosEgg(const int, const int);
    void                        setPosGrass(const int, const int);
    void                        setPosStone(const int, const int, const int);
    void                        setPoseFood(const int, const int);
    
    void                        setTrantorianInfo(const int, const int);
    void                        setTrantorianInfo(const int, const std::string);
    void                        setPlayerToList(const int, const int, const int);
    void                        setEggToList(const int, const int, const int);
    void                        removePlayerList(const int);
    void                        removeEggList(const int);
    void                        setEndGame();
    void                        setMenuBool(const bool);
    void                        setNothingFoundBool(const bool);
    void                        setConnectionLostBool(const bool);
    void                        setWinBool(const bool);
    
    //recieved message
    
    void                        welcome();
    void                        msz();
    void                        btc();
    void                        tna();
    void                        pnw();
    void                        ppo();
    void                        plv();
    void                        pin();
    void                        pbc();
    void                        pdi();
    void                        enw();
    void                        sgt();
    void                        seg();
    void                        smg();
    
    //Parsing message
    
    void                        initClient(const std::string, const std::string);
    void                        deleteClient();
    void                        doAction(const std::string);
    const int                   parseToInt();
    
    //Send message
    
    void                        setMsz();
    void                        setBtc(const int, const int);
    void                        setMtc();
    void                        setTna();
    void                        setPpo(const int);
    void                        setPlv(const int);
    void                        setPin(const int);
    void                        setSgt();
    void                        setSst(const int);
    
    const int                   getTime();
    const std::pair<int, int>   getMapSize();
    std::map<int, std::pair<int, int> > getPlayerList();
    std::map<int, std::pair<int, int> > getEggList();
    std::map<std::pair<int, int>, int>  getBlocInfo();
    
    Client              *client;
    sf::RenderWindow    &window;
    sf::View            &view;
    
protected:
    std::map<std::pair<int, int>, int>  blocInfo;
    std::map<int, std::pair<int, int> > PlayerList;
    std::map<int, std::pair<int, int> > EggList;
    int                                 nbPlayer;
    
    int                                 nbTeam;
    std::map<int, std::string>          PlayerNameTeam;
    std::map<int, int>                  PlayerLvl;
    
     
private:    
    bool                EndGame;
    std::pair<int, int> MapSize;
    std::pair<int, int> MousePosition;
    
    sf::Sprite          &Menu;
    sf::Sprite          &ConnectionLost;
    sf::Sprite          &NothingFound;
    sf::Sprite          &Win;
    
    sf::Sprite          &CommunicationBox;
    sf::Sprite          &ItemBox;
    sf::Sprite          &TimeControl;
    
    sf::Sprite          &Trantorian;
    sf::Sprite          &Egg;
    
    sf::Sprite          &Grass;
    sf::Sprite          &Linemate;
    sf::Sprite          &Deraumere;
    sf::Sprite          &Sibur;
    sf::Sprite          &Mendiane;
    sf::Sprite          &Phiras;
    sf::Sprite          &Thystame;
    
    sf::Sprite          &Food;
    
    sf::Font            &Font;
    sf::Font            &InfoTrantorianFont;
    sf::Font            &ConsolFont;
    sf::Text            TextConsol;
    sf::Text            TextTrantorianInfo;
    sf::Text            TextWinner;
    
    std::map<int, std::string>  TrantorianInfo;
    std::map<int, std::string>  TrantorianInfoTeam;
    
    sf::Music           &Music;
    
    bool                _Menu;
    bool                _NothingFound;
    bool                _ConnectionLost;
    bool                _win;
    
    int                                             Time;
    std::map<std::string,  void(Graph::*)(void)>    FonctionParse;
    std::string                                     Command;
};

#endif
