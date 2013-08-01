#include <iostream>
#include "Clock.hpp"
#include "GameClockImpl.hpp"

gdl::Clock::Clock()
  : clock_(gdl::GameClockImpl::getInstance()), isActiv_(false), elapsedTime_(0), savedTime_(clock_.sfClockGlobal.GetElapsedTime()), totalClock_(0)
{
}

gdl::Clock::~Clock()
{
}

void	gdl::Clock::play(void)
{
  this->isActiv_ = true;
  this->savedTime_ = this->clock_.sfClockGlobal.GetElapsedTime();
}

void	gdl::Clock::pause(void)
{
  this->isActiv_ = false;
  reset();
}

void	gdl::Clock::update(void)
{
  if (this->isActiv_ == true)
    {
      float	currentTime = this->clock_.sfClockGlobal.GetElapsedTime();

      this->elapsedTime_ = currentTime - this->savedTime_;
      this->totalClock_ += this->elapsedTime_;
      this->savedTime_ = currentTime; // this->clock_.sfClockGlobal.GetElapsedTime();
    }
}

void	gdl::Clock::reset(void)
{
  this->elapsedTime_ = 0.f;
}

float	gdl::Clock::getElapsedTime(void) const
{
  return (this->elapsedTime_);
}

float	gdl::Clock::getTotalElapsedTime(void) const
{
  return  totalClock_;
}
