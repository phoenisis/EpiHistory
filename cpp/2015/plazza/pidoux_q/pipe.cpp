#include "pipe.hh"

#include <iostream>
#include <fstream>
#include <limits.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

pipe::pipe(const int id)
{
  std::ofstream file;
  this->name = id;

  if(mkfifo(name.c_str(), 0644) == -1)
    std::cerr << "Cannot creat pipe" << std::endl;
  else
    std::cout << "pipe : " << pipe
              << " created" << std::endl;
}


pipe::~pipe()
{
  if( remove( this->name ) != 0 )
    std::cerr << "Error deleting file" << std::endl;
  else
    std::cout << "Pipe successfully deleted"
              << std::endl;
}

const std::string pipe::reader(const int id)
{
  std::string name= id;
  int rd, numread;
  char buffer[PIPE_BUF];
  std::string sentence;

  rd = open(name.c_str(), O_RDONLY);
  numread = read(rd, buffer, PIPE_BUF);
  sentence = buffer;
  close(rd);

  return (sentence);
}

bool writter(const std::string str)
{
  std::ofstream	file;

  file.open(this->name.c_str(), std::fstream::in | std::fstream::out);

  if (file.write(str.c_str(), str.length()) < 0)
    std::cerr << "Cannot writte into the pipe"
              << std::endl;
  else
    puts(str.c_str());

  file.close();
}
