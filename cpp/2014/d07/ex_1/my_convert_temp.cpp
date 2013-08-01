//
// my_convert_temp.cpp for ex_1 in /home/pidoux_q/cu/rendu/cpp/d07/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 10 14:49:25 2011 quentin PIDOUX
// Last update Tue Jan 11 08:24:38 2011 quentin PIDOUX
//

#include <istream>
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
  float temp;
  float result;
  std::string name;

  std::cin >> temp;
  std::cin >> name;

  if (!name.compare("Fahrenheit"))
    {
      result = (( 5.0 / 9.0 * (temp - 32)));
      std::cout << std::setw(16) << std::fixed << std::setprecision(3) 
		<< result << std::setw(16) << "Celsius" << std::endl;
    }
  else if (!name.compare("Celsius"))
    {
       result = (temp * 9 / 5 + 32);
       std::cout << std::setw(16) << std::fixed << std::setprecision(3) 
		 << result << std::setw(16) << "Fahrenheit" << std::endl;
    }
  return (0);
}
