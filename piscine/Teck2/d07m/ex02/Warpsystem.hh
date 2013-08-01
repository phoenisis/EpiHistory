#ifndef _WARPSYSTEM_HH_
#define _WARPSYSTEM_HH_

namespace WarpSystem
{
  class QuantumReactor
  {
  private:
    bool _stability;
  public:
    QuantumReactor();
    ~QuantumReactor();
    bool isStable();
    void setStability(bool);
  };

  class Core
  {
  private:
    WarpSystem::QuantumReactor *_coreReactor;
  public:
    Core(WarpSystem::QuantumReactor *);
    ~Core();
    WarpSystem::QuantumReactor * checkReactor();
  };
}

#endif
