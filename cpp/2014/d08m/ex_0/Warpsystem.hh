/*
** Warpsystem.hh for ex_0 in /home/pidoux_q/rendu/cpp/d08m/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan 11 10:25:38 2011 quentin PIDOUX
// Last update Tue Jan 11 17:05:00 2011 quentin PIDOUX
*/

#ifndef _WARPSYSTEM_HH_
#define _WARPSYSTEM_HH_

namespace WarpSystem
{
  class QuantumReactor
  {
  public:
    QuantumReactor();
    ~QuantumReactor();
    bool isStable();
    void setStability(bool stability);
    bool _stability;

  };
  class Core
  {
  public:
    Core();
    ~Core();
    QuantumReactor * checkReactor();
  private:
    QuantumReactor *_coreReactor;
  };
}

#endif
