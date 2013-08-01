#include <string>

void    my_put_nbr(long n, std::string &str)
{
  if (n < 0)
    {
      str += '-';
      if (n / -10 != 0)
        my_put_nbr(n / -10, str);
      str += (-(n % 10) + '0');
    }
  else
    {
      if (n / 10 != 0)
        my_put_nbr(n / 10, str);
      str += (n % 10 + '0');
    }
}
