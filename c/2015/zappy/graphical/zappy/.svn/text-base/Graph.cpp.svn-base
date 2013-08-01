//
//  Graph.cpp
//  zappy
//
//  Created by Quentin PIDOUX on 14/06/12.
//  Copyright (c) 2012 Epitech. All rights reserved.
//

#include "Graph.h"

void                        callAction(void * i)
{
    Graph* thiss = (Graph*) i;

    while (thiss->window.isOpen())
        thiss->doAction(thiss->client->recieveMessage());
}

//               Class Graph

sf::RenderWindow&           Graph::initWindow()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(800, 600), "Zappy Client");
    return *window;
}

sf::View&                   Graph::initView()
{
    sf::View *view = new sf::View;
    view->reset(sf::FloatRect(0, 0, 800, 600));
    return *view;
}

sf::Sprite&                 Graph::initSprite(const std::string str)
{
    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite = new sf::Sprite;
    
    try {
        if (!texture->loadFromFile(resourcePath() + str))
            throw std::invalid_argument("Cannot find Sprite file in the folder.");
    }
    catch (const std::invalid_argument& error){
        std::cout << "std::invalid_argument : " << error.what() << std::endl;
    }
    sprite->setTexture(*texture);
    return *sprite;
}

sf::Font&                   Graph::initFont()
{
    sf::Font *font = new sf::Font;
    
    try {
        if (!font->loadFromFile(resourcePath() + "Pineapple.ttf"))
            throw std::invalid_argument("Cannot find Font file in the folder.");
    }
    catch (const std::invalid_argument& error){
        std::cout << "std::invalid_argument : " << error.what() << std::endl;
    }
    return *font;
}

sf::Music&                  Graph::initMusic(const std::string str)
{
    sf::Music *music =  new sf::Music;
    
    try {
        if (!music->openFromFile(resourcePath() + str))
            throw std::invalid_argument("Cannot find Music file in the folder.");
    }
    catch (const std::invalid_argument& error){
        std::cout << "std::invalid_argument : " << error.what() << std::endl;
    }
    return *music;
}

Graph::Graph()
:   window(initWindow()) ,view(initView()) ,Menu(initSprite("Menu.png")) ,ConnectionLost(initSprite("ConnectionLost.png")) ,NothingFound(initSprite("NothingFound.png")) ,Win(initSprite("Win.png")) ,CommunicationBox(initSprite("CommunicationBox.png")) ,ItemBox(initSprite("ItemBox.png")) ,TimeControl(initSprite("TimeControl.png")) ,Trantorian(initSprite("Trantorian.png")) ,Egg(initSprite("Egg.png")) ,Grass(initSprite("Grass.png")) ,Linemate(initSprite("Linemate.png")),Deraumere(initSprite("Deraumere.png")), Sibur(initSprite("Sibur.png")), Mendiane(initSprite("Mendiane.png")),Phiras(initSprite("Phiras.png")),Thystame(initSprite("Thystame.png")),Food(initSprite("Food.png")) ,Font(initFont()),InfoTrantorianFont(initFont()) ,ConsolFont(initFont()) ,Music(initMusic("nice_music.ogg"))
{
    EndGame = false;
    this->_Menu = true;
    this->_ConnectionLost = false;
    this->_NothingFound = false;
    this->_win = false;
    
    this->FonctionParse["BIE"]=&Graph::welcome;
    this->FonctionParse["msz"]=&Graph::msz;
    this->FonctionParse["bct"]=&Graph::btc;
    this->FonctionParse["tna"]=&Graph::tna;
    this->FonctionParse["pnw"]=&Graph::pnw;
    this->FonctionParse["ppo"]=&Graph::ppo;
    this->FonctionParse["plv"]=&Graph::plv;
    this->FonctionParse["pin"]=&Graph::pin;
    this->FonctionParse["pbc"]=&Graph::pbc;
    this->FonctionParse["pdi"]=&Graph::pdi;
    this->FonctionParse["enw"]=&Graph::enw;
    this->FonctionParse["sgt"]=&Graph::sgt;
    this->FonctionParse["seg"]=&Graph::seg;
    this->FonctionParse["smg"]=&Graph::smg;
}

