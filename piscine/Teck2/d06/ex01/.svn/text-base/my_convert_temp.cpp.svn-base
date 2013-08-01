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
