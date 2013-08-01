#include "Config.h"

Config::Config(std::string const & filename) {    

    if (doc_.LoadFile(filename.c_str()) != 0){
        std::cerr << "Error in file" << std::endl;
        std::cout << "Generate default profile for server" << std::endl;
        conf_.port_ = 8080;
        conf_.buffSize_ = 512;
        conf_.nbThreads_ = 2;
        conf_.maxClients_ = 256;
        conf_.path_ = ".";
        default_ = true;
    }
    else{
        conf_.port_ = doc_.FirstChildElement("server")->IntAttribute("port");
        conf_.buffSize_ = doc_.FirstChildElement("server")->IntAttribute("buffsize");
        conf_.nbThreads_ = doc_.FirstChildElement("server")->IntAttribute("nbthread");
        conf_.maxClients_ = doc_.FirstChildElement("server")->IntAttribute("clientmax");
        conf_.path_ = doc_.FirstChildElement("server")->Attribute("path");
        default_ = false;
    }
    checkInfoServer();
    retrieveModulesInfos();
    displayServerConf();
}

Config::~Config() {
}

void	Config::retrieveModulesInfos() {
    if (default_ == false){
        t_module				s_element;
        
        for (tinyxml2::XMLElement  *element = doc_.FirstChildElement("modulelist")->FirstChildElement("module"); element; element = element->NextSiblingElement("module"))
        {
            s_element.name_ = std::string(element->Attribute("name"));
            s_element.path_ = std::string(element->Attribute("directory"));
			if (ACCESS(s_element.path_.c_str(), EXISTENCE_MODE) == 0) {
				conf_.modules_.push_back(s_element);
			}
        }
        mod_ = s_element;
    }
}

void    Config::displayServerConf() {
    std::cout << "configuration server :" << std::endl;
    std::cout << "port= " << conf_.port_ << std::endl;
    std::cout << "Buffer= " << conf_.buffSize_ << std::endl;
    std::cout << "nbthread= " << conf_.nbThreads_ << std::endl;
    std::cout << "client max= " << conf_.maxClients_ << std::endl;
	std::cout << "path= " << conf_.path_.c_str() << std::endl;
	std::cout << "Modules:" << std::endl;
	for (std::list<t_module>::iterator it = conf_.modules_.begin(); it != conf_.modules_.end(); ++it)
		std::cout << (*it).name_.c_str() << ": " << (*it).path_.c_str() << std::endl;
}

void    Config::checkInfoServer()
{
    if (conf_.port_ <= 0){
        conf_.port_ = 80;
        std::cerr << "Invalid port, value default value are now used" << std::endl;
    }

    if (conf_.buffSize_ <= 0 || conf_.buffSize_ >= 20000){
        conf_.buffSize_ = 256;
        std::cerr << "Invalid buffsize, value default value are now used" << std::endl;

    }

    if (conf_.nbThreads_ <= 0 || conf_.nbThreads_ > 16){
        conf_.nbThreads_ = 2;
        std::cerr << "Invalid number of thread, value default value are now used" << std::endl;

    }

    if (conf_.maxClients_ <= 0 || conf_.maxClients_ >= 512){
        conf_.maxClients_ = 256;
        std::cerr << "Invalid client capacity, value default value are now used" << std::endl;

    }
}

t_config	Config::getConfig() const {
	return conf_;
}

int			Config::getPort() const {
	return	conf_.port_;
}

int			Config::getBuffSize() const {
	return	conf_.buffSize_;
}

int			Config::getNbThreads() const {
	return	conf_.nbThreads_;
}

int			Config::getMaxClients() const {
	return	conf_.maxClients_;
}

std::string	Config::getPath() const {
	return	conf_.path_;
}

std::list<t_module>	Config::getModules() const {
	return	conf_.modules_;
}