Graph::~Graph()
{}

const sf::Sprite&           Graph::getMenu()
{
    return this->Menu;
}

const sf::Sprite&           Graph::getConnectionLost()
{
    return this->ConnectionLost;
}

const sf::Sprite&           Graph::getNothingFound()
{
    return this->NothingFound;
}

const sf::Sprite&           Graph::getWin()
{
    return this->Win;
}

const sf::Sprite&           Graph::getCommunicationBox()
{
    return this->CommunicationBox;
}

const sf::Sprite&           Graph::getItemBox()
{
    return this->ItemBox;
}

const sf::Sprite&           Graph::getTimeControl()
{
    return this->TimeControl;
}

const sf::Sprite&           Graph::getTrantorian()
{
    return this->Trantorian;
}

const sf::Sprite&           Graph::getEgg()
{
    return this->Egg;
}

const sf::Sprite&           Graph::getGrass()
{
    return this->Grass;
}

const sf::Sprite&           Graph::getStone(const int choice)
{
    switch (choice) {
        case 1:
            return this->Linemate;
            break;
        case 2:
            return this->Deraumere;
            break;
        case 3:
            return this->Sibur;
            break;
        case 4:
            return this->Mendiane;
            break;
        case 5:
            return this->Phiras;
            break;
        case 6:
            return this->Thystame;
            break;
    }
}

const sf::Sprite&           Graph::getFood()
{
    return this->Food;
}

const sf::Sprite&           Graph::getWhatToDraw(const int i)
{
    switch (i) {
        case 0:
            return this->Food;
            break;
            
        case 1:
            return this->Linemate;
            break;
        case 2:
            return this->Deraumere;
            break;
        case 3:
            return this->Sibur;
            break;
        case 4:
            return this->Mendiane;
            break;
        case 5:
            return this->Phiras;
            break;
        case 6:
            return this->Thystame;
            break;
    }
}

const sf::Font&             Graph::getFont()
{
    return this->Font;
}

const sf::Text              Graph::getTextConsol()
{
    return this->TextConsol;
}

const sf::Text              Graph::getTextTrantorianInfo()
{
    return this->TextTrantorianInfo;
}

const sf::Text              Graph::getTextWinner()
{
    return this->TextWinner;
}

sf::Music&                  Graph::getMusic()
{
    return this->Music;
}

const int                   Graph::getMapSizeX()
{
    return this->MapSize.first;
}

const int                   Graph::getMapSizeY()
{
    return this->MapSize.second;
}

const std::pair<int, int>   Graph::getMousePosition()
{
    return this->MousePosition;
}

const bool                  Graph::getInfoBlockMouse()
{
    
    return true;
}

const std::string           Graph::getTrantorianInfo(const int id)
{
    std::map<int,std::string>::iterator it;
    it = this->TrantorianInfo.find(id);
    return it->second;
}

const bool                  Graph::getEndGame()
{
    return this->EndGame;
}

const bool                  Graph::getMenuBool()
{
    return this->_Menu;
}

const bool                  Graph::getNothingfoundBool()
{
    return this->_NothingFound;
}

const bool                  Graph::getConnectionLostBool()
{
    return this->_ConnectionLost;
}

const bool                  Graph::getWinBool()
{
    return this->_win;
}

const int                   Graph::getNbPlayer()
{
    return this->nbPlayer;
}

void                        Graph::setTextConsol(const std::string text)
{
    this->TextConsol.setString(text);
}

void                        Graph::setPosTextConsol(const int x, const int y)
{
    this->TextConsol.setColor(sf::Color::Black);
    this->TextConsol.setFont(this->Font);
    this->TextConsol.setCharacterSize(22);
    this->TextConsol.setPosition(x, y);
}

void                        Graph::setTextTrantorianInfo(const std::string text)
{
    this->TextTrantorianInfo.setString(text);
}

