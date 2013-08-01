#include "ModuleNetwork.hh"
#include <stack>

int		main()
{
  ModuleNetwork<std::stack<int> >	mod;
  std::stack<int>	s;

  s = mod.getinfo("/proc/net/dev");
  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;
  s.pop();
  return 0;
}
