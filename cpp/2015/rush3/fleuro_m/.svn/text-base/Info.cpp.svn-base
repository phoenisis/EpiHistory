#include "Info.hh"

Info::Info()
{
  ModuleOS<std::string> mod;
  ModuleRam<std::stack<long> > mod2;
  ModuleCPU<std::stack<std::string> > mod3;
  ModuleUserName<std::string> mod4;
  ModuleTime<std::stack<std::string> > mod5;
  ModuleNetwork<std::stack<long> > mod6;
  std::stack<long>	ram;
  std::stack<long>	network;
  std::stack<std::string>	cpu;
  std::stack<std::string>	time;

  this->ostype = mod.getinfo("/proc/sys/kernel/ostype");
  this->osrelease = mod.getinfo("/proc/sys/kernel/osrelease");
  this->hostname = mod.getinfo("/proc/sys/kernel/hostname");
  this->username = mod4.getinfo("/proc/self/environ");
  ram = mod2.getinfo("/proc/meminfo");
  this->ramfree = ram.top();
  ram.pop();
  this->ramtotal = ram.top();
  ram.pop();
  cpu = mod3.getinfo("/proc/cpuinfo");
  this->nbcore = cpu.top();
  cpu.pop();
  this->frequence = cpu.top();
  cpu.pop();
  this->coretype = cpu.top();
  cpu.pop();
  time = mod5.getinfo("/proc/driver/rtc");
  this->date = time.top();
  time.pop();
  this->heure = time.top();
  time.pop();
  network = mod6.getinfo("/proc/net/dev");
  this->old_transmited = network.top();
  this->transmited = 0;
  network.pop();
  this->old_received = network.top();
  this->received = 0;
  network.pop();
}

Info::~Info()
{
}

void		Info::refresh()
{
  ModuleRam<std::stack<long> > mod2;
  ModuleTime<std::stack<std::string> > mod5;
  ModuleNetwork<std::stack<long> > mod6;
  std::stack<long>	ram;
  std::stack<long>	network;
  std::stack<std::string>	time;

  ram = mod2.getinfo("/proc/meminfo");
  this->ramfree = ram.top();
  ram.pop();
  this->ramtotal = ram.top();
  ram.pop();
  time = mod5.getinfo("/proc/driver/rtc");
  this->date = time.top();
  time.pop();
  this->heure = time.top();
  time.pop();
  network = mod6.getinfo("/proc/net/dev");
  this->transmited = network.top() - this->old_transmited;
  this->old_transmited = network.top();
  network.pop();
  this->received = network.top() - this->old_received;
  this->old_received = network.top();
  network.pop();
}

std::string	Info::getOstype() const
{
  return (this->ostype);
}

std::string	Info::getOsrelease() const
{
  return (this->osrelease);
}

std::string	Info::getHostname() const
{
  return (this->hostname);
}

std::string	Info::getUsername() const
{
  return (this->username);
}

long		Info::getRamfree() const
{
  return (this->ramfree);
}

long		Info::getRamtotal() const
{
  return (this->ramtotal);
}

std::string	Info::getNbcore() const
{
  return (this->nbcore);
}

std::string	Info::getFrequence() const
{
  return (this->frequence);
}

std::string	Info::getCoretype() const
{
  return (this->coretype);
}

std::string	Info::getDate() const
{
  return (this->date);
}

std::string	Info::getHeure() const
{
  return (this->heure);
}

long		Info::getTransmited() const
{
  return (this->transmited);
}

long		Info::getReceived() const
{
  return (this->received);
}