void                        Graph::setTextWinner(const std::string text)
{
    this->TextWinner.setString(text);
}

void                        Graph::setPosTextTrantorianInfo(const int x, const int y)
{
    this->TextTrantorianInfo.setColor(sf::Color::Black);
    this->TextTrantorianInfo.setFont(this->Font);
    this->TextTrantorianInfo.setCharacterSize(20);
    this->TextTrantorianInfo.setPosition(x, y);
}

void                        Graph::setPosTextWinner(const int x, const int y)
{
    this->TextTrantorianInfo.setColor(sf::Color::Black);
    this->TextTrantorianInfo.setFont(this->Font);
    this->TextTrantorianInfo.setCharacterSize(20);
    this->TextTrantorianInfo.setPosition(x, y);
}

void                        Graph::setMousePosition(const int x, const int y)
{
    this->MousePosition.first = x;
    this->MousePosition.second = y;
}

void                        Graph::setPosCommunicationBox(const int x, const int y)
{
    this->CommunicationBox.setPosition(x, y);
}

void                        Graph::setPosItemBox(const int x, const int y)
{
    this->ItemBox.setPosition(x, y);
}

void                        Graph::setPosTimeControl(const int x, const int y)
{
    this->TimeControl.setPosition(x, y);
}

void                        Graph::setPosTrantorian(const int x, const int y)
{
    this->Trantorian.setPosition(x, y);
}

void                        Graph::setPosEgg(const int x, const int y)
{
    this->Egg.setPosition(x, y);
}

void                        Graph::setPosGrass(const int x, const int y)
{
    this->Grass.setPosition(x, y);
}

void                        Graph::setPosStone(const int choice, const int x, const int y)
{
    switch (choice) {
        case 1:
            this->Linemate.setPosition(x, y);
            break;
        case 2:
            this->Deraumere.setPosition(x, y);
            break;
        case 3:
            this->Sibur.setPosition(x, y);
            break;
        case 4:
            this->Mendiane.setPosition(x, y);
            break;
        case 5:
            this->Phiras.setPosition(x, y);
            break;
        case 6:
            this->Thystame.setPosition(x, y);
            break;
    }
}

void                        Graph::setPoseFood(const int x, const int y)
{
    this->Food.setPosition(x, y);
}

void                        Graph::setTrantorianInfo(const int id, const int nb)
{
    std::stringstream out;
    out << nb;
    std::string text = out.str();
    
    switch (id) {
        case 0:
            this->TrantorianInfo[0] = text;
            break;
        case 1:
            this->TrantorianInfo[1] = text;
            break;
        case 2:
            this->TrantorianInfo[2] = text;
            break;
        case 3:
            this->TrantorianInfo[3] = text;
            break;
        case 4:
            this->TrantorianInfo[4] = text;
            break;
        case 5:
            this->TrantorianInfo[5] = text;
            break;
        case 6:
            this->TrantorianInfo[6] = text;
            break;
        case 7:
            this->TrantorianInfo[7] = text;
            break;
    }
}

void                        Graph::setTrantorianInfo(const int id, const std::string team)
{
    this->TrantorianInfoTeam[id]=team;
}

void                        Graph::setPlayerToList(const int id,const int x, const int y)
{
    std::map<int, std::pair<int, int> >::iterator it;
    std::pair<int, int> tmp = *new std::pair<int, int>(x, y);
    
    this->PlayerList[id] = tmp;
}

void                        Graph::removePlayerList(const int id)
{
    std::map<int, std::pair<int, int> >::iterator it;
    
    it=this->PlayerList.find(id);
    if (it != this->PlayerList.end())
        this->PlayerList.erase(it);
}

void                        Graph::setEggToList(const int id,const int x, const int y)
{
    std::map<int, std::pair<int, int> >::iterator it;
    std::pair<int, int> tmp = *new std::pair<int, int>(x, y);
    
    this->EggList[id] = tmp;
}

