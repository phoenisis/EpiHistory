#include <string.h>
#include "player.hh"

void		player::parse(std::string str)
{
  int		i = 0;
  int		pos1 = 0;
  int		pos2 = 0;
  int		pos3 = 0;
  int		pos4 = 0;
  char		buffer[1024];
  std::string	str2;
  std::string	str3;
  int		y = 0;

  while ((y = str.find('{')) != std::string::npos)
    str.erase(y, 1);
  while ((y = str.find('}')) != std::string::npos)
    str.erase(y, 1);
  str.erase(0, 1);
  while (str.size() > 1 && (this->_toGet.ress.compare("") == 0))
    {
      str2 = "";
      str3 = "";
      if (i != 0)
	pos1 = str.find_first_of(",");
      pos2 = str.find_first_of(",", pos1 + 1);
      if (pos2 == std::string::npos)
	pos2 = str.find_first_of('\n');
      if (pos2 - pos1 < 2 && i != 0)
	str.erase(0, 1);
      else
	{
	  memset(buffer, 0, 1024);
	  str.copy(buffer, pos2 - pos1, pos1);
	  str2 = buffer;
	  while ((y = str2.find(',')) != std::string::npos)
	    str2.erase(y, 1);
	  if (pos2 - pos1 < 12)
	    {
	      while ((y = str2.find(' ')) != std::string::npos)
		str2.erase(y, 1);
	      this->needed(str2, i);
	      std::cout << str << std::endl;
	    }
	  else
	    {
	      while (str2.size() > 0 && (this->_toGet.ress.compare("") == 0))
		{
		  pos3 = 0;
		  pos4 = str2.find_first_of(' ', pos3 + 1);
		  if (pos4 == std::string::npos)
		    pos4 = str2.find_first_of('\n');
		  memset(buffer, 0, 1024);
		  str2.copy(buffer, pos4 - pos3, pos3);
		  str3 = buffer;
		  while ((y = str3.find(' ')) != std::string::npos)
		    str3.erase(y, 1);
		  this->needed(str3, i);
		  str2.erase(0, pos4 - pos3);
		}
	    }
	  str.erase(0, pos2 - pos1);
	}
      i++;
    }
}
