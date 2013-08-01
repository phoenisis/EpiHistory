#include <cstdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#include <list>

typedef struct s_site {
  int               _id;
  std::string       _address;
  std::list<int>    _links;
} t_site;

t_site      parseLine(std::string & line) {
  t_site        data;
  std::string   tmp;

  data._id      = std::atoi(line.c_str());
  tmp           = line.substr(line.find_first_of(';') + 1);
  data._address = tmp.substr(0, tmp.find_first_of(';'));
  tmp           = line.substr(line.find_first_of(';') + 1);
  tmp           = tmp.substr(tmp.find_first_of(';') + 1);
  
  for (;std::atoi(tmp.c_str()) != data._links.back(); tmp = tmp.substr(tmp.find_first_of(';') + 1))
    data._links.push_back(std::atoi(tmp.c_str()));
  
  return data;
}

int         processCalcul(std::list<t_site> listes, int c, int n, int i){

    float first = (c/n) + (1 - c);
    float val1 = 0;
    int count = 0;
    
    for (std::list<t_site>::iterator it = listes.begin(); it != listes.end(); it++) {

        val1 += (1000-1)/it->_links.size();
    }
    
    first = (first * val1);
    
    for (std::list<t_site>::iterator it = listes.begin(); it != listes.end(); it++) {

        std::cout << first << " " << it->_address << std::endl;
    }
    
  return 0;
}

int         main(int ac, char **av){
  if (ac < 4){
    std::cout << "ERROR require <./399pageRank testfile.txt, c, i>" << std::endl;
    exit(EXIT_FAILURE);
  }
  
  else{
    std::string         line;
    std::list<t_site>   listes;
    int                 c = std::atoi(av[2]);
    int                 i = std::atoi(av[3]);
    int                 n = 0;
    
    std::ifstream file(av[1], std::ifstream::in);

    while (!file.eof()){
      std::getline(file, line);
      listes.push_back(parseLine(line));
      ++n;
    }
  
    processCalcul(listes, c, n, i);
  
    file.close();
  }
    
  return 0;
}