void                        Graph::removeEggList(const int id)
{
    std::map<int, std::pair<int, int> >::iterator it;
    
    it=this->EggList.find(id);
    if (it != this->EggList.end())
        this->EggList.erase(it);
}

void                        Graph::setEndGame()
{
    this->_win= true;
}

void                        Graph::setMenuBool(const bool i)
{
    this->_Menu = i;
}

void                        Graph::setNothingFoundBool(const bool i)
{
    this->_NothingFound = i;
}

void                        Graph::setConnectionLostBool(const bool i)
{
    this->_ConnectionLost = i;
}

void                        Graph::setWinBool(const bool i)
{
    this->_win = true;
}

// Client

void                        Graph::initClient(const std::string ip, const std::string port)
{
    this->client = new Client(ip, port);
}

void                        Graph::deleteClient()
{
    delete this->client;
}

void                        Graph::doAction(const std::string text)
{
    std::string command;
    std::string str;
    std::map<std::string,void(Graph::*)(void)>::iterator it;
    
    if (text.length() > 1){
        str.append(text.begin(), text.begin()+3);
    
        it = this->FonctionParse.find(str);
    
        if (it != this->FonctionParse.end()){
            command.append(text.begin()+4, text.end());
            this->Command.clear();
            this->Command = command;
            std::cout << "Fonction : " << str << " est appeler" << std::endl;
            (*this.*it->second)();
        }
    }
}

const int                   Graph::parseToInt()
{
    int nb = 0;
    std::string tmp = this->Command;
    std::string tmp2 = "";
    std::string final = "";
    
    for (int i = 0; tmp[i] != ' '; i++){
        tmp2 += tmp[i];
        nb = std::atoi(tmp2.c_str());
        if (tmp[i+1] == ' ')
            final.append(tmp.begin()+(i+2), tmp.end());
    }
    
    this->Command = final;
    return nb;
}

void                        Graph::welcome()
{
    std::string msg = "GRAPHIC";
    this->client->sendMessage(msg);    
    msg = "Serveur: BIENVENUE";
    
    setTextConsol(msg);
}

void                        Graph::msz()
{   
    int x = parseToInt();
    int y = std::atoi(this->Command.c_str());
    
    std::pair<int, int> pair(x*30, y*30);
    this->MapSize = pair;
}

void                        Graph::btc()
{
    int x = parseToInt()*30;
    int y = parseToInt()*30;
    int tmp = 0;
    
    for (int i = 0; i < 5; i++) {
        tmp = parseToInt();
        
        switch (tmp) {
            case 0:
                this->Food.setPosition(x, y);
                this->window.draw(this->Food);
                break;
            case 1:
                this->Linemate.setPosition(x, y);
                this->window.draw(this->Linemate);
                break;
            case 2:
                this->Deraumere.setPosition(x, y);
                this->window.draw(this->Deraumere);
                break;
            case 3:
                this->Sibur.setPosition(x, y);
                this->window.draw(this->Sibur);
                break;
            case 4:
                this->Mendiane.setPosition(x, y);
                this->window.draw(this->Mendiane);
                break;
            case 5:
                this->Phiras.setPosition(x, y);
                this->window.draw(this->Phiras);
                break;
            case 6:
                this->Thystame.setPosition(x, y);
                this->window.draw(this->Thystame);
                break;
            default:
                break;
        }

    }
}

void                        Graph::tna()
{
    std::string team;
    team.append(this->Command.begin(), this->Command.end()-1);
    
    this->PlayerNameTeam[this->nbTeam]=team;
    this->nbTeam++;
}

void                        Graph::pnw()
{
    int id = parseToInt();
    std::string team;
    
    this->setTrantorianInfo(1, id);
    this->setPlayerToList(id, parseToInt()*30, parseToInt()*30);
    this->setTrantorianInfo(4, parseToInt());
    parseToInt();
    this->setTrantorianInfo(2, parseToInt());
    team.append(this->Command.begin(), this->Command.end()-1);
    this->setTrantorianInfo(id, team);    
}

