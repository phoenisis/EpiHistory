#include <stack>
#include "ModuleOS.hh"
#include "ModuleRam.hh"
#include "ModuleCPU.hh"
#include "ModuleUserName.hh"
#include "ModuleTime.hh"
#include "ModuleNetwork.hh"
#include "IMonitorModule.hh"
#include "Info.hh"

int		main()
{
  Info		info;

  while (42)
    {
      std::cout << info.getOstype() << std::endl;
      std::cout << info.getOsrelease() << std::endl;
      std::cout << info.getHostname() << std::endl;
      std::cout << info.getUsername() << std::endl;
      std::cout << info.getRamfree() << std::endl;
      std::cout << info.getRamtotal() << std::endl;
      std::cout << info.getNbcore() << std::endl;
      std::cout << info.getFrequence() << std::endl;
      std::cout << info.getCoretype() << std::endl;
      std::cout << info.getDate() << std::endl;
      std::cout << info.getHeure() << std::endl;
      std::cout << info.getTransmited() << std::endl;
      std::cout << info.getReceived() << std::endl;
      std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
      sleep(1); 
      info.refresh();
    }
  return (0);
}

  // ModuleOS<std::string> mod;
  // ModuleRam<std::stack<int> > mod2;
  // ModuleCPU<std::stack<std::string> > mod3;
  // ModuleUserName<std::string> mod4;
  // ModuleTime<std::stack<std::string> > mod5;
  // ModuleNetwork<std::stack<long> > mod6;
  // std::stack<int>	ram;
  // std::stack<long>	network;
  // std::stack<std::string>	cpu;
  // std::stack<std::string>	time;
    
  // std::cout << mod.getinfo("/proc/sys/kernel/ostype") << std::endl;
  // std::cout << mod.getinfo("/proc/sys/kernel/osrelease") << std::endl;
  // std::cout << mod.getinfo("/proc/sys/kernel/hostname") << std::endl;
  // std::cout << mod4.getinfo("/proc/self/environ") << std::endl;
  // ram = mod2.getinfo("/proc/meminfo");
  // std::cout << ram.top() << std::endl;
  // ram.pop();
  // std::cout << ram.top() << std::endl;
  // ram.pop();
  // cpu = mod3.getinfo("/proc/cpuinfo");
  // std::cout << cpu.top() << std::endl;
  // cpu.pop();
  // std::cout << cpu.top() << std::endl;
  // cpu.pop();
  // std::cout << cpu.top() << std::endl;
  // cpu.pop();
  // time = mod5.getinfo("/proc/driver/rtc");
  // std::cout << time.top() << std::endl;
  // time.pop();
  // std::cout << time.top() << std::endl;
  // time.pop();
  // network = mod6.getinfo("/proc/net/dev");
  // std::cout << network.top() << std::endl;
  // network.pop();
  // std::cout << network.top() << std::endl;
  // network.pop();
  // return 0;
