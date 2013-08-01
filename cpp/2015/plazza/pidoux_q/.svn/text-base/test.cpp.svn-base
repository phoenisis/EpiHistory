#include "process.hh"
#include <iostream>
#include <cstdlib>

#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <limits.h>

void	init()
{
  std::ofstream	file;
  std::string pipe="pipe_test";
  std::string word;

  if(mkfifo(pipe.c_str(), 0644) == -1)
    std::cerr << "Cannot creat pipe" << std::endl;
  else
    std::cout << "pipe : " << pipe << " created" << std::endl;
}

std::string reader()
{
  std::string pipe="pipe_test";
  int rd, numread;
  char buffer[PIPE_BUF];
  std::string sentence;

  rd = open(pipe.c_str(), O_RDONLY);
  numread = read(rd, buffer, PIPE_BUF);
  sentence = buffer;
  close(rd);

  return (sentence);
}

bool writter(std::string str)
{
  std::ofstream	file;
  std::string pipe="pipe_test";

  file.open(pipe.c_str(), std::fstream::in | std::fstream::out);

  if (file.write(str.c_str(), str.length()) < 0)
    std::cerr << "Cannot writte into the pipe" << std::endl;
  else
    puts(str.c_str());

  file.close();
}

void remove()
{
  if( remove( "pipe_test" ) != 0 )
    printf("%s\n", "Error deleting file" );
  else
   printf("%s\n", "Pipe successfully deleted" );
}

int	main(int ac, char **av)
{
  //  Process	p(&lol);

  if (ac > 1)
    {
      std::cout << reader() << std::endl;
      remove();
    }
  else
    {
      init();
      writter("j'irai loler sur ta tombe !");
    }

   return 0;
}