void                        Graph::ppo()
{
    parseToInt();
    int x = parseToInt()-1;
    int y = parseToInt()-1;
    this->Trantorian.setPosition(x*30, y*30);
    this->window.draw(this->Trantorian);

}

void                        Graph::plv()
{
    int id = parseToInt();
    int lvl = parseToInt();
    std::map<int,int> ::iterator it;
    
    it=this->PlayerLvl.find(id);
    
    if (it == this->PlayerLvl.end())
        this->PlayerLvl[id] = lvl;
    else {
        this->PlayerLvl.erase(it);
        this->PlayerLvl[id] = lvl;
    }
}

void                        Graph::pin()
{
    this->setTrantorianInfo(0, parseToInt());
    parseToInt();
    parseToInt();
    for (int i = 3; i <= 7; i++) {
        this->setTrantorianInfo(i, parseToInt());
    }
}

void                        Graph::pbc()
{
    this->setTextConsol(this->Command);
}

void                        Graph::pdi()
{
//    removePlayerList(parseToInt());
}

void                        Graph::enw()
{
    parseToInt();
    parseToInt();
    this->Egg.setPosition((parseToInt()-1),(std::atoi(this->Command.c_str())-1));
    this->window.draw(Egg);
    
   // setEggToList(id, parseToInt(), parseToInt());
}

void                        Graph::sgt()
{
    std::string msg = "Serveur : System clock at ";
    int time = std::atoi(this->Command.c_str());
    msg += this->Command;
    msg += " .";
    msg += '\n';

    this->Time = time;
    
    std::cout << "SGT DONNNE : "<< this->Command << std::endl;
    setTextConsol(msg);
}

void                        Graph::seg()
{
    std::string msg;
    
    setEndGame();
    msg.append(this->Command.begin(), this->Command.end()-1);
    setTextWinner(msg);
}

void                        Graph::smg()
{
    std::string msg = "Serveur: ";
    
    msg += this->Command;
    msg += '\n';
    setTextConsol(msg);
}

void                        Graph::setMsz()
{
    if (this->client->sendMessage("msz") == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setBtc(const int x, const int y)
{
    std::ostringstream convert;
    std::ostringstream convert2;

    std::string tmp;
    std::string tmp2;
    std::string msg = "bct ";
    
    convert << x;
    convert2 << y;
    
    tmp = convert.str();
    tmp2 = convert2.str();
    
    msg += tmp;
    msg += " ";
    msg += tmp2;
    
    if (this->client->sendMessage(msg) == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setMtc()
{
    if (this->client->sendMessage("mtc") == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setTna()
{
    if (this->client->sendMessage("tna") == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setPpo(const int id)
{
    std::string msg = "ppo ";
    msg += id;
    
    if (this->client->sendMessage(msg) == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setPlv(const int id)
{
    std::string msg = "plv ";
    msg += id;
    
    if (this->client->sendMessage(msg) == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setPin(const int id)
{
    std::string msg = "ppo ";
    msg += id;
    
    if (this->client->sendMessage(msg) == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setSgt()
{
    if (this->client->sendMessage("sgt") == false){
        this->_ConnectionLost = true;
    }
}

void                        Graph::setSst(const int Time)
{
    std::ostringstream convert;
    std::string tmp;
    
    convert << Time;
    tmp = convert.str();
    std::string msg = "sst ";
    msg += tmp;
    std::cout << "Time est de :" << this->Time << std::endl;
    
    std::cout << msg << std::endl;
    
    if (this->client->sendMessage(msg) == false){
        this->_ConnectionLost = true;
    }
}

const int                   Graph::getTime()
{
    return this->Time;
}

const std::pair<int, int>   Graph::getMapSize()
{
    
    return this->MapSize;
}

std::map<int, std::pair<int, int> > Graph::getPlayerList()
{
    return this->PlayerList;
}

std::map<int, std::pair<int, int> > Graph::getEggList()
{
    return this->EggList;
}

std::map<std::pair<int, int>, int>  Graph::getBlocInfo()
{
    return this->blocInfo;
}